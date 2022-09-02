#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *src = fopen(argv[1], "r");
    FILE *dest = fopen(argv[2], "w");

    char c = 0;

    while ((c = getc(src)) != EOF) {
        fputc(c, dest);
    }

    fclose(src);
    fclose(dest);

    return 0;
}