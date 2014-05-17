# include <stdio.h>
# include <limits.h>

int
main (void)
{
    unsigned long l;
    float f, g;

    for (l = 0; l < (ULONG_MAX-1000); l += 1000)
    {
        f = l, g = l+1;
        if (f == g)
        {
            printf ("(float) %ld+1 == (float) %ld\n", l, l);
            break;
        }
     }

     f = l; 
     printf ("%f++ =>  ", f);
     f++;
     printf ("%f\n ", f);
     return 0;
}
