# ident "a sample prog to demo the functionality of named pipe (read part)"

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>

# define FIFO_PIPE "myfifo.pipe"

int main ()
 {
 char msg [100];
 int num, fd;
 mknod(FIFO_PIPE, S_IFIFO | 0666, 0);

 /*
  * following open is a blocking call
  * unless someone opens the pipe for
  * writing, this will wait
 */
 printf ("tick: waiting for writer...\n");
 fd = open(FIFO_PIPE, O_RDONLY);
 printf ("tick: got a writer..\n");

 do
  {
  if ((num=read(fd, msg, 100)) == -1)
   {
   perror("tick:read");
   }
  else
   {
   msg[num] = '\0';
   printf("tick: read %d bytes| %s\n", num, msg);
   }
  }while (num >0);
 }
