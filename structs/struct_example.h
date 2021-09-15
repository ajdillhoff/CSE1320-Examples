#ifndef STRUCT_EXAMPLE_H_
#define STRUCT_EXAMPLE_H_

#include <stdio.h>
#include <string.h>

#define STR_MAX 128

typedef struct {
    char name[STR_MAX];
    char type[STR_MAX];
    int hp;
    int level;
} monster_t;

void trim(char *);
void print_monster(monster_t *);
monster_t create_monster();

#endif
