/*
* Meomry related functions
* By Pratush Rai
*/

#include<stdlib.h>
#include"memory.h"

#define nullptr NULL // NULL -> nullptr


/*
Allocates new amount of memory 
for string based on old and new size
*/
char* allocate(char* pointer, int old_size, int new_size){
  if(new_size == 0){
    free(pointer);
    return nullptr;
  }
  char *result = realloc(pointer, new_size);
  if(result == nullptr) exit(1);
  return result;
}
