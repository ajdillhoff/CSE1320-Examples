#include <stdio.h>

int pow2(int a) {
    return a * a;
}

void use_function(int (*fn)(int), int x) {
    printf("Address of fn = %p\n", fn);
    printf("fn(%d) = %d\n", x, fn(x));
}

int main() {
    printf("Address of pow2 = %p\n", pow2);

    use_function(pow2, 10);

    return 0;
}
