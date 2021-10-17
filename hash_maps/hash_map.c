#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAP_SIZE 10
#define BUF_SIZE 128

int hash_function(char *key) {
    printf("key: %s\n", key);

    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }

    printf("hash: %d\n", sum);

    return sum;
}

int compute_index(char *key, int array_size) {
    int hash = hash_function(key);
    int index = hash % array_size;

    printf("index = %d\n", index);

    return index;
}

void print_map(char *map[], int map_size) {
    for (int i = 0; i < map_size; i++) {
        printf("map[%d] = %s\n", i, map[i]);
    }
}

int main() {
    char buffer[BUF_SIZE] = { 0 };
    char *hash_map[MAP_SIZE] = { NULL };

    while (1) {
        // get key from user
        printf("Enter key (enter empty string to quit): ");
        fgets(buffer, BUF_SIZE, stdin);
        buffer[strlen(buffer) - 1] = 0;

        if (strlen(buffer) == 0) {
            for (int i = 0; i < MAP_SIZE; i++) {
                if (hash_map[i]) {
                    free(hash_map[i]);
                }
            }

            break;
        }

        // convert key to an index
        int index = compute_index(buffer, MAP_SIZE);

        // check for collision
        if (hash_map[index] != NULL) {
            printf("COLLISION DETECTED!\n");
            free(hash_map[index]);
        }

        // get value from user
        printf("Enter value: ");
        fgets(buffer, BUF_SIZE, stdin);
        buffer[strlen(buffer) - 1] = 0;

        // insert the value into the map
        hash_map[index] = malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(hash_map[index], buffer);

        print_map(hash_map, MAP_SIZE);
    }

    return 0;
}
