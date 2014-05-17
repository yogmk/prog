%{
# include "hoc.h"
# include "y.tab.h"

extern int lineno;
%}
%%
[ \t]                       { ; }       /* skip blanks and tabs */

[0-9]+\.?|[0-9]*\.[0-9]+   	{
                               sscanf (yytext, "%lf", &yylval.val);
							   return NUMBER;
							}

[a-zA-Z][a-zA-Z0-9]*   		{
                               Symbol *s;
							   if ((s = lookup (yytext)) == 0)
							   	  s = install (yytext, UNDEF, 0.0);
							   yylval.sym = s;
							   return s->type == UNDEF ? VAR : s->type;
							}
^:.*                        {
							   //fgets (yytext, 100, stdin);
							   yytext[0] = ' ';     /* wipe leading ':' */
							   yylval.cmd = malloc (strlen(yytext));
							   strcpy (yylval.cmd, yytext);
							   puts (yylval.cmd);
							   return CMD;
							}

\n                          {  lineno++; return '\n'; }

.                           {  return yytext[0]; }

