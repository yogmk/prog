# include <stdio.h>
# include <unistd.h>

int 
main (void)
{
	int i =0;

    fprintf (stdout, "[ ]");
    fprintf (stdout, "\b\b");
	for (i=0; i < 100; i++)
	  {
		putchar ('\\');
		fflush (stdout);
		usleep(300);
		putchar ('\b');
		fflush (stdout);
		putchar ('|');
		fflush (stdout);
		usleep(300);
		putchar ('\b');
		fflush (stdout);
		putchar ('/');
		fflush (stdout);
		usleep(300);
		putchar ('\b');
		fflush (stdout);
	  	putchar ('-');
		fflush (stdout);
		usleep(300);
		putchar ('\b');
		fflush (stdout);
	}
	putchar ('\n');
}
