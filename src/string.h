#pragma once
#include <stdlib.h>

#include <stdint.h>

typedef struct{
  char* arr;
  int count;
  int capacity;
}string;


void init_string(string *v);

void add(string *v, char data);

void free_string(string *v);