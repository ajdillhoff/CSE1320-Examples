#include <stdio.h>
#include <string.h>

int main() {
    char *token = NULL;
    char props[] = "NAME,AGE,EMAIL,DOB";
    char input[] = "Chrisjen,63,avasarala@un.com,12-01-3413";

    // Tokenize Properties and print
    token = strtok(props, ",");
    while (token != NULL) {
        printf("%-20s ", token);
        token = strtok(NULL, ",");
    }
    printf("\n");

    // Tokenize input and print
    token = strtok(input, ",");
    while (token != NULL) {
        printf("%-20s ", token);
        token = strtok(NULL, ",");
    }
    printf("\n");

    return 0;
}
