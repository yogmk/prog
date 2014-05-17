# ident "@(#) implmentation of Node Class."

# include <stdlib.h>
# include <stdarg.h>
# include <assert.h>

# include "util.h"
# include "Node.h"
# include "Node.if"

/**
 * selector
 */

void
show (const void *_self)
{
	const nodeclass_t *self = classOf (_self);

	assert (self->_show);
	self->_show (_self);
}

/**
 *  Node:
 */
 
static void *
node_ctor (void *_self, va_list *ap)
{
	node_t *self = super_ctor (Node, _self, ap);
	char *text = va_arg (*ap, char *);

	assert (Node == classOf (self));
	self->_data = malloc (strlen (text) + 1);
	strcpy ((char *)(self->_data), text);

	self->_next = self->_prev = (void *) 0;
	
	return self;
}


static void *
node_dtor (void *_self)
{
	node_t *self = super_dtor (Node, _self);

	assert (self);
	free (self->_data);

	return self;
}

static void
node_show (const void *_self)
{
	const node_t *self = _self;

	assert (self->_data);

	puts ((char *)(self->_data));
}



/**
 *  NodeClass:
 */

static void *
nodeclass_ctor (void *_self, va_list *ap)
{
	nodeclass_t *self = super_ctor (NodeClass, _self, ap);
	typedef void (*fnptr) ();
	fnptr selector, function;

	selector = va_arg (*ap, fnptr);
	function = va_arg (*ap, fnptr);
	
	if (selector == (fnptr) show)
		* (fnptr*) & self->_show = function;

	return self;
}



/**
 *  initialisation
 */

const void *Node, *NodeClass;

void
initNode (void)
{
	if (!NodeClass)
		NodeClass = new (Class, "NodeClass", 
		                 sizeof (nodeclass_t), Class, 
						 ctor, nodeclass_ctor, 
						 (void *)0);
	
	if (!Node)
		Node = new (NodeClass, "Node", 
		            sizeof (node_t), Object, 
					ctor, node_ctor, 
					dtor, node_dtor,
					show, node_show,
					(void *)0);
}
