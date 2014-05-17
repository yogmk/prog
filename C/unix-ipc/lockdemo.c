# ident " demo program showing fcntl locking in action"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>


int 
main (int argc, char **argv)
{
    struct flock fl =
    {
         F_WRLCK,                    /* l_type -> type of lock */
         SEEK_SET,                   /* l_whence -> from where */
         0,                          /* l_start -> offset from l_whence */
         0,                          /* l_len -> how many bytes */
         0                           /* l_pid -> getpid() */
    };

    int fd;

    if (argc > 1)
    {
         fl.l_type = F_RDLCK;
    }
    
    /* open the file */

    if ((fd = open("lockdemo.c", O_RDWR)) == -1)
    {
        perror("open");
        exit (EXIT_FAILURE);
    }
    
    puts("Press any key to get a lock on the file..\n");
    getchar();
    puts("Trying to acquire a lock....\n");

    fl.l_len = 1305;
    if (fcntl(fd, F_SETLKW, &fl) == -1)
    {
        perror("fcntl");
        exit(1);
    }
    puts ("\nacquired the lock..\n");
    puts ("Press any key to release lock..\n");

    getchar();

    fl.l_type = F_UNLCK;        /* unlock */   
    if (fcntl(fd, F_SETLK, &fl) == -1)
    {
        perror("fcntl");
        exit (1);
    }
    puts ("unlocked..\n");
    return 0;
}
/* some text */
/* some text */
/* some text */
