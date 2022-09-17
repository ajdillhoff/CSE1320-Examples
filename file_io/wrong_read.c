#include <stdio.h>

int main() {

    FILE *fp = fopen("data.txt", "r");

    // feof should be a check that occurs AFTER a read.
    while (!feof(fp)) {
        char c = getc(fp);
        printf("%c", c);
    }

    fclose(fp);

    return 0;
}
