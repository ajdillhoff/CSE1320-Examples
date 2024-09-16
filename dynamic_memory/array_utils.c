#include <stdio.h>
#include <string.h>

#include "array_utils.h"

int add(void *data, array_s *arr, int pos) {
    // Basic error checking
    if (pos < 0 || pos > arr->numel || data == NULL || arr == NULL) {
        return 1;
    }

    if (arr->numel == arr->capacity) {
        printf("[DEBUG] Need to resize\n");
        // Resize our array
        arr->data = realloc(arr->data, arr->capacity * 2 * arr->elem_size);
        arr->capacity *= 2;
    }

    // arr->data = realloc(arr->data, (arr->numel + 1) * arr->elem_size);

    // Shift contents
    // for (int i = arr->numel; i > pos; i--) {
    //     arr->data[i] = arr->data[i-1];
    // }

    // Shift the data over
    memcpy(arr->data + ((pos + 1) * arr->elem_size),
           arr->data + pos * arr->elem_size,
           (arr->numel - pos) * arr->elem_size);

    // Insert the element
    memcpy(arr->data + (pos * arr->elem_size), data, arr->elem_size);

    // arr->data[pos] = data;
    arr->numel++;

    return 0;
}

int push(void *elem, array_s *arr) {
    return add(elem, arr, arr->numel);
}

// void *pop_p(array_s *arr, int pos) {
//     // Error checking
//     if (arr == NULL || pos < 0 || pos >= arr->numel) {
//         return NULL;
//     }

//     // Get the data requested
//     void *elem = arr->data[pos];

//     // Shift data
//     for (int i = pos; i < arr->numel - 1; i++) {
//         arr->data[i] = arr->data[i+1];
//     }

//     // Realloc
//     arr->data = realloc(arr->data, (arr->numel - 1) * sizeof(void *));
//     arr->numel--;

//     return elem;
// }

// void *pop(array_s *arr) {
//     return pop_p(arr, arr->numel-1);
// }