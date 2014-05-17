# include <stdio.h>

int
main (void)
{
    int (*new)(void);

    new = main;

    printf ("main is at %p\n", new);
    return 0;

}
