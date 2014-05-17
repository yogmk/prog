# ident "K&R chapter 1.9, page 28. Program to read a set of lines & print the longest"

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
    printf ("\n%s\n", longest);

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


void copy (char to[], char from[])
 {
   int i;
   for (i=0; from[i] != '\0'; i++)
    to[i] = from[i];

   if (from[i] == '\0')
     to[i] = from[i];
 }
