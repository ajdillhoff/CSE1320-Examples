#include <stdio.h>

int main() {
    int val = 5;
    int *ptr = &val;

    printf("%p\n", ptr);
    printf("%d\n", *ptr);
    printf("%d\n", *ptr + 1);
    printf("%d\n", *(ptr + 1));
    printf("%d\n", (*ptr) + 1);
    printf("%p\n", *&ptr);
    printf("%p\n", &ptr);
    printf("%p\n", &ptr + 1);
}
