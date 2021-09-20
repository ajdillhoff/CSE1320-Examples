#include <stdio.h>

int main() {
    FILE *fp = fopen("formatted_data.txt", "w");

    fprintf(fp, "%d %f %c %s", 10, 0.5, '?', "even a whole string\n");

    fclose(fp);

    return 0;
}
