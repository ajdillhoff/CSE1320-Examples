#include <stdio.h>
#include <stdlib.h>

double *push(double val, int size, double *arr) {
    arr = realloc(arr, (size + 1) * sizeof(double));
    arr[size] = val;

    return arr;
}

double *pop(double *arr, int size) {
    arr = realloc(arr, (size - 1) * sizeof(double));

    return arr;
}

int main() {
    double *arr = NULL;

    return 0;
}
