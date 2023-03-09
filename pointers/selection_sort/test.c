#include "selection_sort.h"

#include <assert.h>
#include <stdio.h>

int compare_int(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main(void) {
    int a[] = { 3, 1, 2 };
    selection_sort(a, 3, sizeof(int), compare_int);
    assert(a[0] == 1);
    assert(a[1] == 2);
    assert(a[2] == 3);
    printf("Success\n");
}