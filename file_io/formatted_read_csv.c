#include <stdio.h>

int main(int argc, char **argv) {
    FILE *fp = fopen(argv[1], "w");

    fprintf(fp, "%s,%s,%s,%s\n", argv[2], argv[3], argv[4], argv[5]);

    fclose(fp);

    return 0;
}
