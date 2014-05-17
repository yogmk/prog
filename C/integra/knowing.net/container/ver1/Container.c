# ident "@(#) implemenation of Container class"

# include <assert.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>

# include "Container.h"
# include "Container.if"
# include "Class.h"
# include "Class.if"

void *
container_ctor (void *_self, va_list *app)
{
	struct Container *contnr = _self;

	typedef void (*fnptr) ();               /* generic function pointer */
	fnptr foo, bar;
	va_list ap = *app;

	contnr->_count = 0;
	contnr->_obj_class = 0;
	contnr->_list = 0;

	/* assign function pointers to actual functions */
	* (fnptr*) & contnr->_add = va_arg (ap, fnptr);
//	contnr->_del = va_arg (ap, fnptr);
//	contnr->_typ = va_arg (ap, fnptr);

	return contnr;
}


void *
container_dtor (void *_self)
{
	/* constructor does not acquire any resources,
	 * so nothing special to be done here, just toss back
	 */
	return _self;
}


int
container_add (void *_self, void *object)
{
	struct Container *self = _self;

	if (self->_count == 0)
	{
	  	/* container is still empty, any type can be added */
		self->_obj_class = classOf (object);
		printf ("object of class %s added.\n", (self->_obj_class)->_name);
		++(self->_count);
	}
	else
	{
		/*  Before adding, Container needs to verify
	  	 *  whether the object is compatible.
	 	 */
	
	  	if (self->_obj_class == classOf (object))
		{
		  	/* add() */
			puts ("object can be added");
		}
		else
		{
		  	puts("error: can't add object of different type to container");
		}
	}
}

/* delete an object from the container
 * -not- delete the container itself
 */

static int
container_del (void *_self, void *object)
{
	const struct Container *self = _self;

	/*
	 * before removing, find out whether that object
	 * exists in the container.
	 */
	
	return 0;
}


/* return the '_type' of object/s 
 * container currently holds 
 */

static const struct Class *
container_obj_class (void *_self)
{
	const struct Container *self = _self;

	assert (self->_obj_class);
	return self->_obj_class;
}


static const struct Class 
_Container = {sizeof (struct Container), "Container", container_ctor, container_dtor};

const void *Container = &_Container;    /* passed to new (Container, ..) */


