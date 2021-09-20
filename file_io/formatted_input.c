#include <stdio.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    FILE *fp = NULL;
    long id = 0;
    char name[BUFFER_SIZE] = { 0 };
    double price = 0;
    char buffer[BUFFER_SIZE] = { 0 };

    if (argc == 1) {
        printf("USAGE: formatted_input FILENAME\n");
        return 1;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        sscanf(buffer, "%ld %s %lf%*c", &id, name, &price);

        printf("ID:\t%ld\nName:\t%s\nPrice:\t%4.2f\n", id, name, price);
    }

    fclose(fp);

    return 0;
}
