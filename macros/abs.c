#include <stdio.h>

int ABS_x;
#define ABS(x) x < 0 ? -x : x
#define ABS_safe(x) (ABS_x = x, ABS_x < 0 ? -ABS_x : ABS_x)

int main() {

    printf("ABS(-10) = %d\n", ABS(-10));
    printf("ABS(5 - 10) = %d\n", ABS(5 - 10));
    int a = 0;
    printf("ABS(a--) = %d\n", ABS(a--));
    a = 0;
    printf("ABS_safe(a--) = %d\n", ABS_safe(a--));

    return 0;
}
