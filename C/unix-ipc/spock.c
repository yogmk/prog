
# ident "a demo program to fetch messages from a message Queue"

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/msg.h>

struct my_msgbuf
  {
  long msgtype;
  char msgtxt [100];
  };


int main (void)
  {
  struct my_msgbuf buf;
  int msgQid;
  key_t key;

  /*
   * Generate the key.
   */

  if ((key = ftok("kirk.c", 'B')) == -1 )
    {
	perror("ftok");
	exit (EXIT_FAILURE);
	}

  /*
   * connect to the message Queue
   */
   
   if ((msgQid = msgget (key, 0644)) == -1)
     {
	 perror("msgget");
	 exit (EXIT_FAILURE);
	 }
   
   puts("\nspock: ready to receive messages, captain!\n");

   buf.msgtype = 1;

  /*
   * fetch messages from the Queue
   * in a forever loop.
   */

   while (1)
     {
     if (msgrcv(msgQid, (struct my_msgbuf *) &buf, sizeof(buf), 0, 0) == -1)
	   {
	   perror("msgrcv");
	   exit (EXIT_FAILURE);
	   }
	 printf ("\nspock: %s\n", buf.msgtxt);
	 }
  return 0;
  }
