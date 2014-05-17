# include <assert.h>
# include <stdlib.h>


# include "Circle.if"
# include "Circle.h"

static void*
circle_ctor (void *_self, va_list *app)
{
	struct Circle *self = super_ctor (Circle, _self, app);

	self->_radius = va_arg (*app, int);
	return self;
}


static void
circle_draw (const void *_self)
{
	const struct Circle *self = _self;

	printf ("circle at %d, %d radius %d\n",
	         ((const struct Point*)(self))->_x,
	         ((const struct Point*)(self))->_y,
			 self->_radius);
}

/**
 *  Initialisation
 */

const void *Circle;

void
initCircle(void)
{
	if (!Circle)
	  {
	  	initPoint();
		Circle = new (PointClass, "Circle",
		              Point, sizeof(struct Circle),
					  _ctor, circle_ctor,
					  draw, circle_draw,
					  0);
	  }
}
