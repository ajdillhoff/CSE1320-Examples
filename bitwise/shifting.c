/*
 * Examples of applying bitwise shifting in C.
 */

#include <stdio.h>

int main() {
    // Using `char` since it is easier to conceptualize 8 bits.
    char val = 10;  // binary: 00001010

    printf("Original value: %d\n", val);

    // Shift the value to the left by 1
    // The result in binary is 00010100 (20 in base 10).
    val = val << 1;

    printf("Shifted left by 1: %d\n", val);

    // The value was effectively multiplied by 2!
    // Shift again...
    val = val << 1;

    printf("Shift again by 1: %d\n", val);

    // Let's shift the other way
    val = val >> 1;

    printf("Shifted right by 1: %d\n", val);

    // This had the effect of dividing by 2

    return 0;
}
