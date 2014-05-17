# ident "A sample prog to demo the initialisation of semaphores"

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/sem.h>

union semun
 {
 int val; 				/* used for SETVAL only */
 struct semid_ds *byf;	/* used for IPC_STAT & IPC_SET */
 ushort *array; 		/* for GETALL & SETALL */
 };


int main(void)
 {
 key_t key;
 int semid;
 union semun arg;

 /*
 * generate the key
 */

 if ((key = ftok("seminit.c", 'J')) == -1)
  {
  perror("ftok");
  exit (EXIT_FAILURE);
  }

 /*
 * create a set of semaphores with 1 semaphore
 */

 if ((semid = semget(key, 1, 0666 | IPC_CREAT)) == -1)
  {
  perror("semget");
  exit (EXIT_FAILURE);
  }

 /*
 * initialise semaphore #0 to 1.
 */

 arg.val = 1;
 if (semctl (semid, 0, SETVAL, arg) == -1)
  {
  perror("semctl");
  exit(EXIT_FAILURE);
  }

 return 0;
 }
