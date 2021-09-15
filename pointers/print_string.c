#include <stdio.h>

void print_string(const char *str) {
    while (*str != 0) {
        printf("%c", *str++);
    }
}

int main() {
    char str[] = "You were right about that thing on Ganymede, Ma\'am.\n";

    print_string(str);
}
