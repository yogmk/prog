# ident "using fork & exec together"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>

int 
spawn (char *prog, char **arg_list)
{
    pid_t child_pid;
   
    child_pid = fork();			/* spawn a child */
    if (child_pid != 0)
      /* 
       * if control comes here, this is the parent 
       * so return the child's pid
       */
    {
        return child_pid;
    }
    if (child_pid == -1)
    {
        printf ("\ncouldn't fork(). Aborting..\n");
        abort();
    }
    else
       /*
        * If control comes here, this must be child
        * Launch the new program.
        */
    {
       execvp (prog, arg_list);
       /*
        * if control returns from execvp, it means
        * there was an error.
        */
       fprintf(stderr, "there was an error in execvp\n");
       abort();
    }
}


int 
main (void)
{
  int child_status;

  char *arg_list[] = {"ls", "-1", "/", NULL};

  spawn ("ls", arg_list);

  wait(&child_status);
  if (WIFEXITED(child_status))
      printf("\nchild process exited normally\n", WEXITSTATUS(child_status));
  else
      puts ("child process exited abnormally");

  return 0;

}
