
typedef struct Symbol               /* symbol table entry */
{
	char *name;
	short type;                     /* VAR, CONST, BLTIN, UNDEF */
	union
	{
		double val;                 /* if VAR or CONST  */
		double (*ptr) ();           /* if BLTIN */
	} u;
	struct Symbol *next;     		/* pointer to next */
} Symbol;

Symbol *lookup (), *install ();


typedef union Datum                 /* interpreter stack type */
{
	double val;
	Symbol *sym;
}Datum;

extern Datum pop ();

typedef int (*Inst) ();             /* machine instruction */

# define STOP (Inst)0

extern Inst prog[];                 /* array of instructions (the program) */

extern  eval (), add (), sub (), dvd (), mul (), neg (), power (), mod ();
extern  assign (), bltin (), varpush (), constpush (), print (); 
