/**
 *  Implementation of methods belonging to Point 'Class'
 */

# include <stdlib.h>
# include <stdarg.h>
# include <assert.h>

# include "Class.h"
# include "new.h"
# include "Point.if"
# include "Point.h"

void *
point_ctor (void *_self, va_list *app)
{
	struct Point *self = _self;

    self->x = va_arg (*app, int);	
    self->y = va_arg (*app, int);	

	return self;
}


void *
point_dtor (void *_self)
{
	/**
	 * we didn't acquire any memory in constructor,
	 * so nothing needs to be done in _dtor
	 */
	 return _self;
}

static void
point_draw (const void *_self)
{
	const struct Point *self = _self;

	printf ("\".\" at %d,%d\n", self -> x, self -> y);
}

static const struct Class _Point = 
 {
   sizeof (struct Point),
   point_ctor,
   point_dtor,
   point_draw
 };

const void *Point = &_Point;

void
move (void *_self, int dx, int dy)
{
	struct Point *self = _self;

	self->x += dx;
	self->y += dy;
}
