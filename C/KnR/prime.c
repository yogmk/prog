# ident "@(#) prim: a program to print prime numbers from 1 - 100."

# include <stdio.h>
# include <math.h>

int 
main(void)
{
  int i, j;

  puts ("2.");
  for (i=3; i < 100; i++)
    {
	for (j=2; j < i; j++)
	  {
	  if ((i % j) == 0)
	    /** 'i' has a divisor, therefore it can't be a prime number. */
		{
		break;
		}
	  if (j > sqrt(i))
	    {
		printf("%d.\n", i);
		break;
		}
	  }
	}
  return 0;
}
