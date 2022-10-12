#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_utils.h"

typedef struct {
    int id;
    char name[128];
} user_s;

void print_data(array_s arr) {
    for (int i = 0; i < arr.numel; i++) {
        user_s *value = arr.data[i];
        printf("(%d, %s)\n", value->id, value->name);
    }
}

int main() {
    array_s arr = { 0 };
    user_s *user1 = calloc(1, sizeof(user_s));
    user1->id = 100;
    strcpy(user1->name, "Carl");

    user_s *user2 = calloc(1, sizeof(user_s));
    user2->id = 200;
    strcpy(user2->name, "Sally");

    push(user1, &arr);
    push(user2, &arr);

    print_data(arr);

    user_s *temp = pop(&arr);

    print_data(arr);

    return 0;
}