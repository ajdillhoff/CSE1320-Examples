#include <stdio.h>

int main() {
    FILE *fp = fopen("data.txt", "r");
    char c = 0;

    if (fp == NULL) {
        printf("Couldn't open file.\n");
        return 1;
    }

    while ((c = getc(fp)) != EOF) {
        printf("%c", c);
    }

    return 0;
}
