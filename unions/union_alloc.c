#include <stdio.h>
#include <string.h>
#include <stdlib.h>

union test {
    char *name;
    short val;
    int b;
    double c;
};

int main() {
    union test t;

    printf("sizeof(union test) = %ld\n", sizeof(union test));

    char str[] = "hello";

    t.name = malloc(10 * sizeof(char));
    strcpy(t.name, str);

    printf("t.name = %p\n", t.name);

    t.val = 5;

    printf("t.name = %p\n", t.name);

    printf("name = %s\n", t.name);

    return 0;
}
