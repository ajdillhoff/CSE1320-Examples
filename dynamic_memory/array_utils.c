#include <stdio.h>

#include "array_utils.h"

int add(void *data, array_s *arr) {
    if (data == NULL) {
        return 1;
    }

    arr->data = realloc(arr->data, (arr->numel + 1) * sizeof(void *));
    arr->data[arr->numel] = data;
    arr->numel++;

    return 0;
}

void *pop_p(array_s *arr, int pos) {
    if (arr == NULL || pos < 0 || pos >= arr->numel) {
        return NULL;
    }

    // Retrieve the element
    void *elem = arr->data[pos];

    // Shift the contents
    for (int i = pos; i < arr->numel - 1; i++) {
        arr->data[i] = arr->data[i+1];
    }

    // Reallocate the data
    arr->data = realloc(arr->data, (arr->numel - 1) * sizeof(void *));
    arr->numel--;

    return elem;
}

void *pop(array_s *arr) {
    return pop_p(arr, arr->numel - 1);
}