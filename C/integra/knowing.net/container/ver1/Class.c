# ident "@(#) implementation of Class interface"


# include <stdlib.h>
# include <assert.h>
# include <stdarg.h>

# include "Class.if"
# include "Class.h"

void *
new (const void *_class, ...)
{
	const struct Class *class = _class;
	void *object;
	va_list ap;

	object = calloc(1, class->_size);
	assert (object);

                               /* make object point to class description */
	*(const struct Class**)object = class;       /* read: *object=class; */
    
	if (class->_ctor)
	  {
	  	va_start (ap, _class);
		object = class -> _ctor (object, &ap);
	    va_end (ap);
	  }
	return object;
}


void 
delete (void *_self)
{
	const struct Class **object = _self;

	assert (object && (*object) && (*object)->_dtor);
	_self = (*object)->_dtor (_self);
	free (_self);
}


const struct Class*
classOf (const void *_object)
{

  /* we receive only a void pointer to struct guess the type.
   * address of struct and address of first member of struct 
   * are same.
   * First member of any object in our application is a pointer
   * to it's Class description.
   * So instead of typecasting pointer to the struct (of 
   * unknown type), typecast it to it's first member (always
   * known to be of struct Class)
   */

	const struct Class **voidp = _object;
  	return  (const struct Class*) (*voidp);
}


