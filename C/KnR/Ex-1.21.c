# ident "K&R chapter 1.10, page 34. Exercise 1.21. Program to 'entab' the spaces with tabs "

# include <stdio.h>
# define MAXLEN 100 		/* maximum length to consider */
# define TABSTOP 8

int getline (char line[], int maxlen);
void entab(char s[]);


int main()
 {
   int currlen;
   char line[MAXLEN];

   currlen=0;
   printf ("\n Enter a few lines..\n");
   while ((currlen = getline(line, MAXLEN)) > 0)
    {
    if (currlen > 0)
     {
     entab(line);
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

/* 
 * function to replace spaces with tabs 
 */
void entab (char s[])
 {
   int i, k, spaces, len;
   char c;

   for (i =0; s[i] != '\0'; i++)
    ;
   len = i+1;	/* +1 for '\0' */	
   spaces = 0;
   for (i =0; s[i] != '\0'; i++)
    {
	/* find out the number of continuous spaces.
	 * from first 'i' position, determine how
	 * many spaces away the next stop is.
	 * and thereafter insert one tab for every 
	 * TABSTOP number of spaces
	 */
    if (s[i] == ' ')
	 {
	 k=i+1;		/* save the 'position' of first blank & proceed till next non-blank */
	 for (; s[i] != ' '; i++)
	  {
	  spaces ++;
      if (((i+1) % TABSTOP) == 0)
	  /* from 'k' to 'this' position, there was a series of blanks
	   *  we'll replace it with tab
	  */
	   {
	   s[k-1] = '\t';
	   /* move the array
	   }
	  }
	 }
	}
	puts(s);
 }
