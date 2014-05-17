# ident "K&R exercise 1.8, page 20.Program to count blanks, tabs & newlines"

# include <stdio.h>

# define BLANK ' '
# define TAB   '\t'
# define NEWLINE '\n'

int main()
 {
 char c;
 int b, t, n;      /* to hold blanks, tabs & newlines count resp */

 b = t = n = 0;
 printf ("\nEnter text..\n");
 while ((c = getchar()) != EOF)
  {
  if (c == BLANK) ++b;
  if (c == TAB) ++t;
  if (c == NEWLINE) ++n;
  }
 printf ("\nThe input had %d blanks, %d tabs & %d newlines.\n", b,t,n);
 return 0;
 }
