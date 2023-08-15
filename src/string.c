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

char* char_at(string s, int index){
  if(index > s.len){
    perror("Index out of bound");
  }
  else if(is_ascii(s.arr[index])){
    return &s.arr[index];
  }
  else{
    char* str;
    int i = index;
    while(!is_ascii(s.arr[index])){
      str[i] = s.arr[index];
      i++;
    }
    return str;
  }
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
  // int old_capacity = s->capacity;
  // if(old_capacity < s->len+1){
  //   s->capacity = grow_capacity(old_capacity);
  //   s->arr = allocate(s->arr, sizeof(char) * old_capacity, sizeof(char) * s->capacity); 
  // }

  for(int i = 0; i < strlen(data); i++){
    add_char(s, data[i]);
  }
  
}

bool cmp_string(string s1, string s2){
  if(s1.len != s2.len){
    return false;
  }
  else{
    for(int i = 0; i < s1.len; i++){
      if(s1.arr[i] != s2.arr[i]){
        return false;
      }
    }
  }
  return true;
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

bool is_empty(string s){
  return ((s.arr == NULL) ? true : false);
}

bool is_ascii(char c){
  return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z' || '0' <= c <= '9';
}