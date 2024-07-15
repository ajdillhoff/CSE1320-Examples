#include <stdio.h>

int main() {
    // Open the file for writing from the beginning of the file
    FILE *f = fopen("my_file", "w");

    if (f) {
        fclose(f);
    }

    // If the file doesn't exist, a segmentation fault occurs
    f = fopen("my_file", "r");

    // Do some stuff with the file

    fclose(f);

    return 0;
}
