#include "hash_map_utils.h"

int hash_function(char *key) {
    int hash = 0;

    for (int i = 0; i < strlen(key); i++) {
        hash += key[i];
    }

    return hash;
}

int compute_index(char *key, int map_size) {
    int hash = hash_function(key);
    int index = hash % map_size;

    return index;
}

hash_element_t *search(hash_map_t *map, char *key) {
    if (map->temp != NULL) {
        int index = compute_index(key, map->temp_size);
        if (!strcmp(map->temp[index]->key, key)) {
            return map->temp[index];
        }
    } else if (map->primary != NULL) {
        int index = compute_index(key, map->map_size);
        if (!strcmp(map->primary[index]->key, key)) {
            return map->primary[index];
        }
    }

    return NULL;
}

void rehash_inc(hash_map_t *map) {
    for (int i = 0; i < R_VALUE; i++) {
        if (map->temp == NULL) {
            return;
        }

        hash_element_t *elem = map->temp[map->temp_index];
        int index = compute_index(elem->key, map->map_size);
        map->primary[index] = elem;

        map->temp[map->temp_index] = NULL;

        // Iterate to next non-null value
        while (map->temp[map->temp_index] == NULL && map->temp_index < map->temp_size) {
            map->temp_index++;
        }

        // Check if temp map is empty
        if (map->temp_index == map->temp_size) {
            free(map->temp);
        }
    }
}

void insert(hash_map_t *map, hash_element_t *elem) {
    int index = compute_index(elem->key, map->map_size);

    // TODO: Check load factor and begin rehash if necessary

    if (map->primary[index]) {
        printf("Collision detected!\n");

        while (map->primary[index] != NULL) {
            index = (index + 1) % map->map_size;
        }
    }

    map->primary[index] = elem;
}
