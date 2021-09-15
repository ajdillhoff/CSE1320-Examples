#include <stdio.h>
#include <string.h>

int main() {
    int *arr_ptr[] = {
        0, 1, 2, 3
    };

    int **ptr_ptr = arr_ptr;
    printf("sizeof(arr_ptr) = %ld\n", sizeof(arr_ptr));
    printf("sizeof(ptr_ptr) = %ld\n", sizeof(ptr_ptr));

    return 0;
}
