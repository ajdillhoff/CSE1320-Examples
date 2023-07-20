#include <stdio.h>

#define MIN(a, b) (a < b) ? a : b
#define MAX(a, b) (a > b) ? a : b

int main() {
    printf("MIN(10, 5) = %d\n", MIN(10, 5));
    printf("MAX(-0.5 + 3.3, 3.2) = %.2f\n", MAX(-0.5 + 3.3, 3.2));

    return 0;
}
