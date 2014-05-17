
char*
reverse (char *line)
 {
 int i, j;
 char temp;
 int len = strlen(line)-1;
 i=0, j = (len / 2);

 while (i <= j)
  {
  temp = *(line+i);
  *(line+i) = *(line+len);
  *(line+len) = temp;
  i++, len--;
  }
 
 return line;
 }
