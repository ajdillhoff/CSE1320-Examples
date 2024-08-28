#include <stdio.h>

int collatz_steps(long long n) {
    int steps = 0;
    
    while (n != 1) {
        if (!n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        printf("%lld", n);
        if (n != 1) {
            printf(" -> ");
        }
        steps++;
    }

    printf("\n");
    
    return steps;
}

int main() {
    long long n = 12;
    int result = collatz_steps(n);
    printf("Number of steps for %lld to reach 1: %d\n", n, result);
    return 0;
}