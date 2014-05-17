# ident "@(#) wrap long lines."

# include <stdio.h>

# define WRAPMARGIN 35

int 
main(void)
{
	int c;
	int margin = WRAPMARGIN;		/* how far we are from wrap margin */
	char line[WRAPMARGIN+1];		/* +1 for '\0' */
	char tmpline[WRAPMARGIN];		/* place to save temp chars (needn't be so big) */	
	int i, tmpi, linebreak=0;
	
	for(i=0, margin=WRAPMARGIN; (c=getchar()) != EOF; )
	{
		if (margin > 0)
		{
			if (isspace(c))
				linebreak = i;
			line[i] = c;
			margin--;
			if (c == '\n')			/* reached EOL before wrap margin */
			{
				line[i] = '\0';		/* overwrite '\n' */
				margin = 0;		
			}
			i++;
		}

		if (margin <= 0 && linebreak == 0 && strlen(line) !=0)
		{
			puts ("error: word too big to fit into wrap margin.");
			return 1;
		}

		if (margin == 0)
		{
			line[linebreak] = '\0';

			/* save trailing chars to tmp array */
			for (tmpi=0; ++linebreak < i; tmpi++)
				tmpline[tmpi] = line[linebreak];

			tmpline[tmpi]='\0';
			
			puts(line);

			i=0;
			if (tmpline[0] != '\0')				/* anything to copy? */
			{
				for (i=0; i < tmpi; i++)		/* copy back */
					line[i] = tmpline[i];
				line[i] = c;					/* c already read */
			}

			linebreak=0;						/* ready for a new line */
			margin = (WRAPMARGIN - (i));
		}

	}
	return 0;
}
