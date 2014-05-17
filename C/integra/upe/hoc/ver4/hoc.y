%{
# include "hoc.h"

# define PROMPT                printf ("(hoc)")
# define code2(c1, c2)         code (c1); code (c2)
# define code3(c1, c2, c3)     code (c1); code (c2); code (c3)
%}
%union                      /* yacc stack type */
{
	Symbol *sym;            /* symbol table pointer */
	Inst   *inst;           /* machine instruction */
	char   *cmd;            /* passed on to shell */
}
%token  <sym>   NUMBER VAR CONST BLTIN UNDEF
%token  <cmd>   CMD         
%right  '='
%left   UNPLUS              
%left   '-' '+'            
%left   '*' '/' '%'       
%left   UNMINUS          
%right  '^'             
%%
list:						/* nothing */ 
		| list '\n'         { PROMPT; }
		| list command '\n'
		| list asgn '\n'    { code(STOP); PROMPT; return 1; }
		| list asgn ';'     { code(STOP); PROMPT; return 1; }
		| list expr '\n'    { code2(print, STOP); PROMPT; return 1; }
		| list expr ';'     { code2(print, STOP); PROMPT; return 1; }
		| list error '\n'   { yyerrok; PROMPT; }
		;
		
command:  CMD               { shell($1); PROMPT; }
        ;

asgn:	  VAR '=' expr      { code3(varpush, (Inst)$1, assign); }
        | CONST '=' expr    { execerror ("won't assign to non-variable", $1->name); }
        ;
	
expr:     NUMBER			{ code2(constpush, (Inst)$1); }
        | CONST             { code3(varpush, (Inst)$1, eval); }
        | VAR               { code3(varpush, (Inst)$1, eval); }
		| asgn  
		| BLTIN '(' expr ')'      { code2(bltin, (Inst)$1->u.ptr); }
        | '+' expr %prec UNPLUS   { ; }
        | '-' expr %prec UNMINUS  { code(neg); }
		| expr '+' expr		{ code(add); }
		| expr '-' expr		{ code(sub); }
		| expr '*' expr		{ code(mul); }
		| expr '/' expr	    { code(dvd); }
		| expr '%' expr		{ code(mod); }
		| expr '^' expr     { code(power); }
		| '(' expr ')'  	
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


int
main (int argc, char **argv)
{
	void catch_fpe(), bannar (), init ();
	progname = argv[0];

	bannar ();
	init ();
	setjmp (begin);
	signal (SIGFPE, catch_fpe);

	/* parse now returns after each 
	 * stmt ot expr instead of token i
	 */
	PROMPT;
	for (initcode (); yyparse (); initcode () )
		execute (prog);
	return 0;
}

# ifndef _LEX_VER_

int
yylex (void)
{
	int c;

	while ((c=getchar ()) == ' ' || c == '\t')
		;
	if (c == EOF)
		return 0;

	if (c == ':')
	{                 /* do not ungetc ':' */
		char buf[100];
		yylval.cmd = malloc (sizeof buf);
		fgets (yylval.cmd, sizeof buf, stdin);
        yylval.cmd [strlen(yylval.cmd)] = '\0';    /* overwrite '\n' */
		return CMD;
	}

    /**
	 * unlike before, push the numbers on the stack
	 * instead of consuming them.
	 */
	if (c == '.' || isdigit (c))        
	{
	    double d;
		ungetc (c, stdin);
		scanf ("%lf", &d);
		yylval.sym = install ("", NUMBER, d);
		return NUMBER;
	}

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
	
	if (c == '\n')
		lineno++;
	
	return c;
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
    puts("/*");
# ifdef _LEX_VER_
	puts(" * This is a 'lex' version of 'hoc'.");
# endif
    puts(" * hoc ver. 4.0: a basic calculator program from the book" );
    puts(" * \"Unix Programming Environment\"  - Karnighan and Pike.");
	puts(" * This version has same functionality as ver 3.0, but it ");
	puts(" * has been implemented as a 'stack machine' internally.");
	puts(" * The code is quite different from previous version.");
    puts(" */");
}
