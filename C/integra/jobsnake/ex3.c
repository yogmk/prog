# ident "@(#) Accept numbers/strings from user & sort them asc or dsc order."

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX 100

int numcmp(const void*, const void*);            /* proto of function comparing ints     */
int cmpstr(const void*, const void*);
char** reverse(char**);

enum { O_ASC = 1, O_DSC = 2};
enum { NUM = 1, STR = 2};
int order = 0, option = 0;

int
main(int argc, char** argv)
  {

    int i, k;
    int n[MAX];
    char **s = NULL;
    char **tmpstr = NULL;

    if (argc <3)
      {
              puts ("usage: srt -option <n, n1, n2 . . .>");
            puts ("options can be -a -d for asc and desc, and -s -n for strings & numbers");
            puts ("numbers can be separated by space, comma, tab & end with newline.");
            exit (EXIT_FAILURE);
      }
    
    /*
     * gather the input
     * user may enter options as -x -y or -xy or any order and combinations of x & y.
     *
     * parse only argv [1] and argv [2] or till both order & option are known.
     */

    for (i=1; i <= 2 && order < 1 && option < 1; i++)
      {
        k = 0;
        while (*(*(argv+i)+k))
         {
            switch (*(*(argv+i)+k))
             {
                 case '-':     break;

                case 'a':    order = O_ASC;
                            puts ("ascending ");
                            break;

                case 'd':    order = O_DSC;
                            puts ("dscending");
                            break;
                            
                case 's':    option = STR;
                            puts ("string compare!");
                            break;
                            
                case 'n':    option = NUM;
                            puts ("numeric compare!");
                            break;

                default :     printf ("Illegal option: %c\n", *(*(argv+i)+k));
                            exit (EXIT_FAILURE);
             }
            k++;
         }
      }

    /* input begins from argv [i] */
    s = argv+i;

    qsort((void **) s, argc-i, sizeof(*s), 
          (int(*)(const void*, const void*)) (option==NUM)? numcmp : cmpstr );

    for (k=0; *(s+k); k++)
    {
        puts(*(s+k));
    }
      return 0;
  }


 /*
  * string compare function being passed to qsort
  */

 int cmpstr (const void* s1, const void* s2)
  {
  /*
   * Note the pointer assignment/conversion from void* to char**
   * because qsort always passes void*, void* to compare function
   * whereas strcmp requires char*, char*
   */
      const char** a = s1;
    const char** b = s2;

    if (order == O_ASC)
        return strcmp(*a, *b);
    else if (order == O_DSC)
        return strcmp (*b, *a);
  }
  

 /*
  * integer compare function being passed to qsort
  */

int
numcmp (const void *a, const void *b)
  {
    char **a_ = a;
    char **b_ = b;

    if (order == O_ASC)
            return (int) (atoi(*a_) - atoi(*b_));
    else if (order == O_DSC)
            return (int) (atoi(*b_) - atoi(*a_));
  }

