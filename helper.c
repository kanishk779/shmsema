#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SHM_ERROR (-1)

static int get_shared_id(char * filename, int size){
    key_t key = ftok(filename, 0); // gives a key associated with the file provided
    if(key == SHM_ERROR){
        printf("ftok failed\n");
        exit(0);
    }
    int id = shmget(key, size, 0644 | IPC_CREAT) // gives a block id 
    if(id == SHM_ERROR){
        printf("shmget failed\n");
        exit(0);
    }
    return id;
}

char * attach_memory(char * filename, int size){
    int id = get_shared_id(filename, size);
    char * res = shmat(id, 0, NULL); // returns the address to be used for shared memory
    if(res == (char *) SHM_ERROR){
        printf("attaching memory failed\n");
        exit(0);
    }
    return res;
}
// just detach the shared memory it does not destroys the shared memory
bool detach_memory(char * id){
    // it takes the address returned by shmat() function as input for detaching the current process
    return (shmdt(id) != SHM_ERROR);
}
// if the nattch variable in shmid_ds struct becomes 0, the kernel itself removes that memory
bool destroy_memory(char * filename){
    int id = get_shared_id(filename, 0);
    if(id == SHM_ERROR){
        printf("cannot destroy memory\n");
        exit(0);
    }
    return (shmctl(id, IPC_RMID, 0) != SHM_ERROR);
}