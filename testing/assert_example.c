#include <assert.h>
#include <stdio.h>

int add_numbers(int a, int b, int c) {
    return a + b + c;
}

int main() {
    assert(add_numbers(1, 2, 3) == 5);

    printf("Success!\n");

    return 0;
}