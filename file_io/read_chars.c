#include <stdio.h>

int main() {
    FILE *fp = fopen("data.txt", "r");
    char c = 0;

    while ((c = getc(fp)) != EOF) {
        printf("%c", c);
    }

    return 0;
}
