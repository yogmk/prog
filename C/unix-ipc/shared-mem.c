# ident "A demo program showing use of shared memory"

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/shm.h>


struct
country
{
    char name [30];
    char capital [30];
    char currency[30];
    int population;
};


int
main (int rgc, char* argv[])
{
    int shmid;                                /* shared mem segment id             */
    char* shm_addr;                           /* address of shared mem segment.    */
    int* countries_counter;                   /* count of data kept in shred mem.  */
    struct shmid_ds shmds;                    /* data struct for shm operations.   */
    struct country* countries;                /* array of country structures.      */
    int i;
  
    /* Allocate a shared memory segment of a size of 2048 bytes.  */
  
    if ((shmid = shmget(100, 2048, IPC_CREAT | IPC_EXCL | 0600)) == -1)
    {
         perror("shmget");
         exit (EXIT_FAILURE);
    }
  
    /* Attach the shared memory segment to our process.  */
  
    if ((shm_addr = shmat (shmid, NULL, 0)) == NULL)
    {
         perror ("shmat");
         exit (EXIT_FAILURE);
    }
     
    /*
     * Assign addresses to counter & array
     * and create data on shared memory
     */
  
    countries_counter = (int *)shm_addr;        /* point the counter at the start of segment. */
    *countries_counter = 0;                     /* initialise to zero.  */
  
    countries = (struct country*) (shm_addr + sizeof(int));
  
    strcpy (countries[0].name, "India");
    strcpy (countries[0].capital, "New Delhi");
    strcpy (countries[0].currency, "INR");
    countries[0].population = 1000000000;
    (*countries_counter)++;
  
    strcpy (countries[1].name, "China");
    strcpy (countries[1].capital, "Beijing");
    strcpy (countries[1].currency, "YUN");
    countries[1].population = 1500000000;
    (*countries_counter)++;
  
    strcpy (countries[2].name, "Australia");
    strcpy (countries[2].capital, "Canberra");
    strcpy (countries[2].currency, "AUD");
    countries[2].population = 25000000;
    (*countries_counter)++;
  
   /* Now access & print the data */
  
    for (i=0; i < (*countries_counter); i++)
    {
         printf ("#: %d\n", i+1);
         printf ("country: %s\n", countries[i].name);
         printf ("capital: %s\n", countries[i].capital);
         printf ("currency: %s\n", countries[i].currency);
         printf ("population: %d\n", countries[i].population);
         puts("\n");
    }
  
    /* Detach from shared memory */
  
     if (shmdt(shm_addr) == -1)
     {
          perror("shmdt");
          exit (EXIT_FAILURE);
     }
      
    /* De-allocate the shared memory */
  
     if (shmctl(shmid, IPC_RMID, &shmds) == -1)
     {
          perror("shmctl");
          exit (EXIT_FAILURE);
     }
     return 0;
} 
