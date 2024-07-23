#include "selection_sort.h"

#include <assert.h>
#include <stdio.h>

int compare_int(const void *elem1, const void *elem2) {
    int *a = (int *)elem1;
    int *b = (int *)elem2;
    return *a - *b;
}

int main(void) {
    int a[] = { 3, 1, 4, 2 };
    selection_sort(a, 4, sizeof(int), compare_int);
    assert(a[0] == 1);
    assert(a[1] == 2);
    assert(a[2] == 3);
    assert(a[3] == 4);
    printf("Success\n");
}