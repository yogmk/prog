# ident "@(#) Extract UPPERCASE words, or unique words from a file."

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

# define MWORDS 50


int LIM=100;

int
main (int argc, char** argv)
{
	void uniqwords(FILE*);
	void ucasewords(FILE*);
	FILE* is;

	if (argc < 2)
	{
		puts("usage: ext -U[ppercase] / -u[nique] <input-file>");
		return 0;
	}
	if (argc < 3)
	{
		puts("accepting input from stdin..");
		is = stdin;
	}
	else if ((is = fopen(argv[2], "r")) == NULL)
	{
		perror(argv[2]);
		exit (EXIT_FAILURE);
	}

	
	if (strcmp(argv[1], "-u") == 0)
		uniqwords(is);
	else if (strcmp(argv[1], "-U") ==0)
		ucasewords(is);
	else
		printf("%s: Illegal option.", argv[1]);

		
	close(is);
	return 0;
}


/* getword: get next word from input stream */

int
getword(char* word, FILE* is)
{
	int c;
	char *w=word;

	while(isspace(c=fgetc(is)))
		;
	if (c !=EOF)
		*w++ = c;
	if (!isalpha(c))
	{
		*w = '\0';
		return c;
	}
	for (LIM=100 ; --LIM > 0; w++)
	{
		if (!isalnum(*w=fgetc(is))) 
		{
			ungetc(*w, is);
			break;
		}
	}
	*w = '\0';
	return word[0];
}



void
uniqwords(FILE* is)
{
	int found(char*, char**, int);
	int getword(char*, FILE*);
	char word[LIM];						/* biggest word we'll encounter */
	char** wa = NULL;					/* words array */
	int wa_size = 0;					/* keeps track of (re/m)alloc'ed memory */
	int wc=0;							/* word count */
	int i=0;

	/*
	 * we initially allocate space for 10 words, and
	 * as and when needed, we'll realloc() the array
	 */
	
	wa_size = MWORDS * sizeof(*wa);
	printf("debug: wa_size = %d\n", wa_size);
	wa = malloc(wa_size);

	for (i=0, wc=0; getword(word, is) != EOF; i++)
	{
		if (!found(word, wa, wc))
		{
			if (wc > (wa_size / sizeof(*wa))) 		/* check overflow	*/
			{
				wa_size += (MWORDS*sizeof(*wa));
				printf("debug: wa_size = %d\n", wa_size);
				if ((wa = realloc(wa, wa_size)) == NULL)			/* space for 10 more words */
				{
					puts("error! can't allocate more memory. unable to continue");
					break;
				}
			}
			printf("debug: adding '%s'\n", word);
			wa[wc] = malloc(strlen(word));
			strcpy(wa[wc], word);
			wc++;
		}
	}

	/* print & free */
	while(--wc >= 0)
	{
		puts (wa[wc]);
		free (wa[wc]);
	}
	free (wa);
}


void
ucasewords(FILE* is)
{
	int i, ucase;
	int getword(char*, FILE*);
	char word[LIM];		/* biggest word we'll encounter */

	while (getword(word, is) != EOF)
	{
		for(i=0, ucase=1; isupper(word[i]); i++)
			;
		if (word[i] != '\0')
			ucase = 0;
		if(ucase)
			puts(word);
	}
}

int
found(char* w, char** list, int n)
{
	while (--n >=0)
	{
		if (strcmp(list[n], w) == 0)			/* found! */
			return 1;
	}
	return 0;
}
