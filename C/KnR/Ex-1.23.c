
# ident "Program to remove all comments from a C program source."

# include <stdio.h>

# define IN 1
# define OUT 0

int
main (void)
  {
  char c, prevc;
  int state; 

  prevc = ' ';
  state = OUT;

  while ((c = getchar()) != EOF)
    {
    if (c == '*')
	  {
	  if (prevc == '/')
	    /* We are inside a comment 
		 * don't echo any char and
		 * set the state
		 */
		{
		state = IN;
		prevc = c;
		}
	  }
	if (state == IN && c == '/')
	  {
	  if (prevc == '*')
	    {
		/* We've reached end of comment, set state to OUT & start echo / *
		 */
		state = OUT;
		prevc = c = ' ';		/* this is important */
		}
	  }
		
	if (state == OUT)
	  putchar (prevc);
	  prevc = c;
	}
  }
