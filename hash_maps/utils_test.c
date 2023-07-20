#include "hash_map_utils.h"

#define BUF_SIZE 64

void trim(char *str) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

void print_element(hash_element_t *elem) {
    if (elem) {
        printf("(%s, %s)\n", elem->key, (char *)elem->value);
    } else {
        printf("EMPTY\n");
    }
}

void print_map(hash_map_t *map) {
    if (map->temp) {
        for (int i = 0; i < map->temp_size; i++) {
            printf("old_map[%d] = ", i);
            print_element(map->temp[i]);
        }
    }
    if (map->primary) {
        for (int i = 0; i < map->map_size; i++) {
            printf("new_map[%d] = ", i);
            print_element(map->primary[i]);
        }
    }
}

/*
 * The value of an element is `void *` so that it may take on
 * any data type that the user wants. It is a good idea to have
 * a separate free function for this since there is no way to
 * know what kind of data will be stored.
 *
 * The user of the hash map should write this.
 */
void free_element(hash_element_t *elem) {
    if (elem) {
        free(elem->key);
        free(elem->value);
        free(elem);
    }
}

/*
 * Releases all memory allocated for the current map,
 * including the pointer for the hash_map_t struct itself.
 */
void free_map(hash_map_t *map) {
    if (map) {
        if (map->temp) {
            for (int i = 0; i < map->temp_size; i++) {
                free_element(map->temp[i]);
            }

            free(map->temp);
        }

        if (map->primary) {
            for (int i = 0; i < map->map_size; i++) {
                free_element(map->primary[i]);
            }

            free(map->primary);
        }

        free(map);
    }
}

int main(int argc, char **argv) {
    char buffer[BUF_SIZE] = { 0 };
    hash_map_t *map = calloc(1, sizeof(hash_map_t));

    init_map(map, 4);

    while (1) {
        printf("Enter a key (ENTER to exit): ");
        fgets(buffer, BUF_SIZE, stdin);
        trim(buffer);

        if (strlen(buffer) == 0) {
            free_map(map);
            break;
        }

        // Determine if the given key already exists.
        hash_element_t *elem = search(map, buffer);

        if (elem == NULL) {
            elem = calloc(1, sizeof(hash_element_t));
        } else {
            printf("Key %s already exists.\n", buffer);
            continue;
        }

        elem->key = calloc(strlen(buffer) + 1, sizeof(char));
        strcpy(elem->key, buffer);

        printf("Enter a value: ");
        fgets(buffer, BUF_SIZE, stdin);
        trim(buffer);

        elem->value = calloc(strlen(buffer) + 1, sizeof(char));
        strcpy(elem->value, buffer);

        insert(map, elem);

        print_map(map);
    }

    return 0;
}
