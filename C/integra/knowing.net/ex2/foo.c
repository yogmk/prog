# ident "@(#) driver program for testing Haar()."

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>

typedef float Pixel;
void Haar(Pixel*, Pixel*, const int, const float);
void revHaar(Pixel*, Pixel*, const int, float);
float average(Pixel*, int);
int getseries(int, char**, Pixel*);

int nu_size;


int
main(int argc, char **argv)
{
	int n, i;
	float av=0.0;
	float sum=0.0;
	Pixel *series = NULL;
	Pixel *transformed = NULL;

	if (argc < 3)
	{
		puts("usage: foo n1 n2 ...");
		puts("n1 n2 sould be a series of pairs of numbers (even).");
		exit (0);
	}
	series = (Pixel*)malloc(5 * sizeof(Pixel));
	n = getseries(argc, argv, series);

	for (i=0; i<n; i++)
		printf(" %f,", series[i]);

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
          {
             printf(" %f,", series[i]);
             sum = sum + series[i];
          }
	putchar('}');

        revHaar(series, transformed, n, sum);
	if (series == NULL) 
	{
		perror("revHaar");
		exit(EXIT_FAILURE);
	}
	putchar('{');
	for (i=0; i<n; i++)
		printf(" %f,", series[i]);
	putchar('}');

	return 0;
}
