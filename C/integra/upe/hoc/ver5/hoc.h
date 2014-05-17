
typedef struct Symbol               /* symbol table entry */
{
    char *name;
    short type;                     /* VAR, CONST, BLTIN, UNDEF */
    union
    {
        double val;                 /* if VAR or CONST  */
        double (*ptr) ();           /* if BLTIN */
    } u;
    struct Symbol *next;            /* pointer to next */
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
extern int TRACE_ON;

extern Inst prog[];                 /* array of instructions (the program) */
extern Inst *code (), *progp;       /* progp is a pointer to an Inst, i.e. a 
                                       pointer to a pointer to a function returning int */

extern      eval (), add (), sub (), dvd (), mul (), neg (), power (), mod ();
extern      assign (), bltin (), varpush (), constpush (), print (); 
extern void gt (), lt (), ge (), le (), eq (), ne (), and (), or (), not ();
extern void add_assign (), sub_assign (), div_assign (), mul_assign (), mod_assign ();    /* += -= *= /= etc */
extern void incr (), decr ();    /* ++, -- */
extern void ifcode (), whilecode (), forcode (), prexpr ();

