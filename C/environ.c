# include <stdio.h>

/**
 * look at main()'s signature
 * third parameter holds a 
 * pointer-to-pointer to 'environment'
 **/


int
main (int argc, char** argv, char** envp)
{
    char* p;
	while (p = *envp++)
	    puts (p);

    return 0;
}
