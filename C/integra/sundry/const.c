/**
 *  a test for const-ness
 */

 int
 main (void)
 {
 	const int i = 10;

	*(int*)&i = 20;

	printf ("i=%d\n", i);
	return 0;
 }
