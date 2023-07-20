#include <stdio.h>


void print_binary_char(unsigned char a) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (a >> i) & 1);
    }
    printf("\n");
}

void read_binary_data(FILE *fp) {
    unsigned char byte = 0;
    int num_bytes = 0;

    // Make sure we are at the beginning of the file.
    rewind(fp);

    while (fread(&byte, sizeof(unsigned char), 1, fp)) {
        printf("byte %d: %3d 0x%02X ", num_bytes++, byte, byte);
        print_binary_char(byte);
    }

    printf("%d bytes in file.\n", num_bytes);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("USAGE: ./a.out FILENAME\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");

    if (!fp) {
        printf("Cannot open file.\n");
        return 1;
    }

    read_binary_data(fp);

    fclose(fp);

    return 0;
}
