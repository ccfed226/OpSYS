#ifndef PRODCON_HPP
#define  PRODCON_HPP
    #include <stdlib.h>
    #include <sys/shm.h>
    #include <sys/ipc.h>
    #include <semaphore.h>
    #include <cstdlib> 
    #include <time.h>

    #define TABLE_SIZE 2


    /**
     * @brief The shared memory buffer with semaphores
     */
    struct sharedMem {

        int table[TABLE_SIZE];

        int in;
        int out;

        sem_t mutex;
        sem_t empty;
        sem_t full;

    };


#endif
