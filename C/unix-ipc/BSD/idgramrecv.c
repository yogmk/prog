# ident "Reading internet domain datagrams"

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/socket.h>

# include <netinet/in.h>		/* equvi't of sys/un.h for unix domain socks */

/*
 * In the included file <netinet/in.h> a sockaddr_in is defined as follows:
 * struct sockaddr_in {
 *    short    sin_family;
 *    u_short  sin_port;
 *    struct in_addr sin_addr;
 *    char     sin_zero[8];
 * };
 *
 * This program creates a datagram socket, binds a name to it, then reads
 * from the socket.
 */

int 
main(void)
 {
 int sock;
 struct sockaddr_in name;
 char buffer [1024];
 int length;

 if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
  {
  perror("creating socket");
  exit (EXIT_FAILURE);
  }
 
 /*
  * create a name with wild-cards
  */
 
 name.sin_family = AF_INET;
 name.sin_port = 0;
 name.sin_addr.s_addr = INADDR_ANY;		/* recv packets from anywhere (not valid for sender) */

 if (bind(sock, &name, sizeof(name)))
  {
  perror("binding name to socket");
  exit(EXIT_FAILURE);
  }
 
 puts("bind() sucessful");
 /*
  * find assigned port value & print it
  */
 
 length = sizeof(name);
 if (getsockname(sock, &name, &length))
  {
  perror("finding the name of socket");
  exit(EXIT_FAILURE);
  }
 printf("socket port #%d\n", ntohs(name.sin_port));
 puts("printf() sucessful");

 /* read from the socket */

 if (read(sock, buffer, sizeof(buffer)) < 0)
  {
  perror("reading datagram from socket");
  exit (EXIT_FAILURE);
  }
 
 printf("packet-->%s\n", buffer);
 close(sock);
 }
