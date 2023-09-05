#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Removes the newline character from the string
// Supports both Windows and UNIX style newlines
void trim(char *str) {
    str[strcspn(str, "\r\n")] = 0;
}

// Parses a line of CSV data and prints the tokens.
// Returns the number of tokens read.
int parse_line(char *buffer) {
    int result = 0;

    // Return the first token (this will replace the first comma with a null character)
    char *token = strtok(buffer, ",");

    // Loop through the string while there are still tokens to process
    while (token != NULL) {
        // Since a token was read, increment the result
        result++;
        printf("%-15s ", token);

        // Attempt to read the next token.
        // This will return NULL if there are no more tokens.
        token = strtok(NULL, ",");
    }

    printf("\n");

    return result;
}

int main() {
    char buffer[BUFFER_SIZE] = { 0 };
    FILE *fp = fopen("prices.csv", "r");

    // Ensure the file was opened.
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    // Keep reading each line while there is still data to be read.
    while (fgets(buffer, BUFFER_SIZE, fp)) {
        trim(buffer);
        int num_tokens = parse_line(buffer);

        printf("%d tokens read.\n", num_tokens);
    }

    return 0;
}
