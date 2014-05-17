# ident "A demo showing producer-consumer synchronisation using semaphore."


# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <time.h>

# include <sys/wait.h>
# include <sys/ipc.h>
# include <sys/types.h>
# include <sys/sem.h>

union semun
 {
  int val;               /* used for SETVAL only */
  struct semid_ds *byf;  /* used for IPC_STAT & IPC_SET */
  ushort *array;         /* for GETALL & SETALL */
 };

int 
main (int argc, char** argv)
 {
 union semun arg;					/* for semctl() 			*/
 int semid, child_pid, retval, i;		
 struct timespec delay;				/* used for wasting time 	*/
 struct sembuf sb;					/* has data for semop()  	*/
 
 /*
  * create a private semaphore set 
  * having only 1 semaphore
  * and access only to owner
 */
 
 if ((semid = semget (IPC_PRIVATE, 1, 0600)) == -1)
  {
  perror("semget");
  exit (EXIT_FAILURE);
  }
 printf ("\nsemaphore set created, id=%d\n", semid); 

 /*
  * Initialise first (& only) semaphore
  * in our set to '0'
 */
 
  arg.val = 0;
  if ((retval = semctl(semid, 0, SETVAL, arg)) == -1)
   {
   perror("semctl");
   exit (EXIT_FAILURE);
   }
 
 /*
  * fork off a child process to start
  * producer-consumer job
  * parent is producer, child is consumer
 */

  child_pid = fork();

  switch (child_pid)
   {
   case -1:
	       perror("fork");
		   exit (EXIT_FAILURE);
   case 0: 					
	      /* 
		   * control is in child process
		   * start consumer loop
		  */
		  for (i=0; i<20; i++)
		   {
           /* WAIT on the semaphore, unless its value is positive */
		   sb.sem_num = 0;
		   sb.sem_op = -1;
		   sb.sem_flg = 0;

		   semop(semid, &sb, 1);
		   printf("consumer: '%d'\n", i);
		   fflush (stdout);
		   }
          exit (EXIT_SUCCESS);
   default: 					
	      /* 
		   * control is in parent 
		   * start producer loop
		  */

		  for (i=0; i<20; i++)
		   {
		   printf("producer: '%d'\n", i);
		   fflush (stdout);

           /* SIGNAL the semaphore, increase its value by 1 */
		   sb.sem_num = 0;
		   sb.sem_op = 1;
		   sb.sem_flg = 0;

		   semop(semid, &sb, 1);
		   /*
		    * pause execution for a little bit
			* to allow consumer to fetch requests
		   */
		   if (rand() > 3*(RAND_MAX/4))
		    {
			delay.tv_sec = 1;
			delay.tv_nsec = 10;
			nanosleep (&delay, NULL);
			}
		   }
	      break;
   }
   return 0;
 }
