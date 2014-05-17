# include <stdio.h>
# define BIG 0
# define LITTLE 1

/*
    <--- addresses grow in this direction. <--
	<...MSB  ...LSB
         +-----+
         |00|01| LITTLE ENDIAN 
         +--|--+ ---------------
         |01|00| BIG ENDIAN
         +-----+ ---------------
      . . 1   0  Array subscript
*/


int main (void)
{
    int word = 0x0001;
    char *p;

    p = &word;

    p[0] == 1 ? puts("LITTLE ENDIAN") : puts ("BIG ENDIAN");

    return;
}
