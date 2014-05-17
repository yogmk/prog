# ident "@(#) Routines that execute machine instruction & manipulate the stack."

# include "hoc.h"
# include "y.tab.h"

# define TRACE(x)  if (TRACE_ON) puts (x);
# define TRACE2(x,y)  if (TRACE_ON) printf (x,y);

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
TRACE (" \tinit ");
    stackp = stack;
    progp = prog;
    printf ("hoc5>");
}

/****************************
 *  The Stack:              *
 *  push() and pop() Datum  *
 ****************************/

void
push (Datum d)
{
TRACE (" \tpush ");
    if (stackp >= &stack [NSTACK])
        execerror ("stack overflow", (char*)0);
    *stackp++ = d;
}

Datum
pop (void)                  /* clear & return top element from stack */
{
TRACE (" \tpop ");
    if (stackp <= stack)
        execerror ("stack underflow", (char*)0);
    return *--stackp;
}


/*****************
 *  The machine: *
 *               *
 *****************/

/* install function pointer in the machine */
Inst*
code (Inst f)               /* install an instruction/operand in the 'machine' */
{
    Inst *oprogp = progp;

    if (progp >= &prog [NPROG])
        execerror ("program too big", (char*)0);
    
    *progp++ = f;
    return oprogp;
}

void
execute (Inst *p)            /* run the 'machine' */
{
    TRACE (" #\toperation\twhat");
    TRACE ("--\t---------\t---------------");
    TRACE ("0\tinit ");

    /* execute the function pointed to by the instruction pointed to by pc 
       pc   = pointer to Inst
       Inst = pointer to function
    */
    for (pc = p; *pc != STOP; )
        (*(*pc++))();        /* important to advance pc here (++), otherwise we 
                                need to do it in the actual function called */
}

/********************* 
 * The Instructions: *
 *********************/

constpush ()                 /* push const onto stack */
{
    Datum d;
    d.val = ((Symbol*)*pc++)->u.val;
TRACE2 (" \tconstpush \t%g\n", d.val);
    push (d);
}


varpush ()
{
    Datum d;
    d.sym = (Symbol*)(*pc++);
TRACE2 (" \tvarpush  \t'%s'\n", d.sym->name);
    push (d);
}


add ()
{
TRACE (" \tadd ");
    Datum d1, d2;
    d2 = pop ();
    d1 = pop ();
    d1.val += d2.val;
    push (d1);
}

sub ()
{
TRACE (" \tsubtract ");
    Datum d1, d2;
    d2 = pop ();
    d1 = pop ();
    d1.val -= d2.val;
    push (d1);
}

mul ()
{
TRACE (" \tmultiply ");
    Datum d1, d2;
    d2 = pop ();
    d1 = pop ();
    d1.val *= d2.val;
    push (d1);
}

dvd ()
{
TRACE (" \tdiv ");
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
TRACE (" \tpower ");
    Datum d1, d2;
    extern double pow ();
    d2 = pop ();
    d1 = pop ();
    d1.val = Pow(d1.val, d2.val);
    push (d1);
}

mod ()
{
TRACE (" \tmod ");
    Datum d1, d2;
    d2 = pop ();
    d1 = pop ();
    d1.val = (int) d1.val % (int) d2.val;
    push (d1);
}

neg ()
{
TRACE (" \tneg ");
    Datum d;
    d = pop ();
    d.val = -d.val;
    push (d);
}

eval ()           /* replace pointer by value */
{
TRACE (" \teval ");
    Datum d;
    d = pop ();

    if (d.sym->type == UNDEF)
        execerror ("undefined variable", (char*)0);
    d.val = d.sym->u.val;
    push (d);
}

assign ()          /* store value in variable and pop pointer */
{
TRACE (" \tassign ");
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
TRACE (" \tprint ");
    Datum d;
    d = pop ();
    printf ("\t = %.8g\n", d.val);
}

bltin ()         /* evaluate built-in on top of stack */
{
TRACE (" \tbltin ");
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


void
gt (void)
{
    Datum d1, d2;

    d2 = pop ();
    d1 = pop ();
    d1.val = (double)(d1.val > d2.val);
    push (d1);
}


void
lt (void)
{
    Datum d1, d2;

    d2 = pop ();
    d1 = pop ();
    d1.val = (double)(d1.val < d2.val);
    push (d1);
}


void
ge (void)
{
    Datum d1, d2;

    d2 = pop ();
    d1 = pop ();
    d1.val = (double)(d1.val >= d2.val);
    push (d1);
}


void
le (void)
{
    Datum d1, d2;

    d2 = pop ();
    d1 = pop ();
    d1.val = (double)(d1.val <= d2.val);
    push (d1);
}


void
eq (void)
{
    Datum d1, d2;

    d2 = pop ();
    d1 = pop ();
    d1.val = (double)(d1.val == d2.val);
    push (d1);
}


void
ne (void)
{
    Datum d1, d2;

    d2 = pop ();
    d1 = pop ();
    d1.val = (double)(d1.val != d2.val);
    push (d1);
}


void
and (void)
{
    Datum d1, d2;

    d2 = pop ();
    d1 = pop ();
    d1.val = (double)(d1.val != 0.0 && d2.val != 0.0);
    push (d1);
}


void
or (void)
{
    Datum d1, d2;

    d2 = pop ();
    d1 = pop ();
    d1.val = (double)(d1.val != 0.0 || d2.val != 0.0);
    push (d1);
}


void
not (void)
{
    Datum d;

    d = pop ();
    d.val = (double)(d.val == 0.0);
    push (d);
}

/* exercise 8.13 */

void 
add_assign (void)
{
TRACE (" \t '+='  ");
    Datum d1, d2;

    d1 = pop ();
    if (d1.sym->type != VAR || d1.sym->type == UNDEF)
        execerror ("assignment to non-variable or undefined variable ", d1.sym->name);
    d2 = pop ();
    d1.sym->u.val = d1.sym->u.val + d2.val;
    push (d1);
}


void 
sub_assign (void)
{
TRACE (" \t '-='  ");
    Datum d1, d2;

    d1 = pop ();
    if (d1.sym->type != VAR || d1.sym->type == UNDEF)
        execerror ("assignment to non-variable or undefined variable ", d1.sym->name);
    d2 = pop ();
    d1.sym->u.val = d1.sym->u.val - d2.val;
    push (d1);
}

void 
div_assign (void)
{
TRACE (" \t '/='  ");
    Datum d1, d2;

    d1 = pop ();
    if (d1.sym->type != VAR || d1.sym->type == UNDEF)
        execerror ("assignment to non-variable or undefined variable ", d1.sym->name);
    d2 = pop ();
    d1.sym->u.val = (d1.sym->u.val / d2.val);
    push (d1);
}

void 
mul_assign (void)
{
TRACE (" \t '*='  ");
    Datum d1, d2;

    d1 = pop ();
    if (d1.sym->type != VAR || d1.sym->type == UNDEF)
        execerror ("assignment to non-variable or undefined variable ", d1.sym->name);
    d2 = pop ();
    d1.sym->u.val = (d1.sym->u.val * d2.val);
    push (d1);
}

void 
mod_assign (void)
{
TRACE (" \t '%='  ");
    Datum d1, d2;

    d1 = pop ();
    if (d1.sym->type != VAR || d1.sym->type == UNDEF)
        execerror ("assignment to non-variable or undefined variable ", d1.sym->name);
    d2 = pop ();
    d1.sym->u.val = ((int) d1.sym->u.val % (int) d2.val);
    push (d1);
}

/* '++' and '--' */

void
incr (void)
{
TRACE ("  \tincr ");
    Datum d;
    d = pop ();

    d.sym->u.val += 1;
    push (d);
}

void
decr (void)
{
TRACE ("  \tdecr ");
    Datum d;
    d = pop ();

    d.sym->u.val -= 1;
    push (d);
}

/*************************
 *  Important routines.  *
 *************************/

/**
 * whilecode opertion is followed by
 * ptr -> loop body 
 * ptr -> next stmt after loop ..
 * ptr -> condition of while (...)
 */
 
void
whilecode (void)
{
    Datum d;
    const Inst *savepc = pc;        /* pointer to ptr -> loop body */

    execute (savepc+2);             /* check condition */
    d = pop ();
    while (d.val)
    {
        execute (*((Inst**)(savepc)));   /* body */
        execute (savepc + 2);            /* keep checking the cond */
        d = pop ();
    }

    pc = *((Inst**)(savepc+1));          /* set pc to next stmt after loop */
}


/**
 * ifcode operation is followed by 
 * ptr -> 'then' body
 * ptr -> 'else' body
 * ptr -> next stmt after if..end
 * ptr -> cond for if (...)
 */

void
ifcode (void)
{
    Datum d;
    const Inst *savepc = pc;         /* pointer to ptr->'if' body */

    execute (savepc+3);              /* evalualte the cond */
    d = pop ();
    if (d.val)
        execute (*((Inst**)savepc));
    else if (*((Inst**)(savepc+1)))  /* else part? */
        execute (*((Inst**)(savepc+1)));

    pc = *((Inst**)(savepc+2));      /* set program counter to next stmt after if..end */
}

/**
 * forcode:
 *     for (pre_expr; cond_expr; post_expr) {
 *       body
 *     }
 */

void
forcode (void)
{
    Datum d;
    const Inst *savepc = pc;

    execute (savepc+2);              /* pre_expr */
    execute (savepc+3);              /* cond_expr */
    d = pop ();

    while (d.val)
    {
        execute (*((Inst**)(savepc)));   /* body */
        execute (savepc + 4);            /* post_expr */
        execute (savepc + 3);            /* keep checking the cond_expr */
        d = pop ();
    }

    pc = *((Inst**) (savepc + 0));        /* set the pc to next stmt after for (;;) */
}

/* print numeric value */
void
prexpr (void)
{
    Datum d;
    d = pop ();
    printf (" = %.8g\n", d.val);
}

