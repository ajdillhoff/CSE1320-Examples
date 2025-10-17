#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));
    int val = rand();
    float p = (float) val / RAND_MAX;



    printf("RAND_MAX = %d\n", RAND_MAX);
    printf("Value = %d\n", val % 6 + 1);
    printf("p = %f\n", p * 20);

    return 0;
}