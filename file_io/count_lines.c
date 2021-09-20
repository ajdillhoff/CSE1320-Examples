#include <stdio.h>

#define BUFFER_SIZE 1024

int main() {
    int num_lines = 0;
    char str[BUFFER_SIZE] = { 0 };
    FILE *fp = fopen("data.txt", "r");

    while (!feof(fp)) {
        fgets(str, BUFFER_SIZE, fp);
        num_lines++;
    }

    printf("%d lines in file.\n", num_lines - 1);

    return 0;
}
