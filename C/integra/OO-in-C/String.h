# ifndef __STRING__

# include "Object.h"

CLASS(String, Object)                   /* class String extends Object */
   char *__buffer;                      /* private character buffer    */
VTABLE(String, Object)
FUNCTIONS
   /** public: constructors */
   String string_new (String this, const char *str);
   String string_new_from_other (String this, String other);

   /** public: destructor */
   void string_destroy (String this);

   /* public: to char conversion */
   const char *toChar (String this);
END_CLASS

# define __STRING__
# endif
