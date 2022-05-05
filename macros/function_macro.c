#include <math.h>
#include <stdio.h>

int ADDED_m;
int SIZE_m;
#define COMPUTE_FACTOR(N, K, M, R, B) (ADDED_m = ceil((double)K/R) + K + M, SIZE_m = ceil(ADDED_m / B), (double)SIZE_m / N)

double compute_resize_factor(int N, int K, int M, int R, double bound) {
    int items_added = ceil((double) K / R) + K + M;
    printf("Based on R = %d, will add %d items total.\n", R, items_added);
    int new_size = ceil((double) items_added / bound);
    return (double)new_size / N;
}

int main() {
    int N = 10;
    int K = 4;
    int M = 5;
    int R = 1;
    double B = 0.7;

    printf("%.2f\n", compute_resize_factor(N, K, M, R, B));
    printf("%.2f\n", COMPUTE_FACTOR(N, K, M, R, B));

    return 0;
}
