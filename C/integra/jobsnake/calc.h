
/* header for calculator program */

# define LIM 100 

extern char line[];			/* buffer to store the expression 	*/

static int pos;					/* current parse position in the buffer */
static int token;

extern double pop_op(void);
extern double pop_no(void);
extern void push_op(char);
extern void push_no(double);

double no_stack[LIM]; 			/* stack to store operands(numbers) 	*/
//int nsp=0; 						/* numbers' stack pointer.				*/

char op_stack[20];				/* stack for operators	*/
//int osp=0;						/* operator stack pointer 	*/


/* grammar for the expression parsing */

/*  - precedence rules -
 *  Parentheses have precedence over all other operators. 
 *  ^ (exponentiation) has precedence over /, *, -, and +. 
 *  * and / have precedence over - and +. 
 *  Unary - has precedence over binary - and +. 
 *  ^ is right associative while all other operators are left associative
 */

/*
 * Assign an integer precedence to each operator, so that multiplication(and division) 
 * have higher precedence than addition (and subtraction). Push each number onto a stack 
 * (a FIFO list) as it is read. Compare the precedence of an incoming operator with the 
 * precedence of the top operator on the stack to decide whether to apply the operator 
 * on the stack or to push the newoperator onto the stack.
 */

 enum precedence
 {
 	eol= (-1), number=0, minus=1, plus, uminus, times, divid, expo, rparen, lparen
 };

 void statement();
 int expression();
 int term();
 int factor();
 int getnumber();
