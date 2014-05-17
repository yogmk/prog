# ident "@(#) implementation of Class A"

# include <assert.h>
# include <stdarg.h>
# include <stdlib.h>

# include "util.h"
# include "Class.if"
# include "A.h"
# include "A.if"


void
disp (const void *_self)
{
	const struct AClass *self = classOf (_self);

	assert (self && self->_disp);
	self->_disp(_self);
}

void *
a_ctor (void *_self, va_list *ap)
{
	struct A *self = super_ctor (A, _self, ap);

	const char *txt = va_arg (*ap, const char*);

	self->_text = malloc (strlen(txt) + 1);
	assert (self->_text);
	strcpy(self->_text, txt);
	
	return self;
}


void *
a_dtor (void *_self)
{
	struct A *self = super_dtor (A, _self);

	assert (self->_text);
	free (self->_text);
	return self;
}


void
a_disp (const void *_self)
{
	const struct A *self = _self;

	assert (self->_text);
	puts (self->_text);
}

/**
 * AClass:
 */

void *
aclass_ctor (void *_self, va_list *ap)
{
	struct AClass *self = super_ctor (AClass, _self, ap);
    
    typedef void (*fnptr) ();
	fnptr selector, function;

	/* assign function pointers to actual functions */
	while (selector = va_arg(*ap, fnptr))
	{
		function = va_arg (*ap, fnptr);
		if (selector == (fnptr) disp)
			*(fnptr*) & self->_disp = function;
	}
	return self;
}

void *
aclass_dtor (void *_self)
{
	struct AClass *self = super_dtor (AClass, _self);
	return self;
}

/**
 * Class description/vtbl initialiser 
 */

const void *A, *AClass;


void
initA (void)
{

	if (!AClass)
	{
		puts ("class AClass");
	  	AClass = new (Class, "AClass", \
		              sizeof(struct AClass), Class, \
					  ctor, aclass_ctor, \
					  dtor, aclass_dtor, 0);
	}
					  
	if (!A)
	{
		puts ("class A");
		A = new (AClass, "A", \
		         sizeof (struct A), Object, \
				 ctor, a_ctor, \
				 dtor, a_dtor, \
				 disp, a_disp, 0);
	}
}
