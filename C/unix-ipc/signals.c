# ident "setting up different signal handlers"

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <signal.h>

int 
main (void)
{
    struct sigaction sa_intr;
    struct sigaction sa_term;
    struct sigaction sa_quit;
    void sig_handler_intr(int sig);   /* prototype declaration */
    void sig_handler_term(int sig);   /* prototype declaration */
    void sig_handler_quit(int sig);   /* prototype declaration */
    char s [100];

    /* set-up the handlers */

     memset(&sa_intr, 0, sizeof(sa_intr));
     sa_intr.sa_handler = SIG_IGN;
     sigaction(SIGINT, &sa_intr, NULL);


     memset(&sa_term, 0, sizeof(sa_term));
     sa_term.sa_handler = SIG_IGN;
     sigaction(SIGTERM, &sa_term, NULL);

     memset(&sa_quit, 0, sizeof(sa_quit));
     sa_quit.sa_handler = SIG_IGN;
     sigaction(SIGQUIT, &sa_quit, NULL);
   
     printf("\nEnter some text..\t");
     if (NULL == fgets(s, sizeof (s), stdin))
     	 perror("fgets");
     else
         printf("\nyou entered...%s", s);

     return 0;
}

 /* SIGNAL the handler functions */

void 
sig_handler_intr (int sig)
{
    printf ("caught a ^C ->%d\n", sig);
    fflush (stdout);
}


void 
sig_handler_term (int sig)
{
    printf ("caught a signal 2- >%d\n", sig);
}

void 
sig_handler_quit (int sig)
{
    printf ("caught a ^\\ ->%d\n", sig);
}

