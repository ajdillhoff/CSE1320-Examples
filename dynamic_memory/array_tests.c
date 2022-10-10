#include <stdio.h>

#include "array_utils.h"

void print_data(array_s arr) {
    for (int i = 0; i < arr.numel; i++) {
        int value = *(int *) arr.data[i];
        printf("%d. %d\n", i, value);
    }
}

int main() {
    array_s arr = { 0 };
    int test_value = 100;

    add(&test_value, &arr);

    print_data(arr);

    return 0;
}