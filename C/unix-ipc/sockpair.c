/*
 * This program creates a pair of connected sockets then forks and
 * communicates over them. This is very similar to communication with pipes,
 * however, socketpairs are two-way communications objects. Therefore I can
 * send messages in both directions.
 */

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/socket.h>

# define DATA1 "In Xanadu did Kublai Khan . . ."
# define DATA2 "A stately pleasure dome decree . . ."

int
main (void)
 {
 int sockets[2];
 int child;
 char buff[1024];

 if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockets) < 0)
  {
  perror("opening socket pair");
  exit (EXIT_FAILURE);
  }

 if ((child = fork()) == -1)
  {
  perror("fork");
  exit (EXIT_FAILURE);
  }
 else if (child)
  /* this is parent */
  {
  close (sockets[0]);
  if (read(sockets[1], buff, 1024, 0) < 0)
   perror("reading stream message");
  printf("-->%s", buff);
  if (write(sockets[1], DATA2, sizeof(DATA2)) < 0)
   perror("writing stream message");
  close (sockets[1]);
  }
  else
   {
   close(sockets[1]);
   if (write(sockets[0], DATA1, sizeof(DATA1)) < 0)
      perror("writing stream message");
   if (read(sockets[0], buff, 1024, 0) < 0)
      perror("reading stream message");
      printf("-->%s\n", buff);
      close(sockets[0]);
   }
 }
