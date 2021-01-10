#ifndef MEMORY_SHARE
#define MEMORY_SHARE

#include<stdbool.h>
#define SIZE 4096
#define FILENAME "temp.txt"

char * attach_memory(char * filename, int size);
bool detach_memory(char * block);
bool destroy_memory(char * filename);

#endif