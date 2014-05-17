# ident "@(#) get a series of numbers in an array."

# include <string.h>
# include <stdlib.h>

# include "bmp.h"
extern int nu_size;

int
getseries(int argc, char **argv, Pixel *numbers)
{
	int i=0, n=0;
	/*
	 * start by allocating memory for 5 numbers,
	 * add 5 more as & when needed.
	 */

	//nu_size = 5; 
	//numbers = malloc(nu_size * sizeof(Pixel));
	
	for (i=0, n=1; n < argc; i++, n++)
	{
		if (i == nu_size-1)
		{
			nu_size += 5; 		/* memory for 5 more numbers */
			numbers = realloc(numbers, nu_size * sizeof(Pixel));
		}
		if( (numbers[i]=(Pixel) atoi(argv[n])) == 0)
		{
			printf ("=nan %s \n", argv[n]);
			--i;
		}
	}
	
	if (i%2 == 0) 				/* i has to be even */
		numbers[i] = '\0';		
	else
		numbers[--i] = '\0';	/* discard last (odd) number */

	return i;
}
