#include <stdio.h>

int main() {
    int arr[10] = { 0 };
    for (int i = 0; i < 10; i++) {
        *(arr + i) = i;
    }

    printf("arr[4] = %d\n", arr[4]);
    printf("*(arr + 4) = %d\n", *(arr + 4));

    return 0;
}
