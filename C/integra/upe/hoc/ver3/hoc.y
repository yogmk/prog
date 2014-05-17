%{
# include "hoc.h"
extern double Pow ();
%}
%union                      /* yacc stack type */
{
 	double val;             /* actual value */
	Symbol *sym;            /* symbol table pointer */
	char * cmd;             /* external shell command (not used by hoc) */
}
%token  <val>   NUMBER
%token  <sym>   VAR CONST BLTIN UNDEF
%token  <cmd>   CMD         /* everything on the line is passed to shell */
%type   <val>   expr asgn
%right  '='
%left   UNPLUS              /* unary '+' lowest prece. */
%left   '-' '+'             /* left associative */
%left   '*' '/' '%'         /* left associative, higher prece. */
%left   UNMINUS             /* unary '-' has even higher prece. */
%right  '^'                 /* exponentiation, highest prec. */
%%
list:						/* nothing */ 
		| list '\n'         /* terminator can be either '\n' or ';' */ { printf ("(hoc)"); }
		| list ';'   
		| list command '\n'
		| list asgn '\n'    { printf ("(hoc)"); }
		| list asgn ';'     
		| list expr '\n'    { printf ("\t%.8g\n", $2); printf ("(hoc)"); }
		| list expr ';'     { printf ("\t%.8g\n", $2); }
		| list error '\n'   { yyerrok; printf ("(hoc)"); }
		;
		
command:  CMD               { if (strlen ($1) > 0) 
                              {
                                  system ($1); 
								  free (yylval.cmd);
							  }
							  printf ("(hoc)"); 
							}
        ;

asgn:	  VAR '=' expr      { if ($1->type == CONST)
                                 execerror ("can't change the constant", $1->name);
							  else {
                                 $$ = $1->u.val = $3; 
								 $1->type = VAR; 
							  }
							}
		| CONST '=' expr    { execerror ("can't change the constant", $1->name); } 
        ;
	
expr:     NUMBER			
        | CONST             { $$ = $1->u.val; }
        | VAR               { if ($1->type == UNDEF)
		                       		execerror ("undefined variable", $1->name);
							  $$ = $1->u.val;
							}
		| asgn  
		| BLTIN '('')'      { $$ = (*($1->u.ptr))(); }
		| BLTIN '(' expr ')'      { $$ = (*($1->u.ptr))($3); }
		| BLTIN '(' expr ',' expr ')'      { $$ = (*($1->u.ptr))($3, $5); }
        | '+' expr %prec UNPLUS   { $$ = $2; }
        | '-' expr %prec UNMINUS  { $$ = -$2; }
		| expr '+' expr		{ $$ = $1 + $3; }
		| expr '-' expr		{ $$ = $1 - $3; }
		| expr '*' expr		{ $$ = $1 * $3; }
		| expr '/' expr		
		                    { if ($3 == 0.0)
				   		         execerror ("division by zero", "");
				              $$ = $1 / $3; 
				            }
		| expr '%' expr		{ $$ = (int)$1 % (int)$3; }
		| '(' expr ')'  	{ $$ = $2; }
		| expr '^' expr     { $$= Pow($1, $3); }
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
	yyparse ();
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
		yylval.cmd = malloc (100);
		fgets (yylval.cmd, 100, stdin);
        yylval.cmd [strlen(yylval.cmd)] = '\0';    /* wipe '\n' character */
		return CMD;
	}

	if (c == '.' || isdigit (c))        
	{
		ungetc (c, stdin);
		scanf ("%lf", &yylval.val);         
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
    puts(" * hoc ver. 3.0: a basic calculator program from the book" );
    puts(" * \"Unix Programming Environment\"  - Karnighan and Pike.");
    puts(" * supports:");
    puts(" * Operators '+', '-', '*', '/' and unary '-',");
	puts(" * also '%' and unary '+' as per exercise 8.2.");
    puts(" * Varibale names 'a'..'z', and some defense against errors.");
	puts(" * Exponentiation operator '^', arbitrary variable names.");
	puts(" * We also has a 'lex' version of 'main' and 'make'");
	puts(" * Prevent asignment to constants (ex 8.5), built-in functions");
	puts(" * rand () and atan2() (ex 8.6), and facility to execute unix");
	puts(" * command from inside hoc (ex 8.7)");
    puts(" */");
}
