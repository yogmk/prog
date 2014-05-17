# ident "K&R exercise 1.19. Function to reverse a line (recursive version)"
# include <stdio.h>

void reverse(char []);

int 
main(void)
{
  //char str[] = "Hello world";
  char * str;

  str = (char *)malloc (sizeof(char) * 20);
  puts ("enter string to reverse..\n");
  scanf("%s", str);
  reverse(str);
  return 0;
}

void reverse(char s[])
{
  int len;
  char c;

  len = strlen(s);
  if (len == 1)
  {
    putchar(s[0]);
    return;
  }
  if (len > 1)
  {
    putchar(s[len-1]);
    s[len-1]='\0';
    reverse(s);
  }
}
