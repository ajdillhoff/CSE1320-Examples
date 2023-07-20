#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void trim(char *str) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

int parse_line(char *buffer) {
    int result = 0;
    char *token = strtok(buffer, ",");

    while (token != NULL) {
        result++;
        printf("%-15s ", token);
        token = strtok(NULL, ",");
    }

    printf("\n");

    return result;
}

int main() {
    char buffer[BUFFER_SIZE] = { 0 };
    FILE *fp = fopen("prices.csv", "r");

    while (fgets(buffer, BUFFER_SIZE, fp)) {
        trim(buffer);
        int num_tokens = parse_line(buffer);

        printf("%d tokens read.\n", num_tokens);
    }

    return 0;
}
