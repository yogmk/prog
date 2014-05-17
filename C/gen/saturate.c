# include <stdio.h>
# include <limits.h>

int
main (void)
{
    long double l=0.0;

    l = 2000000000 + 1000000000;

    printf ("%ld\n", l);

    return 0;
}
