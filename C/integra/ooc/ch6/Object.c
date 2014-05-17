/**
 *  Implementation of Object & Class functions
 */

# include <stdarg.h>
# include <assert.h>
# include <stdlib.h>
# include <stdio.h>
# include <linux/stddef.h>

# include "Object.if"
# include "Object.h"


/**
 *   Object:
 */

static void *
object_ctor (void *_self, va_list *app)
{
	return _self;
}

static void *
object_dtor (void *_self)
{
	return _self;
}

static int
object_differ (const void *_self, const void *_other)
{
	return (_self != _other);
}

static int
object_put_o (const void *_self, FILE *fp)
{
	const struct Class *class = classOf (_self);

	return fprintf (fp, "%s at %p\n", class->_name, _self);
}

const void *
classOf (const void *_self)
{
	const struct Object *self;
	self = _self;
	
	assert (self && self->_class);
	return self->_class;
}

size_t
sizeOf (const void *_self)
{
	const struct Class *class = classOf (_self);
	
	assert (class);
	return (class->_size);
}



/**
 *  Class:
 */


static void*
class_dtor (void *_self, ...)
{
	struct Class *self = _self;
	
	fprintf (stderr, "%s: Cannot destroy Class\n", self->_name);
	return 0;
}


const void*
class_super (const void *_self)
{
	const struct Class *self = _self;

	assert (self && self->_super);
	return (self->_super);
}


static void *
class_ctor (void *_self, va_list *app)
{
	struct Class *self = _self;
	const size_t offset = offsetof(struct Class, _ctor);

	self->_name = va_arg (*app, char *);
	self->_super= va_arg (*app, struct Class*);
	self->_size = va_arg (*app, size_t);

	assert (self->_super);                   /* confirm that super class is not 0 */

	/**
	 *  Time for Inheritance.
	 *  Copy all methods from super class to self.
	 *  We've arranged _ctor to be first method in Class description.
	 *  and also got it's offset above.
	 *  Using memcpy, we'll copy all methods into self.
	 */

	memcpy ((char*) self + offset,                 /* target */
	        (char*) self->_super + offset,         /* source */
			sizeOf (self->_super) - offset);       /* how many bytes */
	
	/**
	 *  connect function pointers in
	 *  Class description to functions.
	 *  
	 *  It is programmer's responsibility to pass
	 *  selector/funtion pairs properly.
	 */

	 {
	 typedef void (*fnptr) ();         /* generic function pointer */
	 fnptr selector;
	 va_list ap = *app;

	 while ((selector = va_arg (ap, fnptr)))
	   {
	   	fnptr foo = va_arg (ap, fnptr);
		if (selector == (fnptr) _ctor)
			*(fnptr*) & self->_ctor = foo;    /* mind you, & is not logical, but addressof */
		else if (selector == (fnptr) _dtor)
			*(fnptr*) & self->_dtor = foo;
		else if (selector == (fnptr) differ)
			*(fnptr*) & self->_differ = foo;
		else if (selector == (fnptr) put_o)
			*(fnptr*) & self->_put_o = foo;
	   }
	 }
	 return self;
}


/**
 *  initialisation: refer struct Class in Class.if
 */

static const struct Class object[] = 
 { 
   {                                                    /* class desc of Object */
   {object + 1}, "Object", object, sizeof (struct Object),
   object_ctor, object_dtor, object_differ, object_put_o 
   },
   {                                                    /* class desc of Class */
   {object + 1}, "Class", object, sizeof (struct Class),
   class_ctor, class_dtor, object_differ, object_put_o
   }
 };
   

const void *Object = object;
const void *Class = object + 1;


/**
 *  Object management & super-class functions
 */

void *
new (const void *_class, ...)
{
	struct Object *object;
	va_list ap;
	const struct Class *class = _class;

	assert (class && class->_size);
	object = calloc (1, class->_size);
	assert (object);
	object->_class = class;
	va_start (ap, _class);
	object = _ctor (object, &ap);
	va_end (ap);

	return object;
}

void
delete (void *_self)
{
	if (_self)
		free (_dtor(_self));
}


void *
_ctor (void *_self, va_list *app)
{
	const struct Class *class = classOf (_self);

	assert (class && class->_ctor);
	return class->_ctor (_self, app);
}


void *
_dtor (void *_self)
{
	const struct Class *class = classOf (_self);

	assert (class->_dtor);
	return class->_dtor (_self);
}


void *
super_ctor (const void *_class, void *_self, va_list *app)
{
	const struct Class *superclass = class_super(_class);
	assert (_self && superclass->_ctor);
	return superclass->_ctor(_self, app);
}

void *
super_dtor (const void *_class, void *_self)
{
	const struct Class *superclass = class_super (_class);

	assert (_self && superclass->_dtor);
	return superclass->_dtor (_self);
}


int differ (const void * _self, const void * b)
{	const struct Class * class = classOf(_self);

	assert(class ->_differ);
	return class ->_differ(_self, b);
}

int super_differ (const void * _class, const void * _self, const void * b)
{	const struct Class * superclass = class_super(_class);

	assert(_self && superclass ->_differ);
	return superclass ->_differ(_self, b);
}

int put_o (const void * _self, FILE * fp)
{	const struct Class * class = classOf(_self);

	assert(class -> _put_o);
	return class -> _put_o(_self, fp);
}

int super_put_o (const void * _class, const void * _self, FILE * fp)
{	const struct Class * superclass = class_super(_class);

	assert(_self && superclass -> _put_o);
	return superclass -> _put_o(_self, fp);
}

