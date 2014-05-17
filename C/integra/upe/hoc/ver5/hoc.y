%{
# include "hoc.h"

# define PROMPT                printf ("hoc>")
# define code2(c1, c2)         code (c1); code (c2)
# define code3(c1, c2, c3)     code (c1); code (c2); code (c3)
%}
%union                      /* yacc stack type */
{
    Symbol *sym;            /* symbol table pointer */
    Inst   *inst;           /* machine instruction */
    char   *cmd;            /* passed on to shell */
}
%token  <sym>   NUMBER VAR CONST BLTIN UNDEF PRINT WHILE IF ELSE FOR
%type   <inst>  stmt asgn expr stmtlist cond while if for end
%token  <cmd>   CMD         
%right  '=' ADD_ASGN  SUB_ASGN  DIV_ASGN  MUL_ASGN  MOD_ASGN
%left   UNPLUS              
%left   OR
%left   AND
%left   GT LT EQ NE GE LE
%left   '-' '+'            
%left   '*' '/' '%'       
%left   UNMINUS  NOT  INCR  DECR
%right  '^'             
%%
list:      /* nothing */ 
        | list '\n'         { PROMPT; }
        | list command '\n'
        | list asgn '\n'    { code(STOP); return 1; }
        | list stmt '\n'    { code(STOP); PROMPT; return 1; }
        | list expr '\n'    { code2(print, STOP); PROMPT; return 1; }
        | list error '\n'   { yyerrok; PROMPT; }
        ;
        
command:  CMD               { shell($1); PROMPT; }
        ;

asgn:     VAR  '='  expr         { $$ = $3; code3(varpush, (Inst)$1, assign); }
        | VAR  ADD_ASGN  expr    { $$ = $3; code3(varpush, (Inst)$1, add_assign); }
        | VAR  SUB_ASGN  expr    { $$ = $3; code3(varpush, (Inst)$1, sub_assign); }
        | VAR  DIV_ASGN  expr    { $$ = $3; code3(varpush, (Inst)$1, div_assign); }
        | VAR  MUL_ASGN  expr    { $$ = $3; code3(varpush, (Inst)$1, mul_assign); }
        | VAR  MOD_ASGN  expr    { $$ = $3; code3(varpush, (Inst)$1, mod_assign); }
        | INCR VAR               { $$ = $2; code3(varpush, (Inst)$2, incr); }
        | DECR VAR               { $$ = $2; code3(varpush, (Inst)$2, decr); }
        | CONST "=" expr         { execerror ("won't assign to non-variable", $1->name); }
        ;
    
stmt:     expr              { /*code(pop)*/; }
        | PRINT expr        { code(print); $$ = $2; }
        | if cond stmt end  {                              /* simple (else-less) if */
                              ($1)[1] = (Inst)$3;          /* pointer to if body */
                              ($1)[3] = (Inst)$4;          /* end, if cond fails */
                            }
        | if cond stmt end ELSE stmt end                   /* if with else */
                            {
                              ($1)[1] = (Inst)$3;          /* pointer to if body */
                              ($1)[2] = (Inst)$6;          /* pointer to else body */
                              ($1)[3] = (Inst)$7;          /* end, if cond fails */
                            }
        | while cond stmt end               
                            {                              /* ($1)[0] has pointer to whilecode() */
                              ($1)[1] = (Inst)$3;          /* pointer to body of loop */
                              ($1)[2] = (Inst)$4;          /* end, if cond fails */
                            }
        | for cond stmt end
                            {
                              ($1)[1] = (Inst)$3;          /* pointer to body of loop */
                              ($1)[2] = (Inst)$4;          /* pointer to next stmt after for(..) loop */
                            }
        | '{' stmtlist '}'  { $$ = $2; }
        ;

cond:     '(' expr ')'      { code(STOP); $$ = $2; }
        ;

while:    WHILE             { $$ = code3 (whilecode, STOP, STOP); }
        ;

if:       IF                { $$ = code(ifcode); code3(STOP, STOP, STOP); }
        ;

for:      FOR               { $$ = code(forcode, STOP, STOP); }
        ;

end:       /* nothing */    { code(STOP); $$ = progp; }
        ;

stmtlist:  /* nothing */    { $$ = progp; }
        | stmtlist '\n'
        | stmtlist stmt
        ;

expr:     NUMBER            { $$ = code2(constpush, (Inst)$1); }
        | CONST             { $$ = code3(varpush, (Inst)$1, eval); }
        | VAR               { $$ = code3(varpush, (Inst)$1, eval); }
        | asgn  
        | BLTIN '(' expr ')'      { $$ = $3; code2(bltin, (Inst)$1->u.ptr); }
        | '+' expr %prec UNPLUS   { $$ = $2; }
        | '-' expr %prec UNMINUS  { $$ = $2; code(neg); }
        | expr '+' expr     { code(add); }
        | expr '-' expr     { code(sub); }
        | expr '*' expr     { code(mul); }
        | expr '/' expr     { code(dvd); }
        | expr '%' expr     { code(mod); }
        | expr '^' expr     { code(power); }
        | expr GT  expr     { code(gt); }
        | expr GE  expr     { code(ge); }
        | expr LT  expr     { code(lt); }
        | expr LE  expr     { code(le); }
        | expr EQ  expr     { code(eq); }
        | expr NE  expr     { code(ne); }
        | expr OR  expr     { code(or); }
        | expr AND expr     { code(and); }
        | NOT  expr         { $$ = $2; code(not); }
        | '(' expr ')'      { $$ = $2; }
        ;
%%
     /* end of grammar */

# include <stdio.h>
# include <ctype.h>
# include <signal.h>
# include <setjmp.h>

char *progname;
int lineno = 1;
jmp_buf begin;
int TRACE_ON = 0;

int
main (int argc, char **argv)
{
    void catch_fpe(), bannar (), init ();
    progname = argv[0];
    int showBannar = 1, i = 0, k = 0;
    unsigned char c = 0;

    /** parse command line arguments */
    if (argc > 1)
    {
        for (i = 1; i < argc; i++)      /* for each arg */
        {
            k = 0;
            while (c = *(argv[i]+k))         /* walk over the characters */
            {
                switch (c)
                {
                     case '-': break;     /* ignore */
                     case 'q':            /* quite, no bannar */
                               showBannar = 0;
                               break;
                     case 't':            /* trace the execution */
                               TRACE_ON = 1;
                               break;
                     default: 
                               printf ("Invalid option %c\n", c);
                               break;
                }
                ++k;
            }
        }
    }

    if (showBannar) bannar();
    init ();
    setjmp (begin);
    signal (SIGFPE, catch_fpe);
    

    /* parse now returns after each 
     * stmt or expr instead of token i */

    for (initcode (); yyparse (); initcode ())
        execute (prog);
    return 0;
}

# ifndef _LEX_VER_

int
yylex (void)
{
    int c;

    while ((c = getchar()) == ' ' || c == '\t')
        ;
    if (c == EOF)
        return 0;

    /* 
     * a shell command? 
     */
    if (c == ':')
    {                 /* do not ungetc ':' */
        char buf[100];
        yylval.cmd = malloc (sizeof buf);
        fgets (yylval.cmd, sizeof buf, stdin);
        yylval.cmd [strlen(yylval.cmd)] = '\0';    /* overwrite '\n' */
        return CMD;
    }

    /**
     * Number:
     *       unlike earlier versions (consuming the number), 
     *       push it on the stack
     */
    if (c == '.' || isdigit (c))        
    {
        double d;
        ungetc (c, stdin);
        scanf ("%lf", &d);
        yylval.sym = install ("", NUMBER, d);
        return NUMBER;
    }

    /**
     * Variable
     */
    if (isalpha (c))
    {
        Symbol *s;
        char buf[100], *p = buf;

        do
        {
          *p++ = c;
        } while ((c=getchar()) != EOF && isalnum(c));
        ungetc (c, stdin);
        *p = '\0';

        if ((s = lookup (buf)) == 0)
            s = install (buf, UNDEF, 0.0);

        yylval.sym = s;
        return s->type == UNDEF ? VAR : s->type; 
    }
    

    /**
     * Operator
     */
    switch (c)
    {
        case '>':    return follow ('=', GE, GT);
        case '<':    return follow ('=', LE, LT);
        case '=':    return follow ('=', EQ, '=');
        case '!':    return follow ('=', NE, NOT);
        case '|':    return follow ('|', OR, '|');
        case '&':    return follow ('=', AND, '&');
        case '/':    return follow ('=', DIV_ASGN, '/');
        case '*':    return follow ('=', MUL_ASGN, '*');
        case '%':    return follow ('=', MOD_ASGN, '%');
        case '+':    if (ADD_ASGN == follow ('=', ADD_ASGN, '+'))   
                         return ADD_ASGN;
                     else
                         return follow ('+', INCR, '+');
        case '-':    if (SUB_ASGN == follow ('=', SUB_ASGN, '-'))
                         return SUB_ASGN;                           /* -= or */
                     else
                         return follow ('-', DECR, '-');            /* -- */
        case '\n':    lineno++; return '\n';
        default :   return c;
    }
}

int 
follow (int expect, int ifyes, int ifno)
{
    int c = getchar ();

    if (c == expect)
        return ifyes;
    ungetc (c, stdin);
    return ifno;
}
# endif

yyerror (char *s)
{
    warning (s, (char*) 0);
}

execerror (char *s, char *t)
{
    warning (s, t);
    longjmp (begin, 0);
}

warning (char *s, char *t)
{
    fprintf (stderr, "%s: %s", progname, s);
    if (t)
        fprintf (stderr, " %s", t);
    fprintf (stderr, " near line %d\n", lineno);
}


catch_fpe ()
{
    execerror ("floating point exception", (void *) 0);
}

void
bannar(void)
{

     puts ("    ****************************************************************   ");
     puts ("    * hoc: a calculator program from the book 'The Unix            * * ");
     puts ("    * Programming Environment'  -- Karnighan and Pike.             ****");
     puts ("    *                                                                 *");
# ifdef _LEX_VER_
     puts ("    * This is a 'lex' version of 'hoc'.\n                             *");
# endif
     puts ("    * supports:                                                       *");
     puts ("    * 1. Operators '+', '-', '*', '/'.                                *");
     puts ("    * 2. unary '-', '%' and unary '+' (exercise 8.2).                 *");
     puts ("    * 3. Varibale names 'a'...'z'                                     *"); 
     puts ("    * 4. Exponentiation operator '^', arbitrary variable names.       *");
     puts ("    * 5. prevent assignment to constants (8.5)                        *");
     puts ("    * 6. rand () and atan2 () (8.6),                                  *");
     puts ("    * 7. execute unix shell commands from within hoc (8.7)            *");
     puts ("    * 8. Full set of relational operators and control flow.           *");
     puts ("    *******************************************************************");
}
