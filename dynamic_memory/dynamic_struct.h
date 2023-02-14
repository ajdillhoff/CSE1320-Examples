#ifndef DYNAMIC_STRUCT_H_
#define DYNAMIC_STRUCT_H_

#include <stdio.h>

typedef struct {
    char *name;
    char *email;
} user_s;

user_s *create_user();
user_s *read_user(FILE *);
void write_user(FILE *, user_s *);
void free_user(user_s *);
void print_user(user_s *);

#endif