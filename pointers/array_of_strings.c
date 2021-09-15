#include <stdio.h>

int main() {
    char *names[] = {
        "Avasarala",
        "Holden",
        "Nagata",
        "Amos",
        "Kamal",
        "Meng",
        "Draper"
    };

    char **names_ptr = names;

    for (int i = 0; i < 7; i++) {
        printf("%s\n", *(names_ptr + i));
    }

    return 0;
}
