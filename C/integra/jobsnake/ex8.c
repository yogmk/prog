
# ident "Open a text file and convert it into HTML file."


# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

enum htags {HTML, TITLE, HEAD, BODY, H1, P, PRE, OL };
enum hchars {SPAC, GT, LT, AMPR, QUOT};

/*
 * since HTML tags/chars are static, we can define them in an array of strings
 */

char *open_tag [] = {"<HTML>", "<TITLE>", "<HEAD>", "<BODY>", "<H1>", 
                     "<P>", "<PRE>", "<OL>" };
char *close_tag [] = {"</HTML>", "</TITLE>", "</HEAD>", "</BODY>", "</H1>", 
                      "</P>", "</PRE>", "</OL>"};
char *html_char[] = {"&nbsp;", "&gt;", "&lt;", "&ampr;", "&quot;" };


int
main (int argc, char** argv)
{
	FILE *is, *os;
	int c, i, run = 1;

	if (argc < 2)
	{
		puts("usage: tx2htm <text file> [output file]");
		exit (0);
	}

	if ((is = fopen(argv[1], "r")) == NULL)
	{
		perror(argv[1]);
		exit (EXIT_FAILURE);
	}

	if (argc == 2) /* output file-name not provided */
		os = stdout;
	else
	{
		if ((os = fopen(argv[2], "w")) == NULL)
		{
			perror(argv[2]);
			exit(EXIT_FAILURE);
		}
	}

	/* start <html> tags */
	fputs(open_tag[HTML], os);
	fputs(open_tag[TITLE], os);
	fputs("tx2htm: converts text to html", os);
	fputs(close_tag[TITLE], os);
	fputs(open_tag[HEAD], os);
	fputs(close_tag[HEAD], os);
	fputs(open_tag[BODY], os);
	/*
	 * first line in the file is a heading!
	 */
	fputs(open_tag[H1], os);
	while ((c=fgetc(is)) != '\n')
		fputc(c, os);
	fputs(close_tag[H1], os);

	/*
	 * once inside the bosy, the logic of where to insert html tags
	 * depends entirely upon the file contents & format
	 * so lets just treat each subsequent line as a paragraph
	 */
	while (run)
	{
		fputs(open_tag[P], os);
		while ((c=fgetc(is)) != '\n' && c!=EOF)
			fputc(c, os);
		if (c == '\n')
			fputs(close_tag[P], os);
		if (c == EOF)
			run = 0;
	}
	
	fputs(close_tag[BODY], os);
	fputs(close_tag[HTML], os);
	
	close(is), close(os);
	return 0;
}
