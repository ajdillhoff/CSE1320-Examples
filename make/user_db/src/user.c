#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "user.h"
#include "utils.h"
#include "array_utils.h"

user_s *create_user() {
    user_s *user = malloc(sizeof(user_s));
    printf("Enter name: ");
    user->name = read_string(stdin);
    printf("Enter email: ");
    user->email = read_string(stdin);

    return user;
}

void free_user(void *data) {
    user_s *user = (user_s *)data;
    free(user->name);
    free(user->email);
    free(user);
}

/*
 * Load users from a CSV file.
 */
user_s *load_users(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    array_t *users = array_new(8);
    char *line = NULL;

    while ((line = read_string(fp)) != NULL) {
        trim(line);

        user_s *user = parse_from_csv(line);
        array_add(users, user);
    }
}

/*
 * Parse a line from a CSV file into a user object.
 */
user_s *parse_from_csv(char *line) {
    char *name = strtok(line, ",");
    char *email = strtok(NULL, ",");

    user_s *user = malloc(sizeof(user_s));
    user->name = strdup(name);
    user->email = strdup(email);

    return user;
}

void save_users(char *filename, array_t *users) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return;
    }

    for (int i = 0; i < users->size; i++) {
        user_s *user = users->data[i];
        fprintf(fp, "%s,%s\n", user->name, user->email);
    }
}

void print_users(array_t *users) {
    for (int i = 0; i < users->size; i++) {
        user_s *user = users->data[i];
        printf("%s (%s)\n", user->name, user->email);
    }
}