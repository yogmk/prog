# include <stdlib.h>
# include <assert.h>
# include <stdarg.h>

# include "Class.h"
# include "String.h"

struct String
  {
  	void *class;                    /* descriptor (always first member of any ADT */
	char *text;
  };


static void*
string_ctor (void *_self, va_list *app)
  {
  	struct String *self = _self;

	const char *text = va_arg (*app, const char*);     /* va_start already done in new() */

	self->text = malloc (strlen (text)+1);
	assert (self->text);
	strcpy (self->text, text);

	return self;
  }


void *
string_dtor (void *_self)
  {
  	struct String *self = _self;

	assert (self);
	free (self->text);
	self->text = 0;
	return self;
  }


void *
string_clone (const void *_self)
  {
  	struct String *self = _self;
	assert (self);
	return new (String, self->text);
  }

static int
string_cmpr (const void *_self, const void *_other)
  {
  	const struct String *self = _self;
  	const struct String *other = _other;

	if (self == other)
		return 0;

	if (!other || other->class != String)
		return 1;

	return strcmp (self->text, other->text);
  }


static const struct Class 
_String = {sizeof(struct String), string_ctor, string_dtor, string_clone, string_cmpr};

const void *String = &_String;                  /* for new(String, ...) */

