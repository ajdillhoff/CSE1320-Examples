#include <stdio.h>
#include <stdlib.h>

int *init_array(int size, int val) {
    if (val == 0) {
        return calloc(size, sizeof(int));
    }
    int *arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = val;
    }

    return arr;
}

int main() {

    int *arr = init_array(1000, 10);
    int size = 1000;

    for (int i = 0; i < 1000; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);

    return 0;
}