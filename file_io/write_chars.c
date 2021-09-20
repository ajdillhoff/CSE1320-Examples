#include <stdio.h>

int main() {
    FILE *fp = fopen("data1.txt", "w");
    char c = 0;

    while ((c = getchar()) != '\n') {
        putc(c, fp);
    }

    return 0;
}
