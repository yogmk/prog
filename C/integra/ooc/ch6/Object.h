/**
 *  Public interface methods declaration for Object
 */

# ifndef _OBJECT_H_

# include <stdio.h>
# include <stdarg.h>

extern const void *Object;          /* new (Object, ...) */
extern const void *Class;           /* new (Class, ...) */

void *new (const void *, ...);
void delete (void *);

void *_ctor (void *, va_list *);
void *_dtor (void *);

int differ (const void *, const void *);
int put_o (const void *, FILE *);

const void *classOf (const void *);
size_t sizeOf (const void *);

const void *class_super (const void *);

# define _OBJECT_H_
# endif

