#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    if (argc != 3) {
        printf("USAGE: ./a.out file1 file2\n");
        return 1;
    }

    FILE *src = fopen(argv[1], "rb");

    if (src == NULL) {
        printf("Couldn't open file %s.\n", argv[1]);
        return 1;
    }

    FILE *dest = fopen(argv[2], "w");

    char c = 0;

    while ((c = getc(src)) != EOF) {
        fputc(c, dest);
    }

    fclose(src);
    fclose(dest);

    return 0;
}