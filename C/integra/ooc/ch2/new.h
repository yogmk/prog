
# ifndef _NEW_

# include <stddef.h>

void *new   (const void *class, ...);
void delete (void *object);
void *clone (const void *self);
int  cmpr  (const void *self, const void *other);

size_t sizeOf (const void *self);

# define _NEW_
# endif
