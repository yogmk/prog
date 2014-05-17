# ident "@(#) implementation of Class B"

# include <assert.h>
# include <stdarg.h>
# include <stdlib.h>

# include "util.h"
# include "B.h"
# include "B.if"


void *
b_ctor (void *_self, va_list *ap)
{
	struct B *self = super_ctor (B, _self, ap);

	const char *txt = va_arg (*ap, const char*);

	self->_btxt = malloc (strlen(txt) + 1);
	assert (self->_btxt);
	strcpy(self->_btxt, txt);
	
	return self;
}


void *
b_dtor (void *_self)
{
	struct B *self = super_dtor (B, _self);

	assert (self->_btxt);
	free (self->_btxt);
	return self;
}


/**
 * BClass:
 */

void *
bclass_ctor (void *_self, va_list *ap)
{
	struct BClass *self = super_ctor (BClass, _self, ap);
    
	/* assign function pointers to actual functions 

    typedef void (*fnptr) ();
	fnptr selector, function;

	while (selector = va_arg(*ap, fnptr))
	{
		function = va_arg (*ap, fnptr);
		if (selector == (fnptr) disp)
			*(fnptr*) & self->_display = function;
	}*/
	return self;
}


/**
 * Class description/vtbl initialiser 
 */

const void *B, *BClass;

void
initB (void)
{

	if (!BClass)
	{
		puts ("class BClass");
	  	BClass = new (Class, "BClass", 
		              sizeof(struct BClass), AClass, 
					  ctor, bclass_ctor, 
					  0);
	}
					  
	if (!B)
	{
		puts ("class B");
		B = new (BClass, "B", 
		         sizeof (struct B), A, 
				 ctor, b_ctor, dtor, b_dtor, 
				 0);
	}
}


