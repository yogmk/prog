# ident "K&R exercise 1.13, page 25. Program to print the histogram of lengths of the words in its input"

# include <stdio.h>

# define IN 0
# define OUT 1
# define MAXHIST 10  	/* upto these many word lengths will be recorded */

int main ()
 {
 char c; 				/* read next char from input into this */
 int i, j ;           	/* generic loop counter */
 int state, len;

 int length_counter[MAXHIST];  /* 
							   Each subscript will act as a length indicator. 
							   Thus subscript '0' will store value indicating 
							   number of words having '0' length (whitespace),
							   and so on 
							   */
 
 for (i = 0; i <= MAXHIST; i++)
   length_counter[i] = 0;

 len = 0;
 state = IN;

 while ((c = getchar()) != EOF)
  {
  if ( c == ' ' || c == '\t' || c == '\n')
   {
   if (state == IN)
    {
    state = OUT;
    ++(length_counter[len]);  	 	/* increment appro. subscript by one */
    len = 0;					    /* reset len */
	}
   }
  else if (state == OUT)
   {
   state = IN;    			/* We're back inside a word */
   ++(length_counter[0]);	/* previous one or more whitespaces were One word */
   ++len;                   /* this was a valid character (non-space) */
   }
  else
   ++len;
  } /* for */

  /*
   * The for loop above gathers all the word lengths
   * Now time to display..
  */


 
 for ( i=0; i<= MAXHIST; i++)
  {
  printf("%2d|", i);
  if (length_counter[i] > 0)
   {
   for (j=0; j<length_counter[i]; j++)
    {
    putchar('[');
    putchar(']');
    }
   }
  putchar('\n');
  }

 } /* main */

