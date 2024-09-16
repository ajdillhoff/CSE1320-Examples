#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_utils.h"

#define BUF_SIZE 128

typedef struct {
    int id;
    char *name;
} user_s;

void print_data(array_s arr) {
    user_s *data = arr.data;
    for (int i = 0; i < arr.numel; i++) {
        user_s value = data[i];
        printf("(%d, %s)\n", value.id, value.name);
    }
}

char *read_name() {
    char buffer[BUF_SIZE] = { 0 };
    char *name = NULL;
    printf("Enter the user's name: ");
    fgets(buffer, BUF_SIZE, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;
    name = calloc(strlen(buffer) + 1, sizeof(char));
    strcpy(name, buffer);

    return name;
}

int main() {
    array_s arr = { 0, 0, 0, sizeof(user_s) };
    user_s *user1 = calloc(1, sizeof(user_s));
    user1->id = 100;
    user1->name = read_name();

    user_s *user2 = calloc(1, sizeof(user_s));
    user2->id = 200;
    user2->name = calloc(6, sizeof(char));
    strcpy(user2->name, "Sally");

    add(user1, &arr, arr.numel);
    add(user2, &arr, arr.numel);

    // push(user1, &arr);
    // free(user1);
    // push(user2, &arr);
    // free(user2);

    print_data(arr);

    // user_s *temp = pop(&arr);

    // print_data(arr);

    return 0;
}