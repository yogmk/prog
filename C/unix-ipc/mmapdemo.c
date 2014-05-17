# ident "mmap() demo. Map this source file in memory & access"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/mman.h>


int
main (int argc, char **argv)
 {
 int i, fd, from, to;
 struct stat st;
 char *buffer;

 if (argc != 3)
  {
  puts ("\nusage: mmapdemo from to\n");
  exit (EXIT_FAILURE);
  }
 
 if ((fd=open("mmapdemo.c", O_RDONLY)) == -1)
  {
  perror("open");
  exit (EXIT_FAILURE);
  }

 if (stat("mmapdemo.c", &st) == -1)
  {
  perror("stat");
  exit (EXIT_FAILURE);
  }
 from = atoi(argv[1]);
 to  = atoi(argv[2]);
 if ((buffer = mmap((caddr_t)0, st.st_size, PROT_READ, MAP_SHARED, fd, 0)) == (caddr_t) -1)
  {
  perror("mmap");
  exit (EXIT_FAILURE);
  }
 
 for (i=from; i <=to; i++)
  {
   putchar(buffer[i]);
  }

 munmap((caddr_t) buffer, st.st_size);
 return 0;
 }
