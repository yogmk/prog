# ident "From Beej's guide to Unix IPC. Demo of signal handling"

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <signal.h>

char msg[] = "No ^C!";

int 
main (void)
{
    void sig_handler_intr(int sig);   /* prototype declaration */
    char s [100];

    /*
     * set-up the handler 
     */
     if (signal(SIGINT, sig_handler_intr) == SIG_ERR)
     {
         /* handler could not be set-up */
         perror("signal");
         exit (1);
     }

     printf("\nEnter some text..\t");
     if (NULL == fgets(s, sizeof (s), stdin))
  	 perror("gets");
     else
         printf("\nyou entered...%s", s);

     return 0;
}

/*
 * This is the handler function
 */

void 
sig_handler_intr (int sig)
{
    puts(msg);
}
