/*
 * This example shows how `realloc` allows us to modify the size of our
 * allocated memory space.
 */

#include <stdio.h>
#include <stdlib.h>

int add_int(int **arr, int value, int *numel) {
    // printf("[DEBUG] Before realloc, arr = %p\n", *arr);
    *arr = realloc(*arr, (*numel + 1) * sizeof((*arr)[0]));
    if (*arr == NULL) {
        return 1;
    }
    // printf("[DEBUG] After realloc, arr = %p\n", *arr);
    (*arr)[*numel] = value;

    // *numel = *numel + 1;
    (*numel)++;

    return 0;
}

int main() {
    // First, let's create a NULL pointer to `int`.
    int *arr = NULL;
    int numel = 0;  // keep track of how many values we have

    // We may want to store some `int` values, but have no space for them.
    // `malloc` and `calloc` are valid choices to allocate memory.
    // We can also use `realloc` -- if the pointer is NULL, it will work just like `malloc`.
    // For the size, we want to add 1 more than the current number of elements (which is 0).
    // This is multipled by the size of an `int` since we are storing `int` values.
    arr = realloc(arr, sizeof(int) * (numel + 1));
    numel++;  // don't forget to increase the number of elements in the array

    // We can now assign a value to arr[0]
    arr[0] = 10;

    // Let's add one more
    arr = realloc(arr, sizeof(int) * (numel + 1));

    // We can assign a value to arr[1] now.
    arr[1] = 15;

    for (int i = 0; i < 10; i++) {
        add_int(&arr, i, &numel);
        printf("inserted %d\n", i);
    }

    // Clean up the memory when we're done.
    free(arr);
}
