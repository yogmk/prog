# ident "@(#) K&R chapter 1.10, page 34. Exercise 1.20. Program to 'detab' the tabs with spaces"

# include <stdio.h>
# define MAXLEN 100 		/* maximum length to consider */
# define TABSTOP 8

int getline (char line[], int maxlen);
void detab(char s[]);


int 
main(void)
{
   int currlen;
   char line[MAXLEN];

   currlen=0;
   puts (" ..enter a few lines..");
   while ((currlen = getline(line, MAXLEN)) > 0)
   {
      if (currlen > 0)
      {
       detab(line);
      }
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


/** 
 ** function to replace tabs with blanks 
 */

void 
detab (char s[])
{
   int i, k, tabs, len;
   char c;

   for (i =0; s[i] != '\0'; i++)
    ;
   len = i+1;  				        	/* +1 for '\0' */
   tabs = 0;
   for (i =0; s[i] != '\0'; i++)
   {
        if (s[i] == '\t')
	 /* found a tab, now insert appropriate spaces & shift array to right 
	  * by that many spaces, assuming array is big enough.
	 */
        {
	     s[i] = '_';			        /* replace current tab char with a space */
	     tabs = (TABSTOP - i  % TABSTOP) - 1;
	     //printf ("\n %d spaces reqd.\n", tabs);
	     for (k = len; k >= i; k--)
	     {
	         s[k+tabs] = s[k];
             }
	     len += tabs; 				/* array size has increased */
	     for (k=1; k < tabs ; k++)
	     {
                 s[++i] = '_';
	     }
	}
   }
	puts(s);
}
