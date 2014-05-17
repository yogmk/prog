# ident "@(#) implemenation of Container class"

# include <assert.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>

# include "util.h"
# include "Class.if"
# include "Container.h"
# include "Container.if"

/**
 * Selector functions
 */

void
add (void *_self, const void *_object)
{
	const struct ContainerClass *self = classOf (_self);

	assert (self && self->_add);
	self->_add (_self, _object);
}


void
del (void *_self, const void *_object)
{
	const struct ContainerClass *self = classOf (_self);

	assert (self && self->_del);
	self->_del (_self, _object);
}


void
typ (const void *_self)
{
	const struct ContainerClass *self = classOf (_self);

	assert (self && self->_typ);
	self->_typ (_self);
}

static void *
container_ctor (void *_self, va_list *app)
{
	struct Container *contnr = super_ctor (Container, _self, app);

	contnr->_count = 0;
	contnr->_obj_class = 0;
	contnr->_list = 0;

	return contnr;
}


static void *
container_dtor (void *_self)
{
	/* constructor does not acquire any resources,
	 * so nothing special to be done here, just toss back
	 */
	return _self;
}


static int
container_add (void *_self, const void *object)
{
	struct Container *self = _self;

	if (self->_count == 0)            /* container empty, any type can be added */
	{
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
container_del (const void *_self, const void *object)
{
	const struct Container *self = _self;

	/* if object exists, remove it.  */
	
	return 0;
}


/* return the Class of object/s 
 * container currently holds 
 */

static const struct Class *
container_obj_class (const void *_self)
{
	const struct Container *self = _self;

	assert (self->_obj_class);
	return self->_obj_class;
}


/**
 *  ContainerClass:
 */

void *
containerclass_ctor (void *_self, va_list *ap) 
{
	struct ContainerClass *self = super_ctor (ContainerClass, _self, ap);

	typedef void (*fnptr) ();               /* generic function pointer */
	fnptr selector, function;

	/* assign function pointers to actual functions */
	while (selector = va_arg(*ap, fnptr))
	{
		function = va_arg (*ap, fnptr);
		if (selector == (fnptr) add)
			*(fnptr*) & self->_add = function;
		else if (selector == (fnptr) del)
			*(fnptr*) & self->_del = function;
		else if (selector == (fnptr) typ)
			*(fnptr*) & self->_typ = function;
	}
	return self;
}

/** 
 *  Class description / vtble initialiser
 */

const void *Container, *ContainerClass;

void 
initCont (void)

{
	if (!ContainerClass)
	{	
		puts ("class ContainerClass");
	  	ContainerClass = new (Class, "ContainerClass", \
		                      sizeof(struct ContainerClass), Class, \
							  ctor, containerclass_ctor, 0);
	}
							  
	if (!Container)
	{
		puts ("class Container");
		Container = new (ContainerClass, "Container", \
		                 sizeof (struct Container), Object, \
						 ctor, container_ctor, \
						 dtor, container_dtor, \
						 add, container_add, 
						 del, container_del,
						 typ, container_obj_class,
						 0);
	}
}
