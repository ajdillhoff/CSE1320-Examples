#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int parse_line(char *buffer) {
    int result = 0;
    char *token = strtok(buffer, ",");

    while (token != NULL) {
        result++;
        printf("%-25s ", token);
        token = strtok(NULL, ",");
    }

    printf("\n");

    return result;
}

int main() {
    char buffer[BUFFER_SIZE] = { 0 };
    char cpy[BUFFER_SIZE] = { 0 };
    FILE *fp = fopen("prices.csv", "r");

    while (!feof(fp)) {
        fgets(buffer, BUFFER_SIZE, fp);
        if (buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = 0;
        }
        parse_line(buffer);
    }

    return 0;
}
