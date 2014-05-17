# ident "a sample program to demo the operations on a semaphore." 

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>

# include <sys/types.h>
# include <sys/sem.h>
# include <sys/ipc.h>

int main (void)
 {
 key_t key;
 int semid;
 struct sembuf sb = {0, -1, 0};

 /*
 *  Get the key
 */

 if ((key = ftok("seminit.c", 'J')) == -1)
  {
  perror("ftok");
  exit (EXIT_FAILURE);
  }
 
 /*
 *  Grab the semaphore
 */

 if ((semid = semget(key, 1, 0)) == -1)
  {
  perror("semget");
  exit (EXIT_FAILURE);
  }

 puts("\nPress a key to lock:");
 getchar();
 puts("Trying to acquire lock...\n");

 if (semop(semid, &sb, 1) == -1)
  {
  perror("semop");
  exit (EXIT_FAILURE);
  }

 puts ("Locked!\nPress return to unlock..");
 getchar ();

 sb.sem_op = 1;		/* mark resource for release */

 if (semop(semid, &sb, 1) == -1)
  {
  perror("semop");
  exit (EXIT_FAILURE);
  }

 puts ("unlocked.");
 return 0;
 }
