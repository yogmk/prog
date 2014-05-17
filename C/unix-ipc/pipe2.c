# ident "a simple prog that uses pipe & fork. Child writes & father reads"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>


int 
main (void)
{
    pid_t pin;
    char msg [100];
    int pipe_fd[2];
    int i=0;
   
    for (i=0; i<sizeof(msg); i++)
        msg[i]= ' ';
    msg[100] = '\0';
   
    if (pipe(pipe_fd) == -1)
    {
        perror("pipe");
        exit (1);
    }
 
    if ((pin = fork()) == -1)
    {
        perror("fork");
        exit (1);
    }
    
    if (pin == 0)        /* this is child, who writes */
    {
        close (pipe_fd[0]);    /* close the read descriptor */
        puts ("child: writing to the pipe\n");
        fgets(msg, sizeof(msg), stdin);
        write(pipe_fd[1], msg, strlen(msg));
        puts ("child: over & out..");
        exit (0);
    }
    else                 /* This is parent, who shall read */
    {
        close (pipe_fd[1]);   /* close the write end of pipe */
        puts("parent: waiting to read.\n");
        read(pipe_fd[0], msg, sizeof(msg));
        printf("parent: received..\n%s \n", msg);
        wait(&pin);
        return 0;
    }
}
