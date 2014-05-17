# ident "A demo program showing use of Unix Domain Sockets- client side"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/un.h>


# define SOCK_PATH "echo_socket"

int
main (void)
 {
 int s, t, len;
 struct sockaddr_un remote;
 char str[100];

 if ((s = socket(AF_UNIX, SOCK_STREAM, 0)) == -1)
  {
  perror("socket");
  exit (EXIT_FAILURE);
  }
 
 puts("trying to connect..\n");

 remote.sun_family = AF_UNIX;
 strcpy(remote.sun_path, SOCK_PATH);
 len = strlen(remote.sun_path) + sizeof(remote.sun_family);

 if (connect(s, (struct sock_addr*) &remote, len) == -1)
  {
  perror("connect");
  exit (EXIT_FAILURE);
  }
 
 puts("connect");
 while (putchar('>'), fgets(str, 100, stdin), !feof(stdin))
  {
  if (send(s, str, strlen(str), 0) == -1)
   {
   perror("send");
   exit (EXIT_FAILURE);
   }

  if ((t = recv(s, str, 100, 0)) > 0)
   {
   str[t] = '\0';
   printf ("echo > %s", str);
   }
  else
   {
   if (t < 0) perror("recv");
   else puts("server closed connection!\n");
   exit (EXIT_FAILURE);
   }
  }
 close(s);
 return 0;
 }
