#include <stdio.h>
#include <string.h>

#define ITEM_PROPS 4
#define BUFFER_SIZE 1024

void add_item(char raw_input[][BUFFER_SIZE]) {
    printf("Enter item number: ");
    fgets(raw_input[0], BUFFER_SIZE, stdin);
    raw_input[0][strlen(raw_input[0]) - 1] = 0;

    printf("Enter item name: ");
    fgets(raw_input[1], BUFFER_SIZE, stdin);
    raw_input[1][strlen(raw_input[1]) - 1] = 0;

    printf("Enter price: ");
    fgets(raw_input[2], BUFFER_SIZE, stdin);
    raw_input[2][strlen(raw_input[2]) - 1] = 0;

    printf("Enter quantity: ");
    fgets(raw_input[3], BUFFER_SIZE, stdin);
    raw_input[3][strlen(raw_input[3]) - 1] = 0;
}

int write_data(FILE *fp, char raw_input[][BUFFER_SIZE]) {
    if (fp == NULL) {
        return 1;
    }

    // Put item on a new line
    putc('\n', fp);

    for (int i = 0; i < ITEM_PROPS - 1; i++) {
        fputs(raw_input[i], fp);
        putc(',', fp);
    }

    fputs(raw_input[3], fp);

    return 0;
}

int main() {
    char buffer[ITEM_PROPS][BUFFER_SIZE] = { 0 };
    FILE *fp = fopen("prices.csv", "a");

    add_item(buffer);
    write_data(fp, buffer);

    return 0;
}
