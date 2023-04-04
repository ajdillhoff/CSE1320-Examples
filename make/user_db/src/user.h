#ifndef USER_H_
#define USER_H_

#include "array_utils.h"

typedef struct {
    char *name;
    char *email;
} user_s;

user_s *create_user();
void free_user(void *data);
array_t *load_users(const char *filename);
void save_users(char *filename, array_t *users);
void print_users(array_t *users);
user_s *parse_from_csv(char *line);

#endif