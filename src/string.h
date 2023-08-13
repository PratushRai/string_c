#ifndef SRC_STRING_H

#define SRC_STRING_H

#include <stdlib.h>

typedef struct{
  char* arr;
  int len;
  int capacity;
}string;

void init_string(string *s);

void add_char(string *s, char data);

void free_string(string *s);

void print_string(string s);

int len_str(string s);

void add_string(string *s, char *data);

void concat(string *s1, string *s2);

#endif
