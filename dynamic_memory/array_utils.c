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