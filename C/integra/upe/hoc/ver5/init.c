# include <math.h>

# include "hoc.h"
# include "y.tab.h"

extern double Log(), Log10(), Exp(), Sqrt(), integer(), Rand ();

/**
 * constants 
 */

static const struct
{
    char *name;
    double cval;
} consts[] = 
            {
                "PI",      3.14159265358979323846,
                "E",       2.71828182845904523536,
                "GAMMA",   0.57721566490153286060,       /* Euler */
                "DEG",     57.29577951308232087680,      /* deg/radian */
                "PHI",     1.61803398874989484820,       /* golden ratio */
                0,         0
            };

/**
 *  built-ins 
 */

static const struct
{
    char *name;
    double (*func) ();
} builtins [] = 
            {
                "sin",     sin,
                "cos",     cos,
                "atan",    atan,
                "log",     Log,          /* checks arguments */
                "log10",   Log10,        /* checks arguments */
                "exp",     Exp,          /* checks arguments */
                "sqrt",    Sqrt,         /* checks arguments */
                "rand",    Rand,
                "int",     integer,
                "abs",     fabs,
                "atan2",   atan2,
                0,         0
            };

/**
 * keywords
 */

static const struct
{
     char *name;
     int kval;
} keywords [] = {
                "if",       IF,
                "else",     ELSE,
                "while",    WHILE,
                "print",    PRINT,
                0,          0
                };
      

/*
 * Boot-strap the data structures
 * constants, built-ins and keywords.
 */

void
init (void)
{
    int i;
    Symbol *s;


    for (i=0; consts[i].name; i++)
        install (consts[i].name, CONST, consts[i].cval);
    
    for (i=0; builtins[i].name; i++)
    {
        s = install (builtins[i].name, BLTIN, 0.0);
        s->u.ptr = builtins[i].func;
    }

    for (i=0; keywords[i].name; i++)
        install (keywords[i].name, keywords[i].kval, 0.0);
}
