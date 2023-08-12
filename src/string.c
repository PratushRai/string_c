#include<stdlib.h>
#include<stdint.h>
#include "string.h"
#include "memory.h"

void init_string(string *v){
  v->arr = NULL;
  v->capacity = 0;
  v->count = 0;
}

int grow_capacity(int old_capacity){
  return ((old_capacity < 8) ? 8 : (old_capacity * 2));
}

void add(string *v, char data){
  int old_capacity = v->capacity;
  if(old_capacity < v->count + 1){
    v->capacity = grow_capacity(old_capacity);
    v->arr = allocate(v->arr, sizeof(char) * old_capacity,  sizeof(char) * v->capacity);
  }
  v->arr[v->count] = data;
  v->count++;
}

void free_string(string *v){
  allocate(v->arr, sizeof(char) * v->count, 0);
}