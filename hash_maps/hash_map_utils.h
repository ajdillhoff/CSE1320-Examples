#ifndef HASH_MAP_UTILS_H_
#define HASH_MAP_UTILS_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define R_VALUE 1

typedef struct {
    char *key;
    void *value;
} hash_element_t;

typedef struct {
    hash_element_t **temp;
    hash_element_t **primary;
    int temp_size;
    int map_size;
    int temp_index;
} hash_map_t;

int hash_function(char *);
int compute_index(char *, int);
hash_element_t *search(hash_map_t *, char *);
void rehash_inc(hash_map_t *);
void insert(hash_map_t *, hash_element_t *);

#endif
