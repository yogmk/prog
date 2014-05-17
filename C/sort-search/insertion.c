/*
 * demonstration of insertion sort
 */

# include <stdio.h>
# include <stdlib.h>

typedef int T;     /* type of item to be sorted */


void
fill (T *a, int low, int high)
{
     int i;
     srand (1);    /* seed random number generation */

     puts ("Numbers generated...");
     for (i = low; i <= high; i++)
     {
         a[i] = rand ();
         //a[i] = high - i;
         printf ("a[%d] = %d\n", i, a[i]);
     }
}



void
insertSort (T *a, int low, int high)
{
     T tmp;
     int i, j;

     /*
      * sort the array a[low..high]
      * start from the second element.
      */

    for (i = low+1; i <= high; i++)
    {
        tmp = a[i];
        printf ("--> %dth element %d\n", i, tmp);

        /* shift the elements down till insertion point is found*/
        for (j = i - 1; j >= low && a[j] > tmp; j--)
        {
            printf ("Shifting %d to %dth place.\n", a[j], j+1);
            a[j+1] = a[j];
        }
        /* insert */
        printf ("Inserting %d at %d\n", tmp, j+1);
        a[j+1] = tmp;
    }

}



int 
main (int argc, char **argv)
{
    int maxNum, lb, ub;

    T *a;

    maxNum = atoi(argv[1]);
    lb = 0, ub = maxNum - 1;

    if (NULL == (a = malloc (maxNum * sizeof (T))))
    {
        puts ("insufficient memory!");
        exit (0);
    }

    fill (a, lb, ub);
    insertSort (a, lb, ub);

    free (a);
    return ;
}

