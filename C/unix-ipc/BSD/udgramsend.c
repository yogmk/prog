# ident "A demo program to send packets to a Unix domain datagram socket"

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/un.h>

# define DATA "The sea is calm tonight, the tide is full . . ."

/*
 * Here I send a datagram to a receiver whose name I get from the command
 * line arguments. The form of the command line is udgramsend pathname
 */

int 
main(int argc, char* argv[])
 {
 int sock;
 struct sockaddr_un name;
 char buffer[1024];

 if ((sock = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0)
  {
  perror("opening datagram socket");
  exit (EXIT_FAILURE);
  }

  /* create a name from command line */

 name.sun_family = AF_UNIX;
 strcpy(name.sun_path, argv[1]);

 /* send message */
 if (sendto(sock, DATA, sizeof(DATA), 0,
            &name, sizeof(struct sockaddr_un)) < 0)
  {
  perror("sending datagram message");
  }
 close(sock);
 }
