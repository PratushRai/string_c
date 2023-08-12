#include<stdlib.h>
#include<stdint.h>
#include "string.h"
#include "memory.h"

void init_string(string *s){
  s->arr = NULL;
  s->capacity = 0;
  s->count = 0;
}

int len_str(string s){
  return s.count; 
}

int grow_capacity(int old_capacity){
  return ((old_capacity < 8) ? 8 : (old_capacity * 2));
}

void add_char(string *s, char data){
  int old_capacity = s->capacity;
  if(old_capacity < s->count + 1){
    s->capacity = grow_capacity(old_capacity);
    s->arr = allocate(s->arr, sizeof(char) * old_capacity, sizeof(char) * s->capacity);
  }
  s->arr[s->count] = data;
  s->count++;
}

void add_string(string *s, char *data){
  int old_capacity = s->capacity;
  if(old_capacity < s->count+1){
    s->capacity = grow_capacity(old_capacity);
    s->arr = allocate(s->arr, sizeof(char) * old_capacity, sizeof(char) * s->capacity); 
  }

  
  
}

void free_string(string *s){
  allocate(s->arr, sizeof(char) * s->count, 0);
}

void print_string(string s){
  printf("{ count: %d, capacity: %d, content: %s } \n", s.count, s.capacity, s.arr);
}
