# ident "@(#) implementation of Class A"

# include <assert.h>
# include <stdarg.h>
# include <stdlib.h>

# include "Class.h"
# include "Class.if"
# include "A.h"
# include "A.if"


void *
a_ctor (void *_self, va_list *ap)
{
	struct A *self = _self;
    typedef void (*fnptr) ();
	fnptr foo;
	const char *txt = va_arg (*ap, const char*);

	self->_text = malloc (strlen(txt) + 1);
	assert (self->_text);
	strcpy(self->_text, txt);
	
    if (foo = va_arg (*ap, fnptr)) 
	    self->_display = foo;

	return self;
}


void *
a_dtor (void *_self)
{
	struct A *self = _self;

	assert (self->_text);
	free (self->_text);
	return self;
}


void
a_display (const void *_self)
{
	const struct A *self = _self;

	assert (self->_text);
	puts (self->_text);
}

/* initialise the Class descriptor */

static const struct Class 
_A = {sizeof (struct A), "A", a_ctor, a_dtor};

const void *A = &_A;

