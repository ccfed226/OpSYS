#include <string.h>

           #include "prod_consume.h"

           int
           main(int argc, char *argv[])
           {
               int            fd;
               char           *shmpath, *string;
               size_t         len;
               struct shmbuf  *shmp;
/*
               if (argc != 3) {
                   fprintf(stderr, "Usage: %s /shm-path string\n", argv[0]);
                   exit(EXIT_FAILURE);
               }
*/
               shmpath = "uqwepkf3211";
               //string = "hello there!!!";
               //len = strlen(string);

               

               /* Open the existing shared memory object and map it
                  into the caller's address space. */

               fd = shm_open(shmpath, O_RDWR, 0);
               if (fd == -1)
                   errExit("shm_open");

               shmp = mmap(NULL, sizeof(*shmp), PROT_READ | PROT_WRITE,
                           MAP_SHARED, fd, 0);
               if (shmp == MAP_FAILED)
                   errExit("mmap");

               /* Copy data into the shared memory object. */
                int i=0; 
                while(i<10){

               shmp->cnt = len;

               /* Tell peer that it can now access shared memory. */

               if (sem_post(&shmp->sem1) == -1)
                   errExit("sem_post");

               /* Wait until peer says that it has finished accessing
                  the shared memory. */

               if (sem_wait(&shmp->sem2) == -1)
                   errExit("sem_wait");
                ++i; 
                
               /* Write modified data in shared memory to standard output. */
                //for(int j=0; j<len; ++j)
                    printf("%s\n", shmp->buf[i%2]); 
                    //write(STDOUT_FILENO, &shmp->buf[i%2][j], 1);
               //write(STDOUT_FILENO, "\n", 1);
                }
               exit(EXIT_SUCCESS);
           }
