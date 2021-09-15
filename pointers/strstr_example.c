#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Find something interesting here.\n";
    char *substr = "something";

    char *key_ptr = strstr(str, substr);
    if (key_ptr != NULL) {
        printf("%s\n", key_ptr);
    }

    return 0;
}
