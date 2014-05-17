# ident "K&R exercise 1.12. Program to print its input one word per line"

# include <stdio.h>

# define IN 1		/* inside a word */
# define OUT 0		/* outside a word boundry */

int main ()
 {
 char c;
 int state;

 state = IN;

 printf ("\nEnter text..\n");

 while ((c = getchar()) != EOF)
  {
  if (state == IN)
   putchar (c);
  if ( c == ' ' || c == '\t' || c == '\n')
   {
   state = OUT;
   putchar ('\n');
   }
  else if (state == OUT)
   {
   state = IN;
   putchar (c);
   }
  }

  return 0;

 }
