#ifndef MEMORY_SHARE
#define MEMORY_SHARE

#include<stdbool.h>

int Size = 4096;
char * file = "temp";
char * attach_memory(char * filename, int size);
int detach_memory(char * block);
int destroy_memory(char * filename);

#endif MEMORY_SHARE