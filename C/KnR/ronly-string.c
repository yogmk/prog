# include <stdio.h>

int 
main (void)
  {

  char a[] = "Hello World! - 1";
  char * p = "Hello World! - 2";
  char *aptr = a;

  puts (a);
  *a = 'X';
  puts(a);

  puts (p);

  *p = 'h';
  puts ("After assignment");
  puts (p);

  return 0;
  }
