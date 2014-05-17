# include "Class.h"
# include "Class.if"
# include "Container.h"
# include "Container.if"
# include "A.h"
# include "A.if"


int
main (void)
{
	struct Container *c = new (Container, container_add);

    struct A *a = new (A, "some text", a_display);
    struct A *aa = new (A, "some more text", a_display);

	const struct Class *k = classOf(c);
	printf("The class of object c is %s\n", k->_name);

	c->_add (c, a);
	c->_add (c, aa);


	a->_display(a);
	aa->_display(aa);

	delete(a);
	delete(aa);
	delete (c);

	return 0;
}
