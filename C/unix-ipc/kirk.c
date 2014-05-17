# ident "a demo program to add messages to a message Queue"

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
   * Create the message Queue
   */
   
   if ((msgQid = msgget (key, 0644 | IPC_CREAT)) == -1)
     {
	 perror("msgget");
	 exit (EXIT_FAILURE);
	 }
   
   puts("\nEnter some lines of text. ^D to terminate\n");

   buf.msgtype = 1;

  /*
   * Add messages to the Queue
   */

   while (gets(buf.msgtxt), !feof(stdin))
     {
     if (msgsnd(msgQid, (struct my_msgbuf *) &buf, sizeof(buf), 0) == -1)
	   {
	   perror("msgsnd");
	   exit (EXIT_FAILURE);
	   }
	 }
   if (msgctl(msgQid, IPC_RMID, NULL) == -1)
     {
     perror ("msgctl");
	 exit (1);
	 }
  return 0;
  }
