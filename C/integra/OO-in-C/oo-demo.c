# include "Shapes.h"

# include <stdio.h>
# include <assert.h>

void 
testShape (Shape s)
{
	assert(IS_RUNTIME_CLASS (s, Shape));
	printf ("Shape.name = %s, Shape.Area() = %.2f\n",\
	         toChar (&s->name),                        /* static binding */
			 VCALL(s, Shape, Area)END_CALL             /* dynamic binding */
			 );
}


void
testScalable (Scalable s)
{
	assert(IS_RUNTIME_CLASS(I_TO_OBJ(s), Object));
	puts ("Scalable.Scale (), ");
	ICALL (s, Scale) , 2.0 END_CALL;                   /* dynamic binding */

}


# define NRECT 10

int
main (void)
{
	struct Circle cir;                                 /* cir instance of Stack frame */
	Circle c;
	Rect r;
	int i;

	c = circle_new (&cir, "circle", 0.5);
	r = ALLOC_ARR (Rect, NRECT);
	for (i=0; i < NRECT; i++)
	  {
	  	char name[20];
		sprintf (name, "rectangle-%d", i);             /* prepare the name */
		rect_new (&r[i], name, (double) i, 0.5);       /* construct a rect */
	  }

	/* test each object ... */
	testScalable (&c->super.Scalable);
	testShape ((Shape) c);
	for (i=0; i < NRECT; i++)
	  {
	  	testScalable (&r[i].super.Scalable);
		testShape ((Shape) &r[i]);
	  }

	/* destroy ... */
	VCALL (c, Object, destroy)END_CALL;               /* dynamic binding */
	FREE_ARR (r);
	return 0;
}

