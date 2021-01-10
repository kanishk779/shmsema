#include "helper.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char ** argv){
    // create the shared memory
    if(argc != 1){
        printf("usage - %s no args\n", argv[0]);
        exit(0);
    }
    char *mem = attach_memory(FILENAME, SIZE);
    if(mem == NULL){
        printf("failed to get the shared memory (read.c)\n");
        exit(0);
    }
    printf("Reading : %s \n", mem);
    // detach after reading
    detach_memory(mem);
    
    return 0;
}