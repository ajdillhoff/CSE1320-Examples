#include <stdio.h>
#include <string.h>

#define ITEM_PROPS 4
#define BUFFER_SIZE 1024

void trim(char *str) {
    str[strcspn(str, "\r\n")] = 0;
}

void add_item(char raw_input[][BUFFER_SIZE]) {
    printf("Enter item number: ");
    fgets(raw_input[0], BUFFER_SIZE, stdin);
    trim(raw_input[0]);

    printf("Enter item name: ");
    fgets(raw_input[1], BUFFER_SIZE, stdin);
    trim(raw_input[1]);

    printf("Enter price: ");
    fgets(raw_input[2], BUFFER_SIZE, stdin);
    trim(raw_input[2]);

    printf("Enter quantity: ");
    fgets(raw_input[3], BUFFER_SIZE, stdin);
    trim(raw_input[3]);
}

int write_data(FILE *fp, char raw_input[][BUFFER_SIZE]) {
    if (fp == NULL) {
        return 1;
    }

    // Put item on a new line
    putc('\n', fp);

    fprintf(fp, "%s,%s,%s,%s", raw_input[0], raw_input[1], raw_input[2],
            raw_input[3]);

    /* Alternative using fputs */
    // for (int i = 0; i < ITEM_PROPS - 1; i++) {
    //     fputs(raw_input[i], fp);
    //     putc(',', fp);
    // }

    // fputs(fp, raw_input[ITEM_PROPS - 1]);

    return 0;
}

int main() {
    char buffer[ITEM_PROPS][BUFFER_SIZE] = { 0 };
    FILE *fp = fopen("prices.csv", "a");

    add_item(buffer);
    write_data(fp, buffer);

    return 0;
}
