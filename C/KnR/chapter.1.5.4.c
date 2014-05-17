# ident "K&R chapter 1.5.4. Program to count characters, words & lines in input"

# include <stdio.h>

# define IN 1		/* inside a word */
# define OUT 0		/* outside a word boundry */

int main ()
 {
 char c;
 int n, w, l; 		/* to hold chars, words & lines resp. */
 int state;

 n = w = l = 0;
 state = OUT;

 printf ("\nEnter text..\n");

 while ((c = getchar()) != EOF)
  {
  ++n;
  if (c == '\n')
   ++l;
  if ( c == ' ' || c == '\t' || c == '\n')
   state = OUT;
  else if (state == OUT)
   {
    state = IN;
	++w;
   }
  }

  printf ("\nThe text had %d characters, %d words & %d lines", n, w, l);
  return 0;

 }
