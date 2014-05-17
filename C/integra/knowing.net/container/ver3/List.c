# ident "@(#) implemenataion of List Class."

# include <stdlib.h>
# include <stdarg.h>
# include <assert.h>

# include "util.h"
# include "List.h"
# include "List.if"

/**
 *  Selectors
 */

void
add (void *_self, void *_node)
{
	const listclass_t *self = classOf (_self);

	assert (self->_add);
	self->_add (_self, _node);
}

void 
rem (void *_self)
{
	const listclass_t *self = classOf (_self);

	assert (self->_del);
	self->_del (_self);

}

void *
head (void *_self)
{
	const listclass_t *self = classOf (_self);

	assert (self->_head);
	self->_head (_self);

}


int
isEmpty (void *_self)
{
	const listclass_t *self = classOf (_self);

	assert (self->_isEmpty);
	self->_isEmpty (_self);

}


/**
 *  List functions
 */


int
list_isEmpty (void *_self)
{
	list_t *self = _self;
	return self->_head ? 0 : 1;
}

static void *
list_head (void *_self)
{
	const list_t *self = _self;
	return (void*)(self->_head);
}


/* add a new node to the begining of the list.
 * so the list grows backwards
 * List is 'stack' style.
 */

static void
list_add (void *_self, void *_new)
{
	list_t *self = _self;
    node_t *new = _new;

	new->_next = self->_head;
	self->_head = new;

	self->_size += 1;
}


/* remove and destroy head node of the list */
static void
list_del (void *_self)
{
	list_t *self = _self;
    node_t *node = 0x0;
	if (list_isEmpty(self))
	{
		puts ("List is empty!");
		return;
	}
		
	node = self->_head;

	self->_head = (self->_head)->_next; 

	puts ((char*)node->_data);
	node->_next = NULL;
	delete (node);
	puts ("deleted");
	--(self->_size);
}


/**
 *  List: 
 */

static void *
list_ctor (void *_self, va_list *ap)
{
	list_t *self = super_ctor (List, _self, ap);

	assert (self);
	self->_size = 0;
	self->_head = (void*) 0;
	return self;
}

static void *
list_dtor (void *_self)
{
	list_t *self = _self;

	if (!list_isEmpty (self))
	{
		puts ("emptying the List");
		while (self->_head != NULL)
			list_del (self);	
	}
	self = super_dtor (List, _self);

	return self;
}


/**
 * ListClass:
 */

static void *
listclass_ctor (void *_self, va_list *ap)
{
	listclass_t *self = super_ctor (ListClass, _self, ap);

	typedef void (*fnptr) ();               /* generic function pointer */
	fnptr selector, function;

	/* assign function pointers to actual functions */
	while (selector = va_arg(*ap, fnptr))
	{
		function = va_arg (*ap, fnptr);
		if (selector == (fnptr) add)
			*(fnptr*) & self->_add = function;
		else if (selector == (fnptr) rem)
			*(fnptr*) & self->_del = function;
		else if (selector == (fnptr) head)
			*(fnptr*) & self->_head = function;
		else if (selector == (fnptr) isEmpty)
			*(fnptr*) & self->_isEmpty = function;
	}
	return self;

}


/**
 * initialisers
 */

const void *List, *ListClass;


void
initList (void)
{
	if (!ListClass)
		ListClass = new (Class, "ListClass", 
		                 sizeof (listclass_t), Class,
						 ctor, listclass_ctor,
						 (void *) 0);
	if (!List)
		List = new (ListClass, "List",
		            sizeof(list_t), Object,
					ctor, list_ctor,
					dtor, list_dtor,
					add, list_add,
					rem, list_del,
					head, list_head,
					isEmpty, list_isEmpty,
					(void *) 0);
}

