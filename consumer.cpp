#include "consumer.hpp"
#include "prod_consume.hpp"




int main(int argc, char *argv[]) {
    srand(time(nullptr)); 
    //Vars
    int fd;
    char * shmpath;
    struct sharedMem *consMem;



    //Grab the shared mem path from command
    shmpath = argv[1];


    //open mem
    fd = shm_open(shmpath, O_RDWR, 0);



    //Truncate it to the size of the struct, ensures extra is not used
    ftruncate(fd, sizeof(*consMem));

    consMem = static_cast<sharedMem*>(mmap(NULL, sizeof(*consMem), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0));

    int i=0; 
    while(i<5){
        sem_wait(&(consMem->full));
        sem_wait(&(consMem->mutex));


        std::cout << "Consumed: hello there!!!" << std::endl;
        

        consMem->out = (consMem->out + 1) % TABLE_SIZE;


        sem_post(&(consMem->mutex));
        sem_post(&(consMem->empty));

        sleep((rand()%10)/1000);
    ++i; 
    }


    //Detatch mem
    shm_unlink(shmpath);


    return 0;

}
