# ident "K&R exercise 1.19. Function to reverse a line (basic version)"

# include <stdio.h>
# define MAXLEN 1000		/* maximum length to consider */

void reverse (char s[]);
int getline (char line[], int maxlen);


int main()
 {
   int currlen;
   int max;
   char line[MAXLEN];

   currlen=0;
   printf ("\n Enter a few lines..\n");
   while ((currlen = getline(line, MAXLEN)) > 0)
    {
	reverse(line);		/* reverse the line */
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

void reverse(char s[])
 {
 char c;
 int i, len, midpoint, end;

 /* first find out the length of the array
    we don't know about strlen() as yet
 */

 for (i=0; s[i] != '\0'; i++)
  ;
 /* i is the length */
 len = i-1; 			/* minus 1 for '\0' */
 midpoint = len / 2;

 /* now, reverse the array char by char */
  for ( i=0, end=len; i <= midpoint; i++, end--)
   {
    c = s[i];
	s[i] = s[end];
	s[end] = c;
   }

  printf("%s\n", s);
 }
