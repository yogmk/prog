# ident "K&R chapter 1.9, page 30. Program to read a set of lines & print the length of the longest(extern version)"

# include <stdio.h>
# define MAXLEN 1000		/* maximum length to consider */

void save ();
int getline ();

int maxlen;
char line [MAXLEN];
char longest [MAXLEN];

int main()
 {
   int currlen;
   int max;
   extern char longest[];

   max =0, currlen=0;
   printf ("\n Enter a few lines..\n");
   while ((currlen = getline()) > 0)
    {
    if (currlen > max)
	 {
	  max = currlen;
	  save();		/* save the line */
	 }
	}
   if (max > 0)
	{
    printf ("\n%s\n", longest);
    printf ("%d\n", max);
	}

   return 0;
 }


int getline ()
 {
   char c;
   int i;
   extern char line[];

   for(i=0; (i < MAXLEN-1) && (c=getchar()) != EOF && c != '\n'; ++i)
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

void save ()
 {
   int i;
   extern char line[];
   extern char longest[];

   for (i=0; line[i] != '\0'; i++)
    longest[i] = line[i];

 }


