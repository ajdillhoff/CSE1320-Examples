#include <stdio.h>
#include <ctype.h>

int skip_whitespace(FILE *fp) {
    int count = 0;
    int c = 0;
    do {
        c = getc(fp);
        count++;
    } while (isspace(c));

    // Put the non-whitespace character back
    ungetc(c, fp);

    return count - 1;
}

int main() {
    int num_numbers = 0;
    char *filename = "whitespace.txt";
    FILE *fp = fopen(filename, "r");

    // Remove whitespace
    int num_spaces = skip_whitespace(fp);
    printf("%d spaces skipped.\n", num_spaces);

    while (1) {
        int c = getc(fp);

        if (feof(fp)) {
            break;
        }
        printf("%c", c);
    }

    return 0;
}
