int 
main (void)
{
	int i=0;

	printf ("before postfix: %d\n", i);
	i = i++;
	i = i++;
	i = i++;
	printf ("before postfix: %d\n", i);
	return 0;
}
