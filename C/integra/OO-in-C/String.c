/** implementation of String */

# include "String.h"

# include <string.h>
# include <stdlib.h>

BEGIN_VTABLE(String, Object)
	VFUNCTION(Object, destroy) = (void (*)(Object))string_destroy;
END_VTABLE


String
string_new (String this, const char *str)
{
	Object_new (&this->super);                   /* construct superclass */
	VHOOK(this, String);                         /* HOOK on String class */

	/** allocate & set-up the privaet buffer */
	if ((this->__buffer = malloc(strlen(str) + 1)) != NULL)
	  {
	  	strcpy (this->__buffer, str);
		return this;
	  }
	else
	  	return NULL;
}

String
string_new_from_other (String this, String other)
{
	return string_new (this, toChar (other));
}

const char
*toChar (String this)
{
	return this->__buffer;
}

void
string_destroy (String this)
{
	free (this->__buffer);                    /* free private buffer */
	Object_destroy (&this->super);            /* call destructor of super class */
}

