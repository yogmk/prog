# include <stdio.h>

typedef int T;


void
fill (T *a, int ub, int lb)
{
    int i;

    puts ("generated numbers...");
    srand (1);     /* seed the random no. generator */
    for (i = lb; i <= ub; i++)
    {
        a[i] = rand ();
        printf ("a[%d]=%d\n", i, a[i]);
    }
}


void
insertsort (T *a, int ub, int lb)
{
    int i, j;
    T tmp;

    puts ("\tstarting insertion sort ");
    for (i = lb + 1; i <= ub; i++)
    {
       tmp = a[i];

       /* shift the elements till insertion point is found */
       for (j = i-1 ; j >= lb && (a[j] > tmp); j--)
       {
           a[j+1] = a[j];
       } 
       a[j+1] = tmp;        /* insert */
    }

}

int
partition (T *a, int ub, int lb)
{
    /* choose a pivot */

    int pivot = a[(lb+ub)/2];
    
    /* work from both ends, swap to keep
     * values less than pivot to the left of pivot and
     * values greater than pivot to the right of pivot
     */
    int i = lb;
    int j = ub;

    while (1)
    {
        T tmp;
        
        while (a[j] > pivot)       /* start moving left towards pivot till we hit a element smaller than pivot*/
            --j;
        while (a[i] < pivot)       /* start moving right towards pivot till we hit a element bigger than pivot*/
            ++i;
 
        if (i >= j)                /* stop on collision */
           break;

        /* swap a[i], tmp */
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
   
    return j;
}


/**
*/
void
quicksort (T *a, int ub, int lb)
{
    int m;

    if (lb >= ub)
    {
        return;
    }

    m = partition (a, ub, lb);
    quicksort (a, m, lb);
    quicksort (a, ub, m+1);
}

/**
 * Improved version of quicksort.
 * If table/array size is small, use inserSort

void
quicksort (T *a, int ub, int lb)
{
    while (lb < ub)
    {
        if ((ub -lb) < 50)
        {
            insertsort (a, ub, lb);
            return;
        }

        int m;
        m = partition (a, ub, lb);

        
    }
}
 */


int
main (int argc, void **argv)
{
    T *a = NULL;
    int maxNum, ub, lb;

    maxNum = atoi (argv[1]);
    
    if (NULL == (a = malloc (maxNum * sizeof (T))))
    {
        puts ("Insufficient memory!");
        exit (0);
    }

    lb = 0; ub = maxNum - 1;

    fill (a, ub, lb);
    quicksort (a, ub, lb);

    puts ("after quick sort...");
    for (lb=0; lb <=ub; lb++)
        printf ("a[%d]=%d\n", lb, a[lb]);

    free (a);
    return 0;
}
            
