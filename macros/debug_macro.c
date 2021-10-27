#include <stdio.h>

#ifdef DEBUG
#define printd(s) printf("[DEBUG] %s\n", s);
#else
#define printd(s)
#endif

int main() {
    printf("This should always print.\n");

    printd("This will only print if DEBUG is defined!");

    return 0;
}
