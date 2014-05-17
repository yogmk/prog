# ident "Demo program to recieve data from a Unix DATAGRAM socket"

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/un.h>

# define NAME "socket"

/*
 * Create a unix domain Datagram socket
 * bind a name to it & read from it
 */

int main(void)
 {
 int sock;
 struct sockaddr_un name;
 char buffer[1024];

 if ((sock = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0)
  {
  perror("opening datagram socket");
  exit (EXIT_FAILURE);
  }

  /* create a name */

 name.sun_family = AF_UNIX;
 strcpy(name.sun_path, NAME);
 if(bind(sock, &name, sizeof(struct sockaddr_un)))
  {
  perror("binding name to datagram socket");
  exit (EXIT_FAILURE);
  }
 
 printf("socket-->%s\n", NAME);

 if ((read(sock, buffer, sizeof(buffer))) < 0)
  {
  perror("receiving datagram packet");
  exit (EXIT_FAILURE);
  }
 
 printf("packet-->%s\n", buffer);
 close(sock);
 unlink(NAME);
 }
