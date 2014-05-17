# include <stdarg.h>
# include <stdio.h>

# include "util.h"
# include "Class.if"
# include "Container.h"
# include "Container.if"
# include "Node.h"
# include "Node.if"
# include "List.h"
# include "List.if"

void init (void);

int
main (void)
{
	init ();
	list_t *ll = new (List);

	node_t *n1 = new (Node, "Node 1");
	node_t *n2 = new (Node, "Node 2");
	node_t *n3 = new (Node, "Node 3");
	node_t *n4 = new (Node, "Node 4");

	add (ll, n1);
	add (ll, n2);
	add (ll, n3);
	add (ll, n4);

	rem (ll);
	rem (ll);
	rem (ll);
	rem (ll);
	rem (ll);
	delete (ll);

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
	initList ();
	initNode ();
}
