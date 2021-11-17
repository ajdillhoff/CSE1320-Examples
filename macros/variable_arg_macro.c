#include <stdio.h>
#include <string.h>

#ifdef DEBUG
#define printd(str, args...) printf("[DEBUG] "); printf(str, args)
#else
#define printd(str, args...)
#endif

int main() {

    printd("Testing %d %.2lf\n", 10, 5.2);

    return 0;
}
