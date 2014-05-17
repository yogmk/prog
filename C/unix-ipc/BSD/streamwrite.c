
# ident "initiating an internet domain stream socket."

# include <stdio.h>
# include <stdlib.h>
# include <netdb.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>

# define DATA "Half a league, half a league . . ."

/* 
 * This program creates a socket and initiates a connection with the socket 
 * given in the command line. One message is sent over the connection and 
 * then the socket is closed, ending the connection. The form of the command 
 * line is streamwrite hostname portnumber 
 */

int
main (int argc, char* argv[])
 {
 int sock;
 struct sockaddr_in server;
 struct hostent* hp;
 struct hostent* gethostbyname();
 char buffer[1024];

 /* sanity check */

 if (argc < 3)
  {
  fprintf(stderr, "usage streamwrite hostname portnumber");
  exit (EXIT_FAILURE);
  }

 /* create socket */

 if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
  perror("opening stream socket");
  exit (EXIT_FAILURE);
  }

 /* connect socket by using name passed thru command line */

 server.sin_family = AF_INET;
 hp = gethostbyname(argv[1]);
 if (hp == 0)
  {
  fprintf(stderr, "%s: unknown host.", argv[1]);
  exit(2);
  }
 
 //bcopy(hp->h_addr, &server.sin_addr, hp->h_length);
 memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
 server.sin_port = htons(atoi(argv[2]));

 if (connect(sock, &server, sizeof(server)) < 0)
  {
  perror("connecting to socket");
  exit (EXIT_FAILURE);
  }
 
 if (write(sock, DATA, sizeof(DATA)) < 0)
  {
  perror("writing to socket");
  exit (EXIT_FAILURE);
  }
 close(sock);
 }
