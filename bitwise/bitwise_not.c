/*
 * Example of applying the bitwise NOT operator.
 */
#include <stdio.h>

void print_binary_char(char a) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (a >> i) & 1);
    }
    printf("\n");
}

void print_twos_complement(char a) {
    printf("Two's Complement of %d\n", a);
    print_binary_char(-a);
}

int main() {
    int val = 10;

    // Applying a bitwise NOT to the value 10 (00001010) will yield -11 (11110110).
    printf("~val = %d\n", ~val);

    print_binary_char(~val);

    // Why does 11110101 equal -11?
    // Recall the Two's complement representation
    print_twos_complement(val);

    return 0;
}
