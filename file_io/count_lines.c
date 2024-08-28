#include <stdio.h>

#define BUFFER_SIZE 1024

int main() {
    int num_lines = 0;
    char str[BUFFER_SIZE] = { 0 };
    FILE *fp = fopen("data.txt", "r");

    if (fp == NULL) {
        printf("Couldn't open the file.\n");
        return 1;
    }

    while (fgets(str, BUFFER_SIZE, fp)) {
        num_lines++;
    }

    printf("%d lines in file.\n", num_lines);

    fclose(fp);

    return 0;
}
