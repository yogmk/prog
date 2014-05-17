# ident "A demo program which removes a semaphore."

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/sem.h>

union semun
 {
 int val;
 struct semid_ds *buf;
 ushort *array;
 };

int main (void)
 {
 key_t key;
 int semid;
 union semun arg;

 /*
 *  Generate the key to access semaphore 
 */

 if ((key = ftok("seminit.c", 'J')) == -1)
  {
  perror("ftok");
  exit (EXIT_FAILURE);
  }

 /*
 * We have the key, now grab the semaphore
 */

 if ((semid = semget(key, 1, 0)) == -1)
  {
  perror("semget");
  exit (EXIT_FAILURE);
  }
 
 /*
 * After grabbing the semaphore, we'll remove it
 */

 if (semctl (semid, 0, IPC_RMID, arg) == -1)
  {
  perror("semctl");
  exit (EXIT_FAILURE);
  }

 return 0;
  
 }
