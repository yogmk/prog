
# ident "Sending an internet domain datagram"

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/socket.h>

# include <netinet/in.h>		/* equvi't of sys/un.h for unix domain socks */
# include <netdb.h>

# define DATA "The sea is calm tonight, the tide if full . . ."

/*
 * datagram is sent to a receiver, 
 * whose name is passed from command line.
 */

int 
main(int argc, char* argv[])
 {
 int sock;
 struct sockaddr_in name;
 struct hostent *hp;
 struct hostent *gethostbyname();

 if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
  {
  perror("creating socket");
  exit (EXIT_FAILURE);
  }
 
 /*
  * create a name with no wild-cards, of the socket to send to.
  * port number will be passed from command line. 
  * gethostbyname() returns a struct includeing network address 
  * of the specified host.
  */
 
 hp = gethostbyname(argv[1]);
 if (hp == 0) 
  { 
  fprintf(stderr, "%s: unknown host ", argv[1]); 
  exit(2); 
  } 
 
 memcpy (hp->h_addr, &name.sin_addr, hp->h_length);
 name.sin_family = AF_INET;
 name.sin_port = htons(atoi(argv[2]));

 /* send message */
 if (sendto(sock, DATA, sizeof(DATA), 0, &name, sizeof(name)) < 0)
  {
  perror("sendto");
  exit (EXIT_FAILURE);
  }
 close(sock); 
 }
