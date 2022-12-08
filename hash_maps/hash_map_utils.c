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

double compute_load_factor(int num_keys, int bucket_size) {
    return (double)num_keys / bucket_size;
}

/*
 * Initializes the map to a given `size`.
 */
void init_map(hash_map_t *map, int size) {
    map->primary = calloc(size, sizeof(void *));
    map->map_size = size;
}

/*
 * Searches a map that implements incremental rehashing.
 * It is necessary to check both the old and new maps
 * when searching for a key.
 *
 * Returns NULL if no such key was found.
 */
hash_element_t *search(hash_map_t *map, char *key) {
    if (map->temp != NULL) {
        int index = compute_index(key, map->temp_size);
        hash_element_t *elem = map->temp[index];
        if (elem && !strcmp(elem->key, key)) {
            return elem;
        }
    }

    if (map->primary != NULL) {
        int index = compute_index(key, map->map_size);
        hash_element_t *elem = map->primary[index];
        if (!elem) {
            return NULL;
        }
        if (!strcmp(elem->key, key)) {
            return elem;
        }
    }

    return NULL;
}

/*
 * Performs incremental rehashing on the map.
 */
void rehash_inc(hash_map_t *map) {
    for (int i = 0; i < R_VALUE; i++) {
        // If there is nothing to rehash at the moment, return immediately.
        if (map->temp == NULL) {
            return;
        }

        // Iterate to next non-null value
        while (map->temp[map->temp_index] == NULL && map->temp_index < map->temp_size) {
            map->temp_index++;
        }

        // Check if temp map is empty
        if (map->temp_index == map->temp_size) {
            free(map->temp);
            map->temp = NULL;
            map->temp_index = 0;

            return;
        }

        hash_element_t *elem = map->temp[map->temp_index];
        int index = compute_index(elem->key, map->map_size);

        // Collision resolution via linear probing
        if (map->primary[index]) {
            printf("Rehashing collision detected!\n");

            while (map->primary[index] != NULL) {
                index = (index + 1) % map->map_size;
            }
        }

        map->primary[index] = elem;

        printf("Rehashing %s into %d\n", elem->key, index);

        map->temp[map->temp_index] = NULL;
    }
}

/*
 * Assumes that the element does not currently exist.
 */
void insert(hash_map_t *map, hash_element_t *elem) {
    double factor = compute_load_factor(map->num_keys + 1, map->map_size);

    printf("[DEBUG] factor = %.2lf\n", factor);

    if (factor >= LOAD_FACTOR) {
        printf("Beginning rehash...\n");
        // Begin rehash
        map->temp = map->primary;
        map->temp_size = map->map_size;
        map->primary = calloc(map->map_size * 2, sizeof(void *));
        map->map_size *= 2;
    }

    int index = compute_index(elem->key, map->map_size);

    if (map->primary[index]) {
        printf("Collision detected!\n");

        while (map->primary[index] != NULL) {
            index = (index + 1) % map->map_size;
        }
    }

    printf("Inserting %s at %d\n", elem->key, index);

    map->primary[index] = elem;
    map->num_keys++;

    rehash_inc(map);
}

/*
 * Assumes that the element does not currently exist.
 */
void insert_no_rehash(hash_map_t *map, hash_element_t *elem) {
    int index = compute_index(elem->key, map->map_size);

    if (map->primary[index]) {
        printf("Collision detected!\n");

        while (map->primary[index] != NULL) {
            index = (index + 1) % map->map_size;
        }
    }

    printf("Inserting %s at %d\n", elem->key, index);

    map->primary[index] = elem;
    map->num_keys++;
}
