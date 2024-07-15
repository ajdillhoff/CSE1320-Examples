#include <stdio.h>
#include <string.h>

int main() {
    int *arr_ptr[] = {
        (int *)0, (int *)1, (int *)2, (int *)3
    };

    int **ptr_ptr = arr_ptr;
    printf("sizeof(arr_ptr) = %ld\n", sizeof(arr_ptr));
    printf("sizeof(ptr_ptr) = %ld\n", sizeof(ptr_ptr));

    return 0;
}
