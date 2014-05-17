/*
 * Display series of numbers (1,2,3,4, 5....etc) in an infinite loop. 
 * The program should quit if someone hits a specific key (Say ESCAPE key).
 */

# include <stdio.h>
# include <stdlib.h>
# include <termio.h>
# include <unistd.h>


/* 
 * Program changes the terminal's properties to function
 * in non-canonocal mode. We run an infinite loop, and 
 * periodically check for input from user. If specific input
 * arrives, we exit (but not unless we've restored the terminal!)
 */

 /* N.B.: by it's very nature, this program is non-portable to Windows */

struct termios saved_attr; 			/* to save current attributes 		*/

void set_non_canon (void);
void reset_term (void);

int
main (void)
 {
 char c;
 int i;
 char *s;

 set_non_canon ();						/* change terminal attributes 		*/

 s = (char *) malloc(7);
 for (i=0; ; i++)
  {	
  	write(STDOUT_FILENO, (char *) itoa(i, s), 4);
	read (STDIN_FILENO, &c, 1);			/* try to read 1 char from stdin 	*/

	if (c == 27)						/* Escape */
	 {
	 	reset_term ();
	 	exit(EXIT_SUCCESS);
	 }
  }
 return 0;								/* we won't reach here 				*/
 }


/*
 * This function sets the term to non-canonical mode.
 * based on code input from GNU C library manual
 */

void
set_non_canon ()
 {
 	struct termios term_st;

	/* firat make sure that stdin is a terminal */
	if (!isatty(STDIN_FILENO))
	 {
	 	perror ("istty");
		exit (EXIT_FAILURE);
	 }

	/*
	 * save current attributes so that
	 * we can restore them later
	 */
	tcgetattr(STDIN_FILENO, &saved_attr);
	//atexit (reset_term);

	/* 
	 * set modes: MIN=0 TIME=0
	 * This makes read return immediately if no input is available
	 */
	tcgetattr(STDIN_FILENO, &term_st);
	term_st.c_lflag &= ~(ICANON|ECHO); 			/* clear icanon & echo 	*/
	term_st.c_cc[VMIN] = 0;
	term_st.c_cc[VTIME] = 1;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term_st);

 }


void
reset_term()
 {
 	tcsetattr(STDIN_FILENO, TCSANOW, &saved_attr);
 }
