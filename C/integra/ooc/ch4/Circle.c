/**
 *  implementation of Circle's methods
 */

# include <assert.h>
# include <stdlib.h>
# include <stdarg.h>

# include "Class.h"
# include "new.h"
# include "Circle.if"
# include "Circle.h"

static void *
circle_ctor (void *_self, va_list *app)
{
	struct Circle *self = 
	((const struct Class*)Point) -> _ctor (_self, app);
    
	self->rd = va_arg (*app, int);
	return self;
}

static void *
circle_dtor (void *_self)
{
	/* nothing to be done */
	return _self;
}

static void
circle_draw (const void *_self)
{
	const struct Circle *self = _self;

	printf ("circle at %d, %d rad %d\n",
	         ((const struct Point *)self) ->x,
	         ((const struct Point *)self) ->y,
			 self->rd);
}


static const struct Class _Circle = 
  { sizeof (struct Circle), circle_ctor, circle_dtor, circle_draw
  };

/**
 *  alternatively ...
    static const struct Class _Circle;
    _Circle._size = sizeof (struct Circle);
    _Circle._ctor = circle_ctor;
    _Circle._dtor = circle_dtor;
    _Circle._draw = circle_draw;
 */

const void *Circle = &_Circle;

