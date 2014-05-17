/**
 *  'new' acts like a (pseudo) keyword.
 *  It is *not* a constructor, (but a (pseudo) keyword),
 *  which calls the constructor.
 */


# include <stdlib.h>
# include <stdarg.h>
# include <assert.h>

# include "Class.h"
# include "new.h"

void *
new (const void *_class, ...)
{
	const struct Class *class = _class;
	void *p = calloc (1, class->_size);
	va_list ap;

	assert (p);

	* (const struct Class **)p = class;
	if (class -> _ctor)
	  {
	  	va_start (ap, _class);
		p = class -> _ctor (p, &ap);                     /* call constructor */
		va_end (ap);
	  }
	
	return p;
}

void
delete (void *self)
{
	const struct Class **p = self;

	if (self && *p && (*p)->_dtor)
		self = (*p)->_dtor(self);

	free (self);
}


void *
clone (const void *self)
{
	const struct Class *const *p = self;

	assert (self && (*p) && (*p) -> _clone);
	return (*p)->_clone (self);
}

int
cmpr (const void *self, const void *other)
{
	const struct Class* const* p = self;

	assert (self && (*p) && (*p)->_cmpr);
	return (*p)->_cmpr (self, other);
}

size_t
sizeOf (const void *object)
{
	const struct Class *const *p = object;	
	assert (object && (*p));
	return (*p)->_size;
}
