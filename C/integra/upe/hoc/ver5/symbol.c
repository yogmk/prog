
# include "hoc.h"
# include "y.tab.h"

static Symbol *symlist = 0;      /* symbol table: linked list */

Symbol *
lookup (s)                       /* find s in symbol table */
 char *s;
{
	Symbol *sp;

	for (sp = symlist; sp != (Symbol*) 0; sp = sp->next)
		if (strcmp(s, sp->name) == 0)
			return sp;

	return (Symbol*) 0;
}


Symbol *
install (const char *s, const int t, const double d) /* install s in symbol table */
{
	Symbol *sp;
	char *emalloc ();

	sp = (Symbol*)emalloc (sizeof(Symbol));
	if (sp)
	{
		sp->name = (char*)emalloc (strlen(s)+1);
		strcpy (sp->name, s);
		sp->type = t;
		sp->u.val = d;
		sp->next = symlist;      /* put at the front of the list */ 
		symlist = sp;

		return sp;
	}
}

char *
emalloc (unsigned n)             /* check return from malloc */
{
	char *p, *malloc();

	if ((p = malloc (n)) != 0)
		return p;
	else
		execerror ("out of memory", (char*) 0);
}

