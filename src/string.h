#pragma once
#include <stdlib.h>

#include <stdint.h>

typedef struct{
  char* arr;
  int count;
  int capacity;
}string;


void init_string(string *s);

void add_char(string *s, char data);

void free_string(string *s);

void print_string(string s);

int len_str(string *s);

void add_string(string *s, char *data);