# ident " a simple calculator supporting 'sum', 'avg', 'product' & 'sqrt'."

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

int
main(int argc, char **argv)
{
	int i=0, n=0;
	double *numbers = NULL;
	double result = 0.0;
	double (*fooptr)(double*) = NULL; 		/* funtion pointer */
	int nu_size = 0;			/* keeps track of memory allocated */

	double sqrt(double); 		/* from math lib */
	double product(double*);
	double sumation(double*);
	double average(double*);

	if (argc < 3)
	{
		puts("usage: calc -{op} n1 n1 ...");
		puts("valid operations are -sum, -avg, -prod[uct] and -sqrt");
		exit (0);
	}

	if ((strcmp(argv[1], "-sum") == 0) ||
		(strcmp(argv[1], "-avg") == 0) ||
		(strcmp(argv[1], "-prod") == 0) ||
		(strcmp(argv[1], "-sqrt") == 0)) 
	{
		;
	}
	else
	{
		printf ("error: invalid operation %s\n", argv[1]);
		exit (-1);
	}
		
	/*
	 * start by allocating memory for 5 numbers,
	 * add 5 more as & when needed.
	 */

	nu_size = 5; 
	numbers = malloc(nu_size * sizeof(*numbers));
	
	for (i=0, n=2; n < argc; i++, n++)
	{
		if (i == nu_size-1)
		{
			nu_size += 5; 		/* memory for 5 more numbers */
			numbers = realloc(numbers, nu_size * sizeof(*numbers));
		}
		if ((numbers[i] = strtod(argv[n], NULL)) == 0.0)
		{
			printf ("=nan %s \n", argv[n]);
			--i;
		}
	}
	numbers[i] = 0.0;;

	/* call appropriate function based on option */
	
	if (strcmp(argv[1], "-sum") == 0) 
		fooptr = sumation;
	else if (strcmp(argv[1], "-avg") == 0) 
		fooptr = average;
	else if (strcmp(argv[1], "-prod") == 0) 
		fooptr = product;


	if (strcmp(argv[1], "-sqrt") == 0) 
	{
		for (i=0; numbers[i]; i++)
		{
			result = sqrt(numbers[i]);
			(isperfectroot(result)) ? printf ("= %d\n", (int)result) : printf ("= %f\n", result);
		}
	}
	else
			printf("=%f \n", fooptr(numbers));

	free(numbers);
	return 0;
}

double
product(double *numbers)
{
	int i;
	double retval = 1.0;

	for (i=0; numbers[i]; i++)
		retval = retval * numbers[i];

	return retval;
}

double
average(double *numbers)
{
	int n=0;
	double val = 0.0;
	double sumation(double*);

	val =(double) sumation(numbers);
	for(n=0; numbers[n]; n++)
		;
	
	return (val / (double)n);
}

double
sumation(double *numbers)
{
	double retval = 0.0;
	int i=0;

	for (i=0; numbers[i]; i++)
		retval = retval + numbers[i];
	
	return retval;
}

int
isperfectroot(double d_)
{
	int n=0;
	double d = 0.0;

	n=(int)d_;
	d = (double) n;

	if (d == d_)
		return 1;
	else
		return 0;
}
