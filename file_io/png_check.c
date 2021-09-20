#include <stdio.h>
#include <string.h>

int check_png(FILE *fp) {
    unsigned char buffer[8] = { 0 };
    unsigned char *png_signature = "\211PNG\r\n\032\n";

    fgets(buffer, 8, fp);

    for (int i = 0; i < 8; i++) {
        printf("%d %d\n", buffer[i], png_signature[i]);
    }

    return strcmp(buffer, png_signature);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("USAGE: png_check FILENAME.png\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("ERROR: File Not Found\n");
        return 1;
    }

    if (!check_png(fp)) {
        printf("File is PNG.\n");
    } else {
        printf("File is not PNG.\n");
    }

    fclose(fp);

    return 0;
}
