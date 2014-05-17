# ifndef _CLASS_H_


/**
 * Following are the known classes to our application

enum class_values { Invalid = 0x0, Container = 0x1, Aa, Bb};
const char * const class_names [] = {"Invalid", "Container", "Aa", "Bb"};
 */

/**
 *  prototypes declaration of object management functions
 */

void *new (const void *, ...);
void delete (void *);

const struct Class *classOf (const void *_object);

# define _CLASS_H_
# endif

