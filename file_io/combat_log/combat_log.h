#ifndef COMBAT_LOG_H_
#define COMBAT_LOG_H_

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int attacker_id;
    int target_id;
    int damage;
} ACTION;

void print_menu();
void get_choice(char*);
int log_combat(FILE*);
int get_num_rounds(FILE*);

#endif
