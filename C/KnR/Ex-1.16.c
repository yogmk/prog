# ident "K&R chapter 1.9, page 30. Program to read a set of lines & print the length of the longest"

# include <stdio.h>
# define MAXLEN 1000		/* maximum length to consider */

void copy (char to[], char from[]);
int getline (char line[], int maxlen);


int main()
 {
   int currlen;
   int max;
   char line[MAXLEN];
   char longest[MAXLEN];

   max =0, currlen=0;
   printf ("\n Enter a few lines..\n");
   while ((currlen = getline(line, MAXLEN)) > 0)
    {
       if (currlen > max)
		{
	    max = currlen;
		copy(longest, line);		/* save the line */
		}
	}
   if (max > 0)
	{
    printf ("\n%s\n", longest);
    printf ("%d\n", max);
	}

   return 0;
 }


int getline (char line[], int maxlen)
 {
   char c;
   int i;

   for(i=0; (i < maxlen-1) && (c=getchar()) != EOF && c != '\n'; ++i)
    {
    line[i] = c;
	}
   if (c == '\n')
	{
    line[i] = c;
	++i;
	}
   line[i] = '\0';
   return i;
 }

/* 
 function modified to remove trailing blanks & tabs from the line 
*/
void copy (char to[], char from[])
 {
   int i;
   for (i=0; from[i] != '\n'; i++)
    to[i] = from[i];

   /*
   if (from[i] == '\0')
    to[i] = '\0';
   */

   /*
   * to remove trailing blanks, tabs
   * go reverse till we hit a non blank
   * character & replace '\0'
   */

   for ( ; to[--i] == ' ' || to[i] == '\t'; i--)
    ;
   to[++i] = '\n';
   to[++i] = '\0';
   printf ("\nline truncated at %d", i);
 }
