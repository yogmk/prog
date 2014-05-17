/** Shapes.c: implementation of Shape Class */

# include "Shapes.h"

BEGIN_VTABLE (Shape, Object)
	VFUNCTION (Object, destroy) = (void (*)(Object))shape_destroy;
	VFUNCTION (Shape, Area) = (void (*)(Shape))Object_NoImpl;
	IFUNCTION (Scalable, Scale) = (void (*)(Object, double))Object_NoImpl;
END_VTABLE



/** constructor */

Shape 
shape_new (Shape this, char *name)
{
	Object_new (&this->super);                     /* construct base class */
	VHOOK (this, Shape);                           /* hook Shape class */
	IHOOK (this, Shape, Scalable);                 /* hook scalable interface */

	if (! string_new (&this->name, name))
		return NULL;
	return this;
}


/** destructor */

void
shape_destroy (Shape this)
{
	string_destroy (&this->name);                  /* destroy member/s */
	Object_destroy (&this->super);                 /* destroy superclass */
}


/** Rect: */

BEGIN_VTABLE (Rect, Shape)
	VFUNCTION (Shape, Area) = (double (*)(Shape)) rect_area;
	IFUNCTION (super.Scalable, Scale) = (void (*) (Object, double)) rect_scale;
END_VTABLE


Rect
rect_new (Rect this, char *name, double w, double h)
{
	if (! shape_new (&this->super, name))          /* construct super class */
		return NULL;
	VHOOK (this, Rect);                            /* hook Rect Class */
	IHOOK (this, Rect, super.Scalable);            /* hook Scalable interface */
	this->__h = h;
	this->__w = w;

	return this;
}


double
rect_area (Rect this)
{
	return (this->__w * this->__h);
}

void
rect_scale (Rect this, double mag)
{
	this->__w *= mag;
	this->__h *= mag;
}



/** Circle: */

BEGIN_VTABLE (Circle, Shape)
	VFUNCTION (Shape, Area) = (void (*)(Shape)) circle_area;
	IFUNCTION (super.Scalable, Scale) = (void (*) (Object, double)) circle_scale;
END_VTABLE


/** Circle: constructor */

Circle
circle_new (Circle this, char *name, double r)
{
	if (! shape_new (&this->super, name))                /* construct super class */
		return NULL;
	VHOOK (this, Circle);
	IHOOK (this, Circle, super.Scalable);
	this->__r = r;
	return this;
}


double
circle_area (Circle this)
{
	return (3.14 * this->__r * this->__r);
}

void
circle_scale (Circle this, double mag)
{
	this->__r *= mag;
}


