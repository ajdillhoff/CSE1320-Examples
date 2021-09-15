#include <stdio.h>
#include <string.h>

typedef int (*choose_ptr)(int, int);

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int divide(int a, int b) {
    return a / b;
}

int multiply(int a, int b) {
    return a * b;
}

// This is not very readable...
/*int (*choose_op(char *c))(int, int) {*/
    /*if (!strcmp(c, "add")) {*/
        /*return add;*/
    /*}*/
/*}*/

// This is much more readable
choose_ptr choose_op(char *c) {
    if (!strcmp(c, "add")) {
        return add;
    }
}

int main() {
    char *op = "add";

    int (*fn)(int, int) = choose_op(op);
    int fn_value = choose_op(op)(10, 10);

    printf("fn(10, 3) = %d\n", fn(10, 3));
    printf("fn_value = %d\n", fn_value);

    return 0;
}
