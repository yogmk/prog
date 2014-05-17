# ident "@(#) Routines that execute machine instruction & manipulate the stack."

# include "hoc.h"
# include "y.tab.h"


# define NSTACK 256
static Datum stack [NSTACK];             /* the stack */
static Datum *stackp;                    /* next free location on the stack */


# define NPROG  2000
Inst   prog [NPROG];                     /* the machine */
Inst   *progp;                           /* next free location for code generation */
Inst   *pc;                              /* program counter during execution */


void
initcode ()
{
	stackp = stack;
	progp = prog;
}

/**
 *  The Stack:
 */

void
push (Datum d)
{
	if (stackp >= &stack [NSTACK])
		execerror ("stack overflow", (char*)0);
	
	*stackp++ = d;
}

Datum
pop (void)                  /* clear & return top element from stack */
{
	if (stackp <= stack)
		execerror ("stack underflow", (char*)0);
	//return *stackp--;
	return *--stackp;
}

/**
 * The machine:
 */

Inst*
code (Inst f)               /* install one instruction or operand */
{
	Inst *oprogp = progp;

	if (progp >= &prog [NPROG])
		execerror ("program too big", (char*)0);
	
	*progp++ = f;
	return oprogp;
}

void
execute (Inst *p)            /* run the machine */
{
    /* execute the function pointed to by the instruction pointed to by pc 
	   pc   = pointer to Inst
	   Inst = pointer to function
	*/
	for (pc = p; *pc != STOP; )
		(*(*pc++))();         /* important to advance pc here, otherwise we need to
		                         do it in the actual function called */
}

/** 
 * Instructions
 */

constpush ()                /* push const onto stack */
{
	Datum d;
	d.val = ((Symbol*)*pc++)->u.val;
	push (d);
}


varpush ()
{
	Datum d;
	d.sym = (Symbol*)(*pc++);
	push (d);
}


add ()
{
	Datum d1, d2;
	d1 = pop ();
	d2 = pop ();
	d1.val += d2.val;
	push (d1);
}

sub ()
{
	Datum d1, d2;
	d1 = pop ();
	d2 = pop ();
	d1.val -= d2.val;
	push (d1);
}

mul ()
{
	Datum d1, d2;
	d1 = pop ();
	d2 = pop ();
	d1.val *= d2.val;
	push (d1);
}

dvd ()
{
	Datum d1, d2;
	d2 = pop ();
	if (d2.val == 0.0)
		execerror ("division by zero", (char *)0);
	d1 = pop ();
	d1.val /= d2.val;
	push (d1);
}

power ()
{
	Datum d1, d2;
	extern double pow ();
	d1 = pop ();
	d2 = pop ();

	d1.val = Pow(d1.val, d2.val);
	push (d1);
}

mod ()
{
	Datum d1, d2;
	d1 = pop ();
	d2 = pop ();

	d1.val = (int) d1.val % (int) d2.val;
	push (d1);
}

neg ()
{
	Datum d;
	d = pop ();
	d.val = -d.val;
	push (d);
}

eval ()           /* replace pointer by value */
{
	Datum d;
	d = pop ();

	if (d.sym->type == UNDEF)
		execerror ("undefined variable", (char*)0);
	d.val = d.sym->u.val;
	push (d);
}

assign ()          /* store value in variable and pop pointer */
{
	Datum d1, d2;
	d1 = pop ();
	d2 = pop ();
	if (d1.sym->type != VAR && d1.sym->type != UNDEF)
		execerror ("assignment to non-variable", d1.sym->name);
	d1.sym->u.val = d2.val;
	d1.sym->type = VAR;
	push (d2);
}

print ()         /* pop the top value and print */
{
	Datum d;
	d = pop ();
	printf ("\t%.8g\n", d.val);
}

bltin ()         /* evaluate built-in on top of stack */
{
	Datum d = pop ();

    /* cast (*pc) to  "pointer to a function returning double" and execute */
	d.val = (*(double (*)()) (*pc++)) (d.val);
	push (d);
}

void
shell (char *cmd)

{
   if (strlen (cmd) > 0) 
   {
     system (cmd); 
	 free (cmd);
   }
}
