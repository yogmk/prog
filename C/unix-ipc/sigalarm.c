# ident "Demo of sigalarm"

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>

sig_atomic_t keep_going = 1;

void do_stuff()
 {
 printf ("While other things happen, keep looping\n");
 }

void
catch_alarm(int signum)
 {
 //keep_going = 0;
 //signal (SIGALRM, catch_alarm);
 if (!keep_going)
  raise(signum);
 keep_going = 0;
 }

int
main()
 {
 signal (SIGALRM, catch_alarm);

 alarm(2);

 while(keep_going)
  {
  do_stuff();
  }
 
 signal(SIGALRM, SIG_DFL);
 raise(SIGALRM);
 return 0;
 }
