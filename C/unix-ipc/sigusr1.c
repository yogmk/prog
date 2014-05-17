# ident "From Adv. Linux Progr'mg. listing 3.5"

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>
# include <sys/types.h>


sig_atomic_t sig_count = 0;

void 
handler (int signal_number)
{
    ++sig_count;
}


int 
main(void)
{
    struct sigaction sa;
    char msg[100];
   
    memset (&sa, 0, sizeof(sa));
    sa.sa_handler = & handler;
   
    sigaction (SIGINT, &sa, NULL);
   
    if (NULL == fgets(msg, sizeof (msg), stdin))
        perror("gets");
    else
        printf ("You entered....$s", msg);
   
    printf("\nSIGUSR1 was raised %d times\n", sig_count);
    return 0;
}

