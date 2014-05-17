# ident "A demo program showing use of Unix Domain Sockets"

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
 int s, s2, t, len;
 struct sockaddr_un remote, local;
 char str[100];

 if ((s = socket(AF_UNIX, SOCK_STREAM, 0)) == -1)
  {
  perror("socket");
  exit (EXIT_FAILURE);
  }
 local.sun_family = AF_UNIX;
 strcpy(local.sun_path, SOCK_PATH);
 unlink(local.sun_path);
 len = strlen(local.sun_path) + sizeof(local.sun_family);

 if (bind(s, (struct sock_addr*) &local, len) == -1)
  {
  perror("bind");
  exit (EXIT_FAILURE);
  }
 
 if (listen(s, 5) == -1)
  {
  perror("listen");
  exit (EXIT_FAILURE);
  }

 for (;;)
  {
  int done, n;
  puts("Waiting for a connection.\n");
  t = sizeof (remote);
  if ((s2 = accept(s, (struct sock_addr*) &remote, &t)) == -1)
   {
   perror("accept");
   exit (EXIT_FAILURE);
   }

  puts("connected.\n");

  done = 0;

  do
   {
   n = recv (s2, str, 100, 0);
   if (n <=0)
    {
	if (n < 0) perror("recv");
	done = 1;
	}

   if (!done)
    if (send(s2, str, n, 0) < 0)
	 {
	 perror("send");
	 done = 1;
	 }
   } while (!done);
   close (s2);
   }
  return 0;
  }
