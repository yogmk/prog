# ident "Example of popen & pclose demoing the functionality of 'more'"

# include <stdio.h>
# include <stdlib.h>


int
write_data(FILE *stream)
 {
 int i;

 for (i = 0; i < 100; i++)
 {
  fprintf(stream, "%d\n", i);
 }
 if (ferror(stream))
  {
  fprintf(stderr, "write_data: could not write data to stream!\n");
  exit (EXIT_FAILURE);
  }
 return 0;
 }

int main()
 {
 FILE* output;

 output = popen ("more", "w");			/* 'more' command and 'w' for writing to the pipe */
 if (! output)
  {
  fprintf(stderr, "popen failed, could not create pipe\n");
  exit (EXIT_FAILURE);
  }
 write_data (output);

 if (pclose(output) != 0)
  {
  fprintf(stderr, "error");
  }
 
 return (EXIT_SUCCESS);
 }
