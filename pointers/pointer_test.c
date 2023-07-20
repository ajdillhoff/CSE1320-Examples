#include <stdio.h>

int main() {

    int a = 10;
    int *b = &a;
    void **c = &b;

    printf("&a = %p\n", &a);
    printf("b = %p\n", b);
    printf("&b = %p\n", &b);
    printf("c = %p\n", c);
    printf("*c = %p\n", *c);
    printf("**c = %d\n", **((int **)c));

    return 0;
}