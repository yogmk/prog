# ifndef _CLASS_H_

/**
 *  prototypes declaration of Object Management functions
 */

const void *Object;
const void *Class;

void *new (const void *, ...);
void delete (void *);
void *super (const void *);

const void *classOf (const void *_object);
size_t sizeOf (const void *);

/*
void *class_ctor (void *, va_list *);
void *class_dtor (void *);
*/

/* despatcher function for constructor/destructor for objects called from new() */

void * ctor (void *, va_list *ap);
void * dtor (void *);


/* is this the right place to declare these?  */

void *super_ctor (const void *class, void *_self, va_list *app);   /* call super->ctor */
void *super_dtor (const void *class, void *_self);

# define _CLASS_H_
# endif

