#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void clear_newline(char *str) {
    char *pos = NULL;
    if ((pos = strchr(str, '\n')) != NULL) {
        *pos = 0;
    }
}

int main() {
    char *token = NULL;
    char props[] = "NAME,AGE,EMAIL,DOB";
    char input[BUFFER_SIZE] = "Chrisjen,63,avasarala@un.com,12-01-3413";

    // Tokenize Properties and print
    token = strtok(props, ",");
    while (token != NULL) {
        printf("%-20s ", token);
        token = strtok(NULL, ",");
    }
    printf("\n");

    fgets(input, BUFFER_SIZE, stdin);
    clear_newline(input);
    while (strcmp(input, "END")) {
        // Tokenize input and print
        token = strtok(input, ",");
        while (token != NULL) {
            printf("%-20s ", token);
            token = strtok(NULL, ",");
        }
        printf("\n");

        fgets(input, BUFFER_SIZE, stdin);
        clear_newline(input);
    }


    return 0;
}
