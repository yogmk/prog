# ident "From Adv. Linux Progr'mg. listing 3.7"

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>


sig_atomic_t child_status = 0;

/*
 * function will habdle SIGCHLD signal
 * by cleaning up the child process
 */
void 
sigchld_handler (int signal_number)
{
    int status;
    wait(&status);
    child_status = status;
}


int 
spawn (char *prog, char **arg_list)
{
    pid_t child_pid;
   
    child_pid = fork();			/* spawn a child */

    if (child_pid != 0)
    {
        return child_pid;               /* only in parent process, control reaches here */
    }
    if (child_pid == -1)
    {
         printf ("\ncouldn't fork(). Aborting..\n");
         abort();
    }
    else                               /* this must be child,launch the new program */
    {
        execvp (prog, arg_list);

        /* execvp never returns, if it does, it means there was an error  */
        fprintf(stderr, "there was an error in execvp\n");
        abort();
    }
}


int main(void)
{
    int child_status;
    char *arg_list[] = {"ls", "-1", "/", NULL};
    struct sigaction sa;
    char msg[100];

    memset (&sa, 0, sizeof(sa));
    sa.sa_handler = &sigchld_handler;

    sigaction (SIGCHLD, &sa, NULL);

    spawn ("ls", arg_list);

    sleep(10);
    printf("\nchild exited with %d\n", WEXITSTATUS(child_status));
    return 0;

}
