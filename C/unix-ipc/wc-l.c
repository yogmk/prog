# ident "a simple prog to emulate the functionality of ll | wc -l"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <signal.h>


int 
main ()
 {
 pid_t pin;
 int pipe_fd[2];

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
 
 if (pin > 0)
  /* this is parent(sender to pipe) */
  {
  //close(stdout);				/* close standard out */
  close(1);						/* close standard out */
  close(pipe_fd[0]);			/* close write end of the pipe */
  //dup2(stdout, pipe_fd[1]);	/* duplicate pipe's write end as stdout */
  dup(pipe_fd[1]);	
  execlp("ls", "ls", "-al", NULL);
  open(1);
  puts("parent:waiting for the child.\n");
  wait(&pin);
  puts("parent:waiting over..\n");
  exit (0);
  //return 0;
  }
 else
  /* This is child (reader from pipe)*/
  {
  //close(stdin);
  close(0);
  close(pipe_fd[1]);
  //dup2(stdin, pipe_fd[0]);
  dup(pipe_fd[0]);
  execlp("wc", "wc", "-l", NULL);
  //exit (0);
  open(0);
  puts("child: returning..\n");
  return 0;
  }
 }
