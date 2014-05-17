
# ident "Using select() to check for pending connections."


# include <stdio.h>
# include <stdlib.h>
# include <netdb.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/time.h>
# include <netinet/in.h>

# define TRUE 1


/*
 * This program uses select() to check that someone is trying to connect
 * before calling accept().
 */


int
main ()
 {
 int sock;
 int msgsock;
 struct sockaddr_in server;
 char buffer[1024];
 int length, retval;
 fd_set ready;
 struct timeval timeout;

 /* create socket */

 if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
  perror("opening stream socket");
  exit (EXIT_FAILURE);
  }

 /* Name the socket using wildcards */
 server.sin_family = AF_INET;
 server.sin_addr.s_addr = INADDR_ANY;
 server.sin_port = 0;

 if (bind(sock, &server, sizeof(server)) < 0)
  {
  perror("binding stream socket");
  exit (EXIT_FAILURE);
  }
 
 /* find out assigned port number & print it out */
 length = sizeof(server);
 if (getsockname(sock, &server, &length))
   {
   perror("getting stream socket name");
   exit (EXIT_FAILURE);
   }
 
 fprintf(stdout, "socket has port# %d\n", ntohs(server.sin_port));

 /* start accepting connections */
 listen(sock, 5);
 do
   {
   FD_ZERO (&ready);
   FD_SET(sock, &ready);
   timeout.tv_sec = 5;
   if (select(sock + 1, &ready, 0, 0, &timeout) < 0) 
    {
	perror("select");
	continue;
	}
   if (FD_ISSET(sock, &ready))
    {
    msgsock = accept(sock, 0, 0);
    if (msgsock == -1)
      perror("accept");
    else
      do
 	   {
	   if (FD_ISSET(sock, &ready))
       memset(buffer, 0, sizeof(buffer)); 
	   if ((retval = read(msgsock, buffer, 1024)) < 0)
    		perror("reading stream message");

	   if (retval == 0)
    	    perror("ending connection.");
	   else
    	    printf( "msg>%s\n", buffer);
	   } while (retval != 0);
	   close(msgsock);
	}
   else
    puts("Do something else!\n");
   } while (TRUE);

     /*
      * Since this program has an infinite loop, the socket "sock" is
      * never explicitly closed. However, all sockets will be closed
      * automatically when a process is killed or terminates normally.
      */
 }
