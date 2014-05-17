# ident "demo of non-atomic access of variables when signals arrive"

# include <stdio.h>
# include <signal.h>

struct
two_words
 {
 int a;
 int b;
 }memory;

void
handler (int signum)
 {
 signal(SIGQUIT, handler);
 fprintf(stdout,"%d %d,", memory.a, memory.b);
 //alarm(1);
 }

int
main (void)
 {
 static struct two_words zeros = {0,0}, ones = {1,1};

 signal(SIGQUIT, handler);
 memory = zeros;
 //alarm(1);
 while(1)
  {
  memory = zeros;
  memory = ones;
  }
 }
