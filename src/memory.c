/*
All memory related stuff
*/

#include<stdlib.h>
#include"memory.h"

#define nullptr NULL

char* allocate(char* pointer, int old_size, int new_size){
  if(new_size == 0){
    free(pointer);
    return nullptr;
  }
  char *result = realloc(pointer, new_size);
  if(result == nullptr) exit(1);
  return result;
}