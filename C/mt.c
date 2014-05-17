/**
 * a sample Multi-Process-Multi-Threaded program
 * 
 * -fork() a process
 * -exit() from parent, so child is adopted by init (1)
 * -The child now becomes the 'root' process daemon
 * -root spawns many (3) child processes
 * -Each child process spwns many (4) threads.
 * -Each thread attempts to read a global resource
 *  maintained by the root.
 **/

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <pthread.h>
# include <fcntl.h>

typedef struct {
    int i;
	unsigned char* str;
	} resource;


void
closallfd(void)
{
    int flmt = sysconf (_SC_OPEN_MAX);
	int fd = 0;

	while (fd < flmt)
	    close(fd++);
}

void
daemonise(void)
{
     pid_t pid = 0;

     if (1 == getppid())        /* already owned by init? */
	     exit (EXIT_FAILURE);

     pid = fork();
	 if (0 > pid)
	     exit (EXIT_FAILURE);

     if (0 < pid)
	     exit (EXIT_SUCCESS);   /* exit parent */
		 
     /* child continues */

	 /* open log file if needed here */

	 
	 if (0 > setsid())          /* create a new session, become leader */
	     exit(EXIT_FAILURE);

     umask(0);                  /* file creation mask */

	 if (0 > chdir ("/"))       /* change to a safe directory */
	     exit (EXIT_FAILURE);

     closallfd();
	 
	 open("/dev/null", O_NOCTTY); /* optionally ..*/
	 dup(0); dup(0);

     pid = fork ();             /* again */
	 if (0 > pid)
	     _exit(EXIT_FAILURE);

     if (0 < pid)
	     _exit (EXIT_SUCCESS);  /* exit parent */

     /**
	  * surviving child goes on to be a daemon 
	  **/

    /* spawn other child processes here.. */

}

int
main (void)
{

    daemonise();
	while (1)
	    sleep (30);
	return 0;
}
