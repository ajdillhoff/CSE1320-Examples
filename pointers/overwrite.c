#include <stdio.h>

void print_array(const char *name, int *arr, int length) {
    printf("Printing %s\n", name);

    printf("[");
    for (int i = 0; i < length - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[length - 1]);
}

int main() {
    int arr1[10] = { 0 };
    int arr2[] = { 0 };

    printf("arr1: %p\n", arr1);
    printf("arr2: %p\n", arr2);

    for (int i = 0; i < 10; i++) {
        printf("arr1[%d] = ", i);
        scanf("%d", &arr1[i]);
        printf("arr2[%d] = ", i);
        scanf("%d", &arr2[i]);

        print_array("arr1", arr1, 10);
        print_array("arr2", arr2, 10);
    }

    return 0;
}
