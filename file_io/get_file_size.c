#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("USAGE: ./a.out filename\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (!fp) {
        printf("Couldn't open file \"%s\"\n", argv[1]);
        return 1;
    }

    fseek(fp, 0, SEEK_END);

    long size = ftell(fp);

    printf("File size: %ld\n", size);

    fclose(fp);

    return 0;
}