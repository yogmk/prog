/**
 * This lex file has some cathing-up to do with hoc5
 * It is not able to handle 2char operators like >=, += etc
 * We need to augment this file to do that
 **********************************************************/

%{
# include "hoc.h"
# include "y.tab.h"

extern int lineno;
%}
%%
[ \t]                       { ; }       /* skip blanks and tabs */

[0-9]+\.?|[0-9]*\.[0-9]+    {
                               //sscanf (yytext, "%lf", &yylval.val);
                               yylval.sym = install ("", NUMBER, strtod(yytext, 0x0));
                               return NUMBER;
                            }

[a-zA-Z][a-zA-Z0-9]*        {
                               Symbol *s;
                               if ((s = lookup (yytext)) == 0)
                                     s = install (yytext, UNDEF, 0.0);
                               yylval.sym = s;
                               return s->type == UNDEF ? VAR : s->type;
                            }
^:.*                        {
                               //fgets (yytext, 100, stdin);
                               yytext[0] = ' ';          /* overwrite leading ':' */
                               yylval.cmd = malloc (strlen(yytext));
                               strcpy (yylval.cmd, yytext);
                               puts (yylval.cmd);
                               return CMD;
                            }

\n                          {  lineno++; return '\n'; }

.                           {  return yytext[0]; }

