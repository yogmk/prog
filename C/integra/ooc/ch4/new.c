
/**
 *  Implementation of ADT Class.
 */

# include <stdlib.h>
# include <assert.h>

# include "Class.h"
# include "new.h"

void *
new (void *_class, ...)
{
	va_list ap;
	void *p = 0x0;
	const struct Class *class = 0x0;

	class = _class;
	p = calloc (1, class->_size);

	assert (p);

	*(const struct Class **)p = class;

	if (class->_ctor)
	  {
	  	va_start (ap, _class);
		p = class->_ctor (p, &ap);
		va_end (ap);
	  }
	return p;
}
		

void
delete (void *_self)
{
	const struct Class **p = 0x0;

	p = _self;
	if ((*p)->_dtor)
		_self = (*p)->_dtor(_self);
	
	free (_self);
}


void
draw (const void *_self)
{
	const struct Class* const* p = _self;

	if (_self && (*p) && (*p)->_draw)
		(*p)->_draw (_self);
	
}
