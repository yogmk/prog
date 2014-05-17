# ident "@(#) wrap long lines. (pointer version)"

# include <stdio.h>
# include <stdlib.h>

static int WRAPMARGIN;

int 
main(int argc, char ** argv)
{
	int c;
	int margin;             		/* how far we are from wrap margin */
	char *line=NULL;
	char *tmpline = NULL;			/* place to save temp chars */
	int i, tmpi, linebreak=0;
	
	if (argc < 2)
	{
		puts ("usage: wrap -<WRAPMARGIN> [FILE]");
		return 0;
	}

	if (!atoi(argv[1]))
	{
		puts("error: wrap margin must be numeric.");
		return 1;
	}
	else
	{
		WRAPMARGIN = -(atoi(argv[1]));
		line = malloc (WRAPMARGIN+1);
		tmpline = malloc (WRAPMARGIN);		/* can be even smaller */
	}

	for(i=0, margin=WRAPMARGIN; (c=getchar()) != EOF; )
	{
		if (margin > 0)
		{
			if (isspace(c))
				linebreak = i;
			*(line+i) = c;
			margin--;
			if (c == '\n')			/* reached EOL before wrap margin */
			{
				*(line+i) = '\0';		/* overwrite '\n' */
				margin = 0;		
			}
			i++;
		}

		if (margin <= 0 && linebreak == 0 && strlen(line) != 0)
		{
			puts ("error: word too big to fit into wrap margin.");
			return 1;
		}

		if (margin == 0)
		{
			*(line+linebreak) = '\0';

			/* save trailing chars to tmp array */
			for (tmpi=0; ++linebreak < i; tmpi++)
				*(tmpline + tmpi) = *(line + linebreak);

			*(tmpline + tmpi) = '\0';
			
			puts(line);

			i=0;
			if (*tmpline != '\0')				/* anything to copy? */
			{
				for (i=0; i < tmpi; i++)		/* copy back */
					*(line + i) = *(tmpline + i);
				*(line + i) = c;					/* c already read */
			}

			linebreak=0;						/* ready for a new line */
			margin = (WRAPMARGIN - (i));
		}

	}
	free(line);
	free(tmpline);
	return 0;
}
