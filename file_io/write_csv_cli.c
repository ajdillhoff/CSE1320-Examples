#include <stdio.h>
#include <string.h>

#define ITEM_PROPS 4

void trim(char *str) {
    str[strcspn(str, "\r\n")] = 0;
}

int write_data(FILE *fp, char *raw_input[]) {
    if (fp == NULL) {
        return 1;
    }

    // Put item on a new line
    putc('\n', fp);

    for (int i = 1; i < ITEM_PROPS; i++) {
        fputs(raw_input[i], fp);
        putc(',', fp);
    }

    fputs(raw_input[ITEM_PROPS], fp);

    return 0;
}

int main(int argc, char *argv[]) {

    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    FILE *fp = fopen("prices.csv", "a");

    write_data(fp, argv);

    return 0;
}
