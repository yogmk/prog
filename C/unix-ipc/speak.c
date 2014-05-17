# ident "a sample prog to demo the functionality of named pipe (write part)"

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
  * following open is a blocking call.
  * unless someone opens the pipe for
  * reading, this will wait.
 */
 printf ("speak: waiting for reader...\n");
 fd = open(FIFO_PIPE, O_WRONLY);
 printf ("speak: got a reader..type some text\n");

 while (gets(msg), !feof(stdin))
  {
  if ((num=write(fd, msg, strlen(msg))) == -1)
   {
   perror("speak:write");
   }
  else
   {
   printf("speak: wrote %d bytes\n", num);
   }
  }
 }
