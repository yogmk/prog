# ident "@(#)convert integer to a string.$"

char* itoa(int n, char* s)
  {
   int i=0;

   do
    {
	s[i++] = n%10 + '0';
	} while ((n /= 10) > 0);

   s[i] = '\0';
   reverse(s);
   return s;
  } 
