#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LF_BOUND 0.1
#define BUF_SIZE 128

typedef struct {
    char *key;
    char *value;
} hash_element_t;

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

double get_load_factor(int num_keys, int array_size) {
    return (double)num_keys / array_size;
}

void print_map(hash_element_t **hash_map, int array_size) {
    for (int i = 0; i < array_size; i++) {
        if (hash_map[i] != NULL) {
            printf("hash_map[%d] = (\"%s\", \"%s\")\n", i, hash_map[i]->key, hash_map[i]->value);
        } else {
            printf("hash_map[%d] = EMPTY\n", i);
        }
    }
}

void rehash(hash_element_t ***hash_map, int *array_size) {
    int new_size = *array_size * 2;
    hash_element_t **new_map = calloc(new_size, sizeof(void *));

    printf("REHASHING\n");

    // Rehash all elements in the original map
    for (int i = 0; i < *array_size; i++) {
        hash_element_t *temp = (*hash_map)[i];

        if (temp == NULL) {
            continue;
        }

        int new_index = compute_index(temp->key, new_size);

        // Linear probing
        if (new_map[new_index] != NULL) {
            printf("REHASH COLLISION DETECTED\n");

            while (new_map[new_index] != NULL) {
                new_index = (new_index + 1) % new_size;
            }

            printf("new index: %d\n", new_index);
        }

        new_map[new_index] = temp;
    }

    free(*hash_map);
    *hash_map = new_map;
    *array_size = new_size;
}

int main() {
    char buffer[BUF_SIZE] = { 0 };
    hash_element_t **hash_map = NULL;
    int num_keys = 0;
    int array_size = 4;

    hash_map = calloc(array_size, sizeof(void *));

    while (1) {
        hash_element_t *elem = calloc(1, sizeof(hash_element_t));

        // get key from user
        printf("Enter key: ");
        fgets(buffer, BUF_SIZE, stdin);
        buffer[strlen(buffer) - 1] = 0;

        // copy key to elem
        elem->key = malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(elem->key, buffer);

        double current_load = get_load_factor(num_keys, array_size);
        double new_load = get_load_factor(num_keys + 1, array_size);

        printf("Current Load: %.2lf\n", current_load);
        printf("New Load: %.2lf\n", new_load);

        if (new_load > LF_BOUND) {
            rehash(&hash_map, &array_size);
        }

        // convert key to an index
        int index = compute_index(buffer, array_size);

        // check for collision
        if (hash_map[index] != NULL) {
            printf("COLLISION DETECTED!\n");

            while (hash_map[index] != NULL) {
                index = (index + 1) % array_size;
            }
        }

        printf("new index = %d\n", index);

        // get value from user
        printf("Enter value: ");
        fgets(buffer, BUF_SIZE, stdin);
        buffer[strlen(buffer) - 1] = 0;

        // copy value to elem
        elem->value = malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(elem->value, buffer);

        // insert the value into the map
        hash_map[index] = elem;

        num_keys++;

        print_map(hash_map, array_size);
    }

    return 0;
}
