# ident "K&R exercise 1.9, page 20.Program to replace blanks with a single blank"

# include <stdio.h>

# define BLANK ' '

int main()
 {
 char c, lastchar;

 printf ("\nEnter text..\n");

 while ((c = getchar()) != EOF)
  {
  if (c == BLANK && c != lastchar)
   {
   putchar (c);
   }
  if (c != BLANK)
   {
   putchar (c);
   }

  lastchar = c;    /* store the last read character */
  
  }
 return 0;
 }
