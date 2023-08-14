#include <stdlib.h>
#include "string.h"
#include "memory.h"
#include <string.h>
#include <stdio.h>

void init_string(string *s){
  s->arr = NULL;
  s->capacity = 0;
  s->len = 0;
}

int len_str(string s){
  return s.len; 
}

int capacity_str(string s){
  return s.capacity;
}

char* str(string s){
  return s.arr;
}

int grow_capacity(int old_capacity){
  return ((old_capacity < 8) ? 8 : (old_capacity * 2));
}

void add_char(string *s, char data){
  int old_capacity = s->capacity;
  if(old_capacity < s->len + 1){
    s->capacity = grow_capacity(old_capacity);
    s->arr = allocate(s->arr, sizeof(char) * old_capacity, sizeof(char) * s->capacity);
  }
  s->arr[s->len] = data;
  s->len++;
}

void add_string(string *s, char *data){
  int old_capacity = s->capacity;
  if(old_capacity < s->len+1){
    s->capacity = grow_capacity(old_capacity);
    s->arr = allocate(s->arr, sizeof(char) * old_capacity, sizeof(char) * s->capacity); 
  }

  for(int i = 0; i < strlen(data); i++){
    add_char(s, data[i]);
  }
  
}

void concat(string *s1, string *s2){
  add_string(s1, s2->arr);
}

void free_string(string *s){
  allocate(s->arr, sizeof(char) * s->len, 0);
}

void print_string(string s){
  printf("{ len: %d, capacity: %d, content: %s } \n", s.len, s.capacity, s.arr);
}
