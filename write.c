#include "helper.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char ** argv){
    // create the shared memory
    if(argc != 2){
        printf("usage - %s [write something]\n", argv[0]);
        exit(0);
    }
    char *mem = attach_memory(FILENAME, SIZE);
    if(mem == NULL){
        printf("failed to get the shared memory (write.c)\n");
        exit(0);
    }
    printf("Writing : %s \n", argv[1]);
    strncpy(mem, argv[1], SIZE);

    detach_memory(mem);

    return 0;
}