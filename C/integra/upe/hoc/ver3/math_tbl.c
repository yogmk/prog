
# include <math.h>
# include <errno.h>

extern int errno;
double errcheck ();

typedef struct
{
	char *name;                   /* function naem as a string */
	void (*func) ();              /* generic function pointer */
} math_tbl;

const math_tbl [] = 
{
	"log",            log,
	"log10",          log10, 
	"exp",            exp, 
	"sqrt",           sqrt, 
	"exponentiation", pow 
};

double
func_despatch ( math_tbl mt, double x)
{
	return errcheck (mt->func (x), mt->name);
}

double 
Pow (double x, double y)
{
	return errcheck (pow (x, y), "exponentiation");
}

double 
integer (double x)
{
	return (double)(long)x;
}

double
errcheck (double d, char *s)       /* check result of library call */
{
	if (errno == EDOM)
	{
		errno = 0;
		execerror (s, "argument out of domain");
	}
	else if (errno == ERANGE)
	{
		errno = 0;
		execerror (s, "result out of range");
	}
	return d;
}
