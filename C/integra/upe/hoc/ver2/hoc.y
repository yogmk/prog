%{
double mem[26];             /* memory for variables 'a'...'z' */
%}
%union                      /* yacc stack type */
{
 	double val;             /* actual value */
	int    index;           /* index into mem[] */
}

%token  <val>   NUMBER
%token  <index> VAR
%type   <val>   expr
%right  '='
%left   UNPLUS              /* unary plus has lowest precedene */
%left   '-' '+'             /* left associative, same precedence */
%left   '*' '/' '%'         /* left associative, higher precedence */
%left   UNMINUS             /* unary minus has highest precedence */

%%
list:						/* nothing */
		| list '\n'         /* List, expr can terminate with either '\n' or ';' */
		| list ';'
		| list expr '\n'    { mem['p'-'a'] = $2; printf ("\t%.8g\n", $2); } /* mem[p] acts as */
		| list expr ';'     { mem['p'-'a'] = $2; printf ("\t%.8g\n", $2); } /* last computed val*/
		| list error '\n'   { yyerrok; }
		| list error ';'    { yyerrok; }
		;
expr:     NUMBER			{ $$ = $1; }
        | VAR               { $$ = mem[$1]; }
		| VAR '=' expr      { $$ = mem[$1] = $3; }
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
	int catch_fpe();
	progname = argv[0];

	bannar ();
	setjmp (begin);
	signal (SIGFPE, catch_fpe);
	yyparse ();
	return 0;
}


int
yylex (void)
{
	int c;

	while ((c=getchar ()) == ' ' || c == '\t')
		;
	if (c == EOF)
		return 0;

	if (c == '.' || isdigit (c))        /* a number */
	{
		ungetc (c, stdin);
		scanf ("%lf", &yylval.val);         /** yyval is defined by yyparse() */
		return NUMBER;
	}

	if (islower(c))
	{
		yylval.index = c - 'a';
		return VAR;
	}
	
	if (c == '\n')
		lineno++;
	
	return c;
}

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
    puts(" * hoc ver. 2.0: a basic calculator program from the book" );
    puts(" * \"Unix Programming Environment\"  - Karnighan and Pike.");
    puts(" * supports:");
    puts(" * operators '+', '-', '*', '/' and unary '-', and ");
	puts(" * also '%' and unary '+' as per exercise 8.2.");
    puts(" * varibale names 'a'..'z', and some defense against errors.");
    puts(" */");
}
