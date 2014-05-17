# ident "K&R exercise 1.13, page 25. Program to print the (Verticle) histogram of lengths of the words in its input"

# include <stdio.h>

# define IN 0
# define OUT 1
# define MAXHIST 10  	/* upto these many word lengths will be recorded */

int main ()
 {
 char c; 				/* read next char from input into this */
 int i, j ;           	/* generic loop counter */
 int state, len;

 int tallest, current;

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
   * The for loop above gathered all the word lengths.
   * It's time to display.
  */

  /* 
   * first we need to find the max value in the counter array (~tallest column) 
  */

  tallest = 0;
  for (i=0; i<=MAXHIST; i++)
   {
   if (length_counter[i] > tallest)
      tallest = length_counter[i];
   }
 
  /*
   * Now for the length of the counter array, we plot the points one row
   * at a time, each column in the row represents a subscript in the array
   * Outer loop will iterate 'tallest' no of times (height/ Y axis) and 
   * inner loop will iterate for the length of the array (length/X axis).
   * if the value at the subscript is less than the tallest (adjusted for 
   * the current row), we plot space
   */

  for (current = tallest; current >= 1; --current)
   {
    for (i=0; i <= MAXHIST; i++)
	 {
     if (length_counter[i] < current)
	  {
	  putchar(' ');
	  }
	 else
	  {
	  putchar('|');
	  }
	 }
	putchar('\n');
   }

  for (i=0; i<=MAXHIST; i++)
   {
   putchar('-');
   }

  putchar('\n');
 } /* main */

