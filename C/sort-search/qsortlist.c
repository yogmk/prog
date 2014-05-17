# include <stdio.h>
# include <stdlib.h>


typedef int T;

typedef struct listNode {
    struct listNode * next;
    struct listNode * prev;
    T data;
} listNode;


/* partition list[lb..rb] ad return pointer to pivot */
listNode *
partition (listNode *lb, listNode *rb)
{
    T tmp, pivot;

    listNode *i, *j;

    int done = 0;

    pivot = lb->data;           /* select a pivot */
    
    /* scan from both ends, swapping when needed */
    i = lb, j = rb;

    while (1)
    {
        while (j->data > pivot)
        {
            j = j->prev;           /* move towards left (pivot) */
            if (i == j) done = 1;
        }
        if (done) return j;

        while (i->data < pivot)
        {
            i = i->next;          /* move towards right (pivot) */
            if (i == j) done = 1;
        }
        if (done) return j;

        /* swap i, j */
        tmp = i->data;
        i->data = j->data;
        j->data = tmp;

        /* examine the next element */
        /* without this while loop will examine same element over & over */

        i = i->next;
        if (i == j) done = 1;

        j = j->prev;
        if (i == j) done = 1;
    }
}


void
quicksort (listNode *lb, listNode *rb)
{
    listNode *m;

    if (lb == rb)
        return;

    m = partition (lb, rb);

    if (lb != m) quicksort (lb, m);              /* sort the left side */
    if (m != rb) quicksort (m->next, rb);        /* sort the right side */

}



int
main (int argc, char * argv[])
{

    int maxNum, i;
    listNode *p;

    maxNum = atoi(argv[1]);

    if (NULL == (p = malloc (maxNum * sizeof (listNode))))
    {
        puts ("Insufficient memory!");
        exit (1);
    }

    /* fill the list */

   srand (1);

   puts ("  generated list..");
   for (i = 0; i<= maxNum; i++)
   {
      p[i].prev = &p[i - 1];      /* this, and next are equivalent */
      p[i].next = p + i + 1;
      p[i].data = rand (); 
      printf ("p[%d].data = %d\n", i, p[i].data);
   }
   
   quicksort (p, &p[maxNum-1]);

   puts (" (quik)sorted list..");
   for (i = 0; i<= maxNum; i++)
   {
      printf ("p[%d].data = %d\n", i, p[i].data);
   }
   free (p);

   return 0;
}
