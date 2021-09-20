#include <stdio.h>
#include <string.h>

int check_jpeg(FILE *fp) {
    unsigned char buffer[4] = { 0 };
    unsigned char *signature = "\xFF\xD8\xFF";

    fgets(buffer, 4, fp);

    return strcmp(buffer, signature);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("USAGE: jpeg_check FILENAME.png\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("ERROR: File Not Found\n");
        return 1;
    }

    if (!check_jpeg(fp)) {
        printf("%s is a JPEG.\n", argv[1]);
    } else {
        printf("%s is not a JPEG.\n", argv[1]);
    }

    fclose(fp);

    return 0;
}
