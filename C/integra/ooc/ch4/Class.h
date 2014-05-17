# ifndef _CLASS_

# include <stdarg.h>

struct Class
  {
  	size_t  _size;
	void * (*_ctor) (void *self, va_list *app);
	void * (*_dtor) (void *self);
	void (*_draw) (const void *self);
  };

# define _CLASS_
# endif

