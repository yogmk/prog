# include <stdarg.h>
# include <stdio.h>

# include "util.h"
# include "Class.if"
# include "Container.h"
# include "Container.if"
# include "A.h"
# include "A.if"
# include "B.h"
# include "B.if"

void init (void);

int
main (void)
{
	init ();
	struct Container *c = new (Container);

    struct A *a = new (A, "some text");
    struct A *aa = new (A, "some more text");
    struct B *b = new (B, "B-tex");

	const struct Class *k = classOf(c);
	printf("The class of object c is %s\n", k->_name);

	add (c, a);
	add (c, aa);
	add (c, b);

	disp (a);
	disp (aa);
	disp (b);

	delete (a);
	delete (aa);
	delete (c);
	delete (b);

	return 0;
}


/**
 * initialise the classes, so that they can be instantiated in main app..
 * Note that 'Object' and 'Class' are already 'bootstrapped' inside util.c
 *
 * Also note that 'A' is not an object of class 'AClass', rather both are
 * objects of Object and Class resp.. They serve as class descriptions for 
 * objects in our application. They are singleton classes, i.e. only one 
 * instance exists at any time during application life.
 *
 */

void
init (void)

{
	initCont ();
	initA ();
	initB ();
}
