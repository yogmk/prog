
typedef struct Symbol               /* symbol table entry */
{
	char *name;
	short type;                     /* VAR, BLTIN, UNDEF */
	union
	{
		double val;                 /* if VAR */
		double (*ptr) ();           /* if BLTIN */
	} u;
	struct Symbol *next;     		/* pointer to next */
} Symbol;

Symbol *lookup (), *install ();
