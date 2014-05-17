# ident "Accept series of numbers, strings from keyboard & sort them ascending, descending orderr"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MIN(a, b) (a) <= (b) ? (a) : (b)
# define MAX(a, b) (a) >= (b) ? (a) : (b)
#  define INT_MAX       2147483647 					/* from limits.h		*/

int
main(int argc, char** argv)
  {
  	int option=1;
    enum { O_MIN = 1, O_MAX = 2};

	int i, n, prevn;

    if (argc <3)
	  {
	  		puts("usage: findm -option <n, n1, n2 . . .>");
			puts("options can be -x/-X for maX and -m/-M for Min");
			puts ("numbers can be separated by space, comma, tab & end with newline.");
			exit(EXIT_FAILURE);
	  }
 
    if (!strcmp(argv[1], "-x") || !strcmp(argv[1], "-X"))
		{
			option = O_MAX;
			prevn = 0;
		}
	else if (!strcmp(argv[1], "-m") || !strcmp(argv[1], "-M"))
		{
			option = O_MIN;
			prevn = INT_MAX;
		}
	else
	  {
	  		puts("usage: findm -option <n, n1, n2 . . .>");
			puts("Illegal option: can be -x/-X for maX and -m/-M for Min");
			exit(EXIT_FAILURE);
	  }
    
  /*
   * get the numbers from command line
  */
    
	for (i = 2; argv[i] != NULL; i++)
	  {
	  	n = (int) atoi(argv[i]);
		if (option == O_MAX)
		 	prevn = MAX(prevn, n);
		else if (option == O_MIN)
			prevn = MIN(prevn, n);
	  }
    printf("The answer is %d\n", prevn);
  	return 0;
  }
