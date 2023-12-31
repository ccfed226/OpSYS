#include <ctype.h>
#include <string.h>
#include <stdio.h>

           #include "prod_consume.h"

           int
           main(int argc, char *argv[])
           {
               int            fd;
               char           *shmpath;
               struct shmbuf  *shmp;
               char *string; 
               size_t         len;
/*
               if (argc != 2) {
                   fprintf(stderr, "Usage: %s /shm-path\n", argv[0]);
                   exit(EXIT_FAILURE);
               }
*/
               shmpath = "uqwepkf3211";
               
                string = "hello there!!!";
                len = strlen(string);
               /* Create shared memory object and set its size to the size
                  of our structure. */
                if (len > MAX_SIZE) {
                   fprintf(stderr, "String is too long\n");
                   exit(EXIT_FAILURE);
               }
               fd = shm_open(shmpath, O_CREAT | O_EXCL | O_RDWR, 0600);
               if (fd == -1)
                   errExit("shm_open");

               if (ftruncate(fd, sizeof(struct shmbuf)) == -1)
                   errExit("ftruncate");

               /* Map the object into the caller's address space. */

               shmp = mmap(NULL, sizeof(*shmp), PROT_READ | PROT_WRITE,
                           MAP_SHARED, fd, 0);
               if (shmp == MAP_FAILED)
                   errExit("mmap");

               /* Initialize semaphores as process-shared, with value 0. */
               if (sem_init(&shmp->sem1, 1, 0) == -1)
                   errExit("sem_init-sem1");
               if (sem_init(&shmp->sem2, 1, 0) == -1)
                   errExit("sem_init-sem2");

               /* Wait for 'sem1' to be posted by peer before touching
                  shared memory. */
                  int i=0; 
                while(i<10){
                
               if (sem_wait(&shmp->sem1) == -1)
                   errExit("sem_wait");

               /* Convert data in shared memory into upper case. */

               for (size_t j = 0; j < len; j++)
                   shmp->buf[i%2][j] = string[j];

               /* Post 'sem2' to tell the peer that it can now
                  access the modified data in shared memory. */

               if (sem_post(&shmp->sem2) == -1)
                   errExit("sem_post");
                ++i; 
                }
               /* Unlink the shared memory object. Even if the peer process
                  is still using the object, this is okay. The object will
                  be removed only after all open references are closed. */

               shm_unlink(shmpath);

               exit(EXIT_SUCCESS);
           }
