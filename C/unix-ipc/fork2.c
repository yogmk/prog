
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    pid_t whichone, first, second;
    int howmany;
    int status;
    
    if ((first=fork())==0) /* Parent spawns 1st child */
    {
        printf("Hiya, I am the first child, "
               "and my id is %d\n", 
               getpid()
               );
        sleep(10); /* Sleep 10 sec, then exit */
        exit(0);   
    }
    else if (first == -1)
    {
        perror("1st fork: something went bananas\n");
        exit(1);
    }
    else if ((second=fork())==0) /* Parent spawns 2nd  child */
    {
        printf("Hiya, I am the second child, "
               "and my id is %d\n", 
               getpid()
               );
        sleep(15); /* Sleep 15 sec, then exit */
        exit(0);   
    }
    else if (second == -1)
    {
        perror("2nd fork: something went bananas\n");
        exit(1);
    }
           
    printf("This is the parent\n");
    
    howmany=0; 
    while (howmany < 2) /* Wait twice */
    {
        whichone=wait(&status);
        howmany++;
        
        if (whichone==first)
           printf("First child exited ");
        else
           printf("Second child exited ");
    
        if ((status & 0xffff)==0)
           printf("correctly\n");
        else
           printf("uncorrectly\n");
    }

    return 0;
}

