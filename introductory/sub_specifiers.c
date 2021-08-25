/*
 * Provides examples of using sub-specifiers in formatted output.
 */

#include <stdio.h>

int main() {
    // Provide a fixed width to the output
    printf("Fixed width of 10, padded with spaces, right-justified (default):\n");
    printf("%10d\n", 10);

    // Provide a fixed width with left justification
    printf("\nFixed width of 10, padded with spaces, left-justified:\n");
    printf("%-10d\n", 10);

    // Pad the fixed width with 0 instead of space
    printf("\nFixed with of 10, padded with zeros:\n");
    printf("%010d\n", 10);

    // Write a positive + if value is positive or negative - if value is negative
    printf("\nForce a '+' if value is positive:\n");
    printf("%+d\n", 10);

    // Truncate a decimal to a fixed number of values
    printf("\nTruncate a decimal to a fixed number of values:\n");
    printf("%.2f\n", 6.2351);

    // Truncate a decimal to a dynamic number of values
    int n = 3;
    printf("\nTruncate a decimal to a dynamic number of values:\n");
    printf("%.*f\n", n, 6.2351);

    // Set fixed with dynamically
    printf("\nSet fixed width dynamically:\n");
    printf("%*d\n", n, 10);

    return 0;
}
