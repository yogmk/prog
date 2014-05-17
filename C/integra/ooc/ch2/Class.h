/**
 *  description of ADT named Class.
 *  This acts as a vtbl for class methods.
 *  All functions here are dynamically bound.
 */

# ifndef _CLASS_

# include <stdarg.h>
# include <stddef.h>

struct Class
  {
  	size_t  _size;                                  /* sizeof Class */
	void * (*_ctor) (void *self, va_list *app);     /** function pointers */
	void * (*_dtor) (void *);               
	void * (*_clone)(void *);
	int    (*_cmpr) (void*, void*);
  };
	

/**
 * Each Object's definition must include above class descriptor
 * as it's first member. e.g.
 * 
 * struct 
 * Point 
 *   {
 *      const void *_class;          // class descriptor
 *      unsigned _x;
 *      unsigned _y;
 *   };
 *
 * and define a variable of 'class descriptor' as ...
 *
 * static const struct Class 
 * _Point = {sizeof (struct Point),               // value of _size
 *           point_ctor,                          // constructor function
 *           point_dtor}                          // destructor function
 *  
 *  const void *Point = &_Point;
 *
 * (This can be automated via pre-processor macros instead of hand coding for each 
 *  new object in the code)
 */

# define _CLASS_
# endif
