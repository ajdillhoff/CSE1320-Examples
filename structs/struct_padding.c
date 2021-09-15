#include <stdio.h>

struct __attribute__((__packed__)) test_t {
    char a;
    int b;
};

int main() {
    printf("%ld\n", sizeof(struct test_t));

    return 0;
}
