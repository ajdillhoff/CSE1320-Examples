#include <stdio.h>

#include "array_utils.h"

int main() {
    array_s *arr = malloc(sizeof(array_s));
    arr->elem_size = sizeof(int);
    arr->numel = 0;
    arr->capacity = 4;
    arr->data = calloc(arr->capacity, arr->elem_size);

    // int a = 1;

    printf("[DEBUG] arr->data = %p\n", arr->data);

    for (int i = 0; i < 10; i++) {
        add(&i, arr, arr->numel);
    }

    // for (int i = 0; i < arr->numel; i++) {
    //     int *data = (int *)arr->data + i;

    //     printf("a[%d] = %d (%p)\n", i, *data, data);
    // }

    return 0;
}