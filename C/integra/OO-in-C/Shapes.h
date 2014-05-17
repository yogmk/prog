
# ifndef __SHAPES__

# include "Object.h"
# include "String.h"

/** Interface Scalable */
INTERFACE (Scalable)
 	void (*Scale)(Object, double);
END_INTERFACE


/** Class Shape: extends Object, implements Scalable */

CLASS (Shape, Object) IMPLEMENTS (Scalable);
	struct String name;                           /* public: shape's name */
VTABLE (Shape, Object) EXTENDS (Scalable);
	double (*Area)(Shape);                        /* pure virtual! */
FUNCTIONS
  	Shape shape_new (Shape this, char *name);     /* constructor */
	void  shape_destroy (Shape this);             /* destructor  */
END_CLASS



/** Class Rect: extends Shape */

CLASS (Rect, Shape)
	double __w;                                  /* private: width */
	double __h;                                  /* private: height */
VTABLE (Rect, Shape)
FUNCTIONS
	Rect rect_new (Rect this, char *name, double w, double h);
	double rect_area (Rect this);
	void rect_scale (Rect this, double mag);
END_CLASS


/** Class Circle: extends Shape */

CLASS (Circle, Shape)
	double __r;                                 /* private: radius */
VTABLE (Circle, Shape)
FUNCTIONS
	Circle circle_new (Circle this, char *name, double r);
	double circle_area (Circle this);
	void circle_scale (Circle this, double mag);
END_CLASS

# define __SHAPES__
# endif
