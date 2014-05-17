# ident "@(#) implementation of Object Management functions."


# include <stdlib.h>
# include <assert.h>
# include <stdarg.h>

# include "Class.if"
# include "util.h"

/* # define sizeOf(object) ((size_t)(((const struct Class*)object)->_size))  */


/**
 *  new(), delete(), classOf(), super() etc..
 */

void *
new (const void *_class, ...)
{
	const struct Class *class = _class;
	struct Object *object;
	va_list ap;

    assert (class && class->_size);
	object = calloc(1, class->_size);
	assert (object);

                               /* compare this line with ver1 */ 
	object->_vtbl = class;     /* make Object's vtbl ptr point to class description */  
    
	va_start (ap, _class);
	object = ctor (object, &ap);
	va_end (ap);

	return object;
}


void 
delete (void *_self)
{
	if (_self)
	free (dtor(_self));
}


void *
super (const void *_self)
{
	const struct Class *self = _self;

	assert (self && self->_super);
	return (void*) self->_super;
}


const void*
classOf (const void *_object)                /* can we turn this into a macro? */
{

  /* we receive only a void pointer to struct guess the type.
   * address of struct and address of first member of struct 
   * are same.
   * since all objects inherit struct Object as the first membet,
   * so instead of typecasting pointer to the struct (of 
   * unknown type), typecast it to it's first member (always
   * known to be of struct Object), which is/has a pointer to 
   * its Class description.
   */

	const struct Object *voidp = _object;
	return (voidp->_vtbl);
}


size_t
sizeOf (const void *_self)
{
	const struct Class *self = classOf(_self);
	return self->_size;
}



/**
 * function despatcher for constructor/destructor
 * for objects
 */

void *
ctor (void *_self, va_list *ap)
{
	const struct Class *klass = classOf (_self);

	assert (klass->_ctor);
	return klass->_ctor (_self, ap);
}

void *
dtor (void *_self)
{
	const struct Class *klass = classOf (_self);

	assert (klass->_dtor);
	return klass->_dtor (_self);
}



/**
 * super-class functions' despatchers
 */

void *
super_ctor (const void *_class, void *_self, va_list *ap)
{
	const struct Class *superclass = super (_class);

	assert (_self && superclass->_ctor);
	return superclass->_ctor (_self, ap);
}


void *
super_dtor (const void *_class, void *_self)
{

	const struct Class *superclass = super (_class);

	assert (_self && superclass->_dtor);
	return superclass->_dtor (_self);
}

/**
 *  Object:
 */

static void *
object_ctor (void *_self, va_list *ap)
{
	return _self;
}


static void *
object_dtor (void *_self)
{
	return _self;
}

/**
 *  Class:
 */
 
static void *
class_ctor (void *_self, va_list *ap)
{
	struct Class *self = _self;
	const size_t offset = offsetof(struct Class, _ctor);

    typedef void (*fooptr) ();                     /* generic function pointer */
    fooptr selector, function;
	va_list app; 

	self->_name = va_arg (*ap, char *);
	self->_size = va_arg (*ap, size_t);
	self->_super = va_arg (*ap, struct Class*);

	assert(self->_super);

	/* binary inheritance. Copy function pointers from 
	   super-class to self.
	*/
	memcpy ((char*) self + offset,                  /* target */
	        (char*) self->_super + offset,          /* source */
		sizeOf(self->_super) - offset);         /* no of bytes */

    /* user will pass selector, function in pairs in new () */
	app = *ap;
    while (selector = va_arg (app, fooptr))
	{
		function = va_arg (app, fooptr);
		if (selector == (fooptr) ctor)
		   *(fooptr*) & self->_ctor = function;
		else if (selector == (fooptr) dtor)
		   *(fooptr*) & self->_dtor = function;
	}
    return self;
}


static void *
class_dtor (void *_self)
{
	printf ("Cannot destroy data-type 'Class %s'\n", \
	        ((const struct Class*)_self)->_name);
	return 0;
}


/**
 * Initialiser (Boot-strap)
 * Only here, Object's class description is Class (array+1),
 * and Class's own class description is also Class (array+1)
 */

static const struct Class 
object [] = {
  {{object+1}, "Object", sizeof (struct Object), object, object_ctor, object_dtor},
  {{object+1}, "Class", sizeof (struct Class), object, class_ctor, class_dtor}
};

const void *Object = object;
const void *Class = object+1;

