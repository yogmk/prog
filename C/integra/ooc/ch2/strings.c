
# include <stdio.h>
# include "new.h"
# include "String.h"


int
main (void)
{
	void *a = new (String, "a");
	void *b = new (String, "b");

	void *aa = clone(a);

	printf ("sizeOf(a) = %u\n", sizeOf(a));
	if (a == aa)
		puts("clone?");

	if (cmpr (a, b))
		puts ("ok");
	
	if (cmpr (a, aa))
		puts ("strings differ?");
	
	delete(a);
	delete(aa);
	delete(b);
	return 0;
}
