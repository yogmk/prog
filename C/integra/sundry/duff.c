# include <stdio.h>

void
duff (short count)
{
	register n=(count+7)/8;
	int j = 1;
	switch(count%8)
	{
	case 0:	while(--n>0){ 	puts ("case 0");
	case 7:		puts ("case 7");
	case 6:		puts ("case 6");
	case 5:		puts ("case 5");
	here:
	j = ++j;
	puts ("you using goto?");
	case 4:		puts ("case 4");
	case 3:		puts ("case 3");
	case 2:		puts ("case 2");
	case 1:		puts ("case 1");
		} 
	}
	if (j==1)
		goto here;
}



int
main(int argc, char **argv)
{
	duff ((short) (*argv[1]- '0'));
	return 0;
}
