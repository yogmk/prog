# ident "Demo of shared memory woth semaphores"

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <wait.h>
# include <time.h>
# include <string.h>
# include <sys/types.h>
# include <sys/sem.h>
# include <sys/shm.h>

# define SHM_ID 250
# define SEM_ID 100


union semun
 {
  int val;               /* used for SETVAL only */
  struct semid_ds *byf;  /* used for IPC_STAT & IPC_SET */
  ushort *array;         /* for GETALL & SETALL */
 };

struct
country
 {
 char name [30];
 char capital [30];
 char currency[30];
 int population;
 };

/*
 * function: random_delay. delay the executing process for a random number
 *           of nano-seconds.
 * input:    none.
 * output:   none.
 */
void
random_delay()
{
    static int initialized = 0;
    int random_num;
    struct timespec delay;            /* used for wasting time. */

    if (!initialized) {
	srand(time(NULL));
	initialized = 1;
    }

    random_num = rand() % 10;
    delay.tv_sec = 0;
    delay.tv_nsec = 10*random_num;
    nanosleep(&delay, NULL);
}

/*
 * function: sem_lock. locks the semaphore, for exclusive access to a resource.
 * input:    semaphore set ID.
 * output:   none.
 */
void
sem_lock(int sem_set_id)
{
    /* structure for semaphore operations.   */
    struct sembuf sem_op;

    /* wait on the semaphore, unless it's value is non-negative. */
    sem_op.sem_num = 0;
    sem_op.sem_op = -1;
    sem_op.sem_flg = 0;
    semop(sem_set_id, &sem_op, 1);
}

/*
 * function: sem_unlock. un-locks the semaphore.
 * input:    semaphore set ID.
 * output:   none.
 */
void
sem_unlock(int sem_set_id)
{
    /* structure for semaphore operations.   */
    struct sembuf sem_op;

    /* signal the semaphore - increase its value by one. */
    sem_op.sem_num = 0;
    sem_op.sem_op = 1;   /* <-- Comment 3 */
    sem_op.sem_flg = 0;
    semop(sem_set_id, &sem_op, 1);
}

/*
 * function: add_country. adds a new country to the counties array in the
 *           shard memory segment. Handles locking using a semaphore.
 * input:    semaphore id, pointer to countries counter, pointer to
 *           counties array, data to fill into country.
 * output:   none.
 */
void
add_country(int sem_set_id, int* countries_num, struct country* countries,
	    char* country_name, char* capital_city, char* currency,
	    int population)
{
    sem_lock(sem_set_id);
    strcpy(countries[*countries_num].name, country_name);
    strcpy(countries[*countries_num].capital, capital_city);
    strcpy(countries[*countries_num].currency, currency);
    countries[*countries_num].population = population;
    (*countries_num)++;
    sem_unlock(sem_set_id);
}

/*
 * function: do_child. runs the child process's code, for populating
 *           the shared memory segment with data.
 * input:    semaphore id, pointer to countries counter, pointer to
 *           counties array.
 * output:   none.
 */
void
do_child(int sem_set_id, int* countries_num, struct country* counties)
{
    add_country(sem_set_id, countries_num, counties,
		"U.S.A", "Washington", "U.S. Dollar", 250000000);
    random_delay();
    add_country(sem_set_id, countries_num, counties,
		"Israel", "Jerusalem", "New Israeli Shekel", 6000000);
    random_delay();
    add_country(sem_set_id, countries_num, counties,
		"France", "Paris", "Frank", 60000000);
    random_delay();
    add_country(sem_set_id, countries_num, counties,
		"Great Britain", "London", "Pound", 55000000);
}

/*
 * function: do_parent. runs the parent process's code, for reading and
 *           printing the contents of the 'countries' array in the shared
 *           memory segment.
 * input:    semaphore id, pointer to countries counter, pointer to
 *           counties array.
 * output:   printout of countries array contents.
 */
void
do_parent(int sem_set_id, int* countries_num, struct country* countries)
{
    int i, num_loops;

    for (num_loops=0; num_loops < 5; num_loops++) {
        /* now, print out the countries data. */
        sem_lock(sem_set_id);
        printf("---------------------------------------------------\n");
        printf("Number Of Countries: %d\n", *countries_num);
        for (i=0; i < (*countries_num); i++) {
            printf("Country %d:\n", i+1);
            printf("  name: %s:\n", countries[i].name);
            printf("  capital city: %s:\n", countries[i].capital);
            printf("  currency: %s:\n", countries[i].currency);
            printf("  population: %d:\n", countries[i].population);
        }
        sem_unlock(sem_set_id);
	random_delay();
    }
}


int 
main (int argc, char* argv[])
 {
 int shmid, semid;
 int retval, i;
 pid_t pid;
 char* shm_addr;
 struct shmid_ds shmds;
 union semun arg;

 int* country_count;
 struct country* country_array;

 /*
  * Create a semaphore set with 1 semaphore
 */
 if((semid = semget(SEM_ID, 1, IPC_CREAT | 0600)) == -1)
  {
  perror("semget");
  exit (EXIT_FAILURE);
  }

 /*
  * initialise the semaphore with '1'
 */
 arg.val = 1;
 if (semctl(semid, 0, SETVAL, arg) == -1)
  {
  perror("semctl");
  exit (EXIT_FAILURE);
  }

 /*
  * Allocate a shared memory segment
 */
 if ((shmid = shmget(SHM_ID, 2048, IPC_CREAT | IPC_EXCL | 0600)) == -1)
  {
  perror("shmget");
  exit (EXIT_FAILURE);
  }
 
 /*
  * attach the shared memory segment to our process
 */
 if(!(shm_addr = shmat(shmid, NULL, 0)))
  {
  perror("shmat");
  exit (EXIT_FAILURE);
  }
 
 /*
  * in  first 'sizeof(int)' buyes, we'll stro the count
  * in rest, we'll store actual data
  * so point pointers to appro. location.
 */
 country_count= (int*)shm_addr;
 *country_count = 0;

 country_array = (struct country*)(shm_addr + sizeof(int));

 /*
  * fork a child to split the task
 */
 pid = fork();
 switch (pid)
  {
  case -1 :
          {
		  perror("fork");
		  exit (EXIT_FAILURE);
		  }
  case 0 :
         /*
		  * This is child
		 */
		 {
		 do_child (semid, country_count, country_array);
		 exit (EXIT_SUCCESS);
		 break;
		 }
  default:
         {
		 do_parent (semid, country_count, country_array);
		 break;
		 }
  }

 /*
  * wait for child to exit
 */
  wait(&retval);

 /*
  * Detach teh shared memory segment
  * de-allocate as well.
 */

 if (shmdt(shm_addr) == -1)
  {
  perror("shmdt");
  exit (EXIT_FAILURE);
  }
 if (shmctl(shmid, IPC_RMID, &shmds) == -1)
  {
  perror("shmctl");
  exit (EXIT_FAILURE);
  }
 return 0;
 }
