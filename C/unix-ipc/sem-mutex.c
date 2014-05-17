# ident "Demo of using semaphore as a mutex syncing access to a file by multiple processes."

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <time.h>

# include <sys/wait.h>
# include <sys/ipc.h>
# include <sys/types.h>
# include <sys/sem.h>

# define NUM_PROCS 	5
# define SEM_ID    	0xabcd
# define FILE_NAME	"/tmp/sem-mutex"
# define DELAY 		4000000


void
update_file (int semid, char* file_path, int data)
 {
 struct sembuf sb;
 FILE* stream;

 /*
 * populate sembuf, 
 * WAIT on the semaphore unless the value
 * is non-negative
 */
 sb.sem_num = 0;
 sb.sem_op = -1;
 sb.sem_flg = 0;

 semop(semid, &sb, 1);

 /*
 * We locked the semaphore, and assured of 
 * exclusive access. Write some data into the file.
 */

 stream = fopen (FILE_NAME, "a");
 if (stream)
  {
  fprintf (stream, "pid %d locked the semaphore resource.\n", data);
  printf ("pid %d locked the semaphore resource.\n", data);
  fclose(stream);
  }
 
 /*
 * We're done.
 * SIGNAL the semaphore - increase the value by one
 */

 sb.sem_num = 0;
 sb.sem_op = 1;
 sb.sem_flg = 0;

 semop(semid, &sb, 1);
 }


 /*
  * Function calling file_update in a loop.
  * called by child processes
 */

void
child_loop(int semid, char* file_name)
 {
 pid_t pid = getpid();
 int i, j;

 for (i = 0; i <=3; i++)
  {
  update_file(semid, file_name, pid);
  for (j=0; j < DELAY; j++)
   ;  /* do nothing for a while */
   //sleep(10) ;
  }
 }

union semun
 {
  int val;               /* used for SETVAL only */
  struct semid_ds *byf;  /* used for IPC_STAT & IPC_SET */
  ushort *array;         /* for GETALL & SETALL */
 };

int 
main (void)
 {
 union semun arg;				/* for semctl() */
 int semid, child_pid, retval, i, child_status;		
 
 /*
  * create a semaphore set with ID 250
  * having only 1 semaphore
  * and access only to owner
 */
 
 if ((semid = semget (SEM_ID, 1, IPC_CREAT | 0600)) == -1)
  {
  perror("semget");
  exit (EXIT_FAILURE);
  }
 
 /*
  * Initialise first (& only) semaphore
  * in our set to '1'
 */
 
  arg.val = 1;
  if ((retval = semctl(semid, 0, SETVAL, arg)) == -1)
   {
   perror("semctl");
   exit (EXIT_FAILURE);
   }
 
 /*
  * create a bunch of child processes
  * that will compete on the semaphore resource
 */

  for (i=0; i <NUM_PROCS; i++)
   {
   child_pid = fork();

   switch (child_pid)
    {
	case -1:
	       perror("fork");
		   exit (EXIT_FAILURE);
    case 0: 					/* control is in child process */
	      child_loop(semid, FILE_NAME);
          exit (EXIT_SUCCESS);
	default: 					/* control is in parent */
	      break;
	}
   }

  /*
   * wait for all children to exit
  */
   
   for (i=0; i < NUM_PROCS; i++)
    {
	wait(&child_status);
	}
   puts ("main: we're done!");
   fflush(stdout);
 }
