#include <stdio.h>

#ifdef DEBUG
#define printd(format, ...) printf("[DEBUG] "); printf(format, ##__VA_ARGS__);
#else
#define printd(s)
#endif

int main() {
    printf("This should always print.\n");

    printd("This will only print if DEBUG is defined!\n");

    return 0;
}
