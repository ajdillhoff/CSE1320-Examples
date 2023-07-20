#include <stdio.h>

void arr_test(int *arr, int size) {
    printf("%ld\n", sizeof(arr));
}

int main() {
    int arr[10] = { 0 };

    arr_test(arr, 10);
    int *a_ptr = arr;
    for (int i = 0; i < 10; i++) {
        *(arr + i) = i;
        arr[i] = i;
        a_ptr[i] = i;
    }

    printf("arr[4] = %d\n", a_ptr[4]);
    printf("*(arr + 4) = %d\n", *(arr + 4));

    return 0;
}
