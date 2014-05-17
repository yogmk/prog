# ident "@(#) driver program for testing Haar()."

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>

void Haar(float*, float*, const int, const float);
float average(float*, int);
int getseries(int, char**, float*);

int nu_size;

typedef short Pixel;

int
main(int argc, char **argv)
{
	int n, i;
	float av=0.0;
	Pixel *series = NULL;
	Pixel *transformed = NULL;

	if (argc < 3)
	{
		puts("usage: foo n1 n2 ...");
		puts("n1 n2 sould be a series of pairs of numbers (even).");
		exit (0);
	}
	series = malloc(5 * sizeof(Pixel));
	n = getseries(argc, argv, series);

	for (i=0; i<n; i++)
		printf(" %f,", (double)series[i]);

	putchar('\n');
	if (series == NULL) 
	{
		perror ("getseries");
		exit(EXIT_FAILURE);
	}

	av = average(series, n);
		
	Haar(series, transformed, n, av);
	if (series == NULL) 
	{
		perror("Haar");
		exit(EXIT_FAILURE);
	}

	putchar('{');
	for (i=0; i<n; i++)
		printf(" %f,", (double)series[i]);
	putchar('}');
	
/*
        revHaar(series, transformed, n, av);
	if (series == NULL) 
	{
		perror("revHaar");
		exit(EXIT_FAILURE);
	}
	putchar('{');
	for (i=0; i<n; i++)
		printf(" %f,", (double)series[i]);
	putchar('}');
*/

	return 0;
}
