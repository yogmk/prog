# ident "From Beej's guide to Unix IPC"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

int 
main(void)
{
    pid_t pid;
    int retval;

    printf ("\nfather: I'm the original process & my pid is %d\n", getpid());

    switch (pid = fork())
    {
        case 0: /* control in child process would come here */
               printf("\nchild: I'm the child & my pid is %d\n", getpid());
               printf("\nchild: my father's pid is %d\n", getppid());
               printf("\nchild: time to return. Pl enter return value ->");
               scanf("%d", &retval);
               exit(retval);
          
        case -1:                                  /* something wrong! fork() did not succeed */
               perror("fork");
               break;

        default:                                  /* normal case. child spawned, this is father */
               printf ("\nfather: my son's pid is %d", pid);
               wait(&retval);                     /* wait till child returns */
               printf ("\nfather: child returned with %d\n", WEXITSTATUS(retval));
               break;
    }
}
