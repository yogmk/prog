# ident "K&R exercise 1.10, page 20.Program to replace tabs, backspaces & backslashs with '\t', '\b' & '\\'"

# include <stdio.h>

# define TAB   '\t'
# define BACKSPACE '\b'
# define BACKSLASH '\\'

int main()
 {
 char c, lastchar;

 printf ("\nEnter text..\n");

 while ((c = getchar()) != EOF)
  {
  if (c == TAB)
   {
   putchar ('\\');
   putchar ('t');
   }
  else if (c == BACKSPACE)
   {
   putchar ('\\');
   putchar ('b');
   }
  else if (c == BACKSLASH)
   {
   putchar ('\\');
   putchar ('\\');
   }
  else
   {
   putchar (c);
   }
  }
 return 0;
 }
