#include <stdlib.h>

#include "array_utils.h"

array_t *array_new(int capacity) {
    array_t *array = malloc(sizeof(array_t));
    array->capacity = capacity;
    array->size = 0;
    array->data = malloc(sizeof(void *) * capacity);

    return array;
}

void array_free(array_t *array, void (*free_func)(void *)) {
    for (int i = 0; i < array->size; i++) {
        free_func(array->data[i]);
    }
    free(array);
}

void array_add(array_t *array, void *item) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->data = realloc(array->data, sizeof(void *) * array->capacity);
    }
    array->data[array->size++] = item;
}