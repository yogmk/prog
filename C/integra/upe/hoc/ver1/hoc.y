%{
# define YYSTYPE double     /* data type of yacc stack */
%}

%left   UNPLUS              /* unary plus hasowest precedene */
%token  NUMBER
%left   '-' '+'             /* left associative, same precedence */
%left   '*' '/' '%'         /* left associative, higher precedence */
%left   UNMINUS             /* unary minus has highest precedence */

%%
list:						/* nothing */
		| list '\n'
		| list expr '\n'    {printf ("\t%.8g\n", $2); }
		;
expr:		NUMBER			{ $$ = $1; }
        | '+' expr %prec UNPLUS   { $$ = $2; }
        | '-' expr %prec UNMINUS  { $$ = -$2; }
		| expr '+' expr		{ $$ = $1 + $3; }
		| expr '-' expr		{ $$ = $1 - $3; }
		| expr '*' expr		{ $$ = $1 * $3; }
		| expr '/' expr		{ $$ = $1 / $3; }
		| expr '%' expr		{ $$ = (int) $1 % (int) $3; }
		| '(' expr ')'  	{ $$ = $2; }
		;
%%

# include <stdio.h>
# include <ctype.h>

char *progname;
int lineno = 1;

int yylex (void);
void yyerror (char *);
void warning (char*, char*);

int
main (int argc, char **argv)
{
	progname = argv[0];
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
		scanf ("%lf", &yylval);         /** yyval is defined by yyparse() */
		return NUMBER;
	}
	if (c == '\n')
		lineno++;
	
	return c;
}


void
yyerror (char *s)
{
	warning (s, (char *) 0);
}

void
warning (char *s, char *t)
{
	fprintf (stderr, "%s: %s", progname, s);
	if (t)
		fprintf (stderr, " %s", t);
	fprintf (stderr, " near line %d\n", lineno);
}
