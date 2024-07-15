#include <stdio.h>
#include <string.h>

#include "array_utils.h"

int add(void *data, array_s *arr, int pos) {
    if (pos < 0 || pos > arr->numel || data == NULL || arr == NULL) {
        return 1;
    }

    // Resize our array
    arr->data = realloc(arr->data, (arr->numel + 1) * arr->elem_size);

    // Shift contents
    // for (int i = arr->numel; i > pos; i--) {
    //     arr->data[i] = arr->data[i-1];
    // }

    // Insert the element
    memcpy(arr->data + (arr->numel * arr->elem_size), data, arr->elem_size);
    // arr->data[pos] = data;
    arr->numel++;
    arr->capacity++;

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