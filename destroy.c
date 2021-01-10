#include "helper.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
    if(argc != 1){
        printf("usage - %s no args\n", argv[0]);
        exit(0);
    }
    if(destroy_memory(FILENAME))
        printf("successfully Destroyed\n");
    else
        printf("Not able to destroy\n");
    return 0;
}