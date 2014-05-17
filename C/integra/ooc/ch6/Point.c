# include <assert.h>

# include "Point.h"
# include "Point.if"

/**
 *  Point:
 */

static void *
point_ctor (void *_self, va_list *app)
{
	struct Point *self;

	self = super_ctor (Point, _self, app);

	self->_x = va_arg (*app, int);
	self->_y = va_arg (*app, int);
	return self;
}

/* point_ctor () does nopt acquire any resources,
 * Hence corrosponding _dtor () is not needed 
 */


static void 
point_draw (const void * _self)
{	const struct Point * self = _self;

	printf("\".\" at %d,%d\n", self ->_x, self ->_y);
}

void
draw (const void *_self)
{
	const struct PointClass *pc = classOf(_self);
	
    assert (pc->_draw);
    pc->_draw (_self);
}

void 
super_draw (const void * _class, const void * _self)
{	const struct PointClass *sc = class_super(_class);

	assert(_self && sc -> _draw);
	sc -> _draw(_self);
}

void 
move (void * _self, int dx, int dy)
{	struct Point * self = _self;

	self -> _x += dx, self -> _y += dy;
}


/**
 *  PointClass:
 */

static void *
pointclass_ctor (void *_self, va_list *app)
{
	struct PointClass *pc = super_ctor (PointClass, _self, app);
	typedef void (*fnptr) ();
	fnptr selector;

	va_list ap = *app;

	while (selector = va_arg (ap, fnptr))
	  {
	  	fnptr method = va_arg (ap, fnptr);

		if (selector == (fnptr) draw)
			* (fnptr*) & pc->_draw = method;
	  }
	return pc;
}

/**
 *  Initialisation
 */

const void *PointClass, *Point;

void
initPoint (void)
{
	if (!PointClass)
		PointClass = new (Class, "PointClass", Class,
					sizeof (struct PointClass),
					_ctor, pointclass_ctor,
					0);
	if (!Point)
		Point = new (PointClass, "Point", Object,
					sizeof (struct Point),
					_ctor, point_ctor,
					draw, point_draw,
					0);
}
