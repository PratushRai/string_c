#ifndef SRC_STRING_H

#define SRC_STRING_H

#include <stdlib.h>
#include <stdbool.h>

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

int capacity_str(string s);

//returns char at index 
char* char_at(string s, int index);

//Returns string as a string literal(char *s)
char* str(string s);

bool is_empty(string s);

void add_string(string *s, char *data);

void concat(string *s1, string *s2);

//Clear the content of the string but leaves the capacity
void clear(string *s);

bool cmp_string(string s1, string s2);

bool is_ascii(char c);

#endif
