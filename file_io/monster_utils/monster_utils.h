#ifndef MONSTER_UTILS_H_
#define MONSTER_UTILS_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define MAX_STR 128

typedef struct {
    char name[MAX_STR];
    char type[MAX_STR];
    int hp;
    int level;
} monster_t;

int write_monster_csv(monster_t, char *);
int write_monster_binary(monster_t, char *);
void read_monsters_csv(char *);
void read_monsters_binary(char *);
monster_t parse_csv_line(char *);
void print_monster(monster_t);
void trim(char *);

#endif
