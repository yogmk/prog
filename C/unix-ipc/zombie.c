# ident "Zombie demo"


/* Zombie: When a child dies before its father could call wait() to get it's status,
 * the child is said to have become a Zombie. (Meaning it has died, but it still
 * occupies an entry in the process table, 'cause kernel preserves this entry in
 * case parent needs it)
 */


#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int 
main (void)
{
    pid_t child_pid;
   
    child_pid =fork ();
    if (child_pid >0)
    {
        sleep (60);         /*This is the parent process.Sleep for a minute.*/
    }
    else 
    {
        exit (0);           /*This is the child process.Exit immediately.*/
    }
    return 0;
}
