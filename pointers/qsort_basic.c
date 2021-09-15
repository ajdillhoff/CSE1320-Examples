#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int numel) {
    for (int i = 0; i < numel; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// They values must be cast to a valid pointer type.
// We dereference a void * since the result of that operation would produce `void`.
int compare(const void *elem1, const void *elem2) {
    int *a = (int *)elem1;
    int *b = (int *)elem2;
    return *a - *b;
}

int main() {
    int arr[10] = { 13, 2, 1, -5, 0, 3, 10, -3, -7, 3 };

    printf("Before qsort\n");
    print_array(arr, 10);

    qsort(arr, 10, sizeof(int), compare);

    printf("After qsort\n");
    print_array(arr, 10);

    return 0;
}
