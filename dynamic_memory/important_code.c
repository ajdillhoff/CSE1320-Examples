#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array = NULL;

    array = malloc(128 * sizeof(int));

    for (int i = 0; i < 128; i++) {
        *(array + i) = i + 1;
    }

    for (int i = 0;i < 128; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }

    free(array);

    return 0;
}