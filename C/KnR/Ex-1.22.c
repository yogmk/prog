# ident "K&R chapter 1.10, page 34. Exercise 1.22. Program to fold long lines"

# include <stdio.h>
# define WIDTH 10  		/* maximum length to consider */
# define TABSTOP 8

int main()
 {
   char line[WIDTH];
   char c;
   int i, k, tabs;
   
   printf("->\n");
   while ((c=getchar()) != EOF)
    {
	for ( i= 0; i<WIDTH; i++)
	 {
	 line[i] = c;
	 if (c == '\t')
	  {
	  line[i] = ' ';
	  tabs = (TABSTOP - i % TABSTOP) - 1;
	  for (k=1; k < tabs; k++)
	   line [++i] = ' ';
	  }
	 }
	}
   puts(line);
   return 0;
 }

