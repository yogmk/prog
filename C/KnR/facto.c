# include <stdio.h>

int facto (int );

int 
main(void)
{
  int *n;
  long int ans;

  
  puts ("enter a number..");
  n = malloc (sizeof(int));
  scanf("%d", n);
  printf ("you entered.. %d\n", *n);

  ans = facto(*n);

  printf("factorial of %d is..%d\n", *n, ans);
  return ans;
}

int 
facto(int n)
{
  int x;

  if (n == 1)
    return 1;
  x = n * facto(n-1);
  return x;
}
