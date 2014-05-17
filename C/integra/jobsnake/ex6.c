# ident "Scientific calculator program."

/*
 * supporting addition, subtraction, multiplication, division, 
 * square-root, square, cube, sin, cos, tan, Factorial, inverse, modulus
 */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

enum {LIM=100};

char line[LIM];					/* buffer to red the expression */
int getline(char[], int);

int
main (void)
{
	int len=0;
	while (1)
	{
		len = getline(line, LIM);
		
		if (strcmp(line, "quit") == 0)
		   return 0;
		
		if (len >0) 
			parse();
	}
}


/*
 * get a line of input expression to parse
 * (excluding trailing '\n')
 */

int 
getline(char line[], int lim)
{
	int i=0, c=0;
 	
	for (i=0; i < LIM; i++)
			line[i] = ' ';

	putchar('=');
	for (i=0; (c=getchar()) != EOF && c != '\n'; i++)
	{
    	line[i] = c;
	}
	if (c == EOF)
		return EOF;

	line[i++] = '\0';
    return 1; 
}

