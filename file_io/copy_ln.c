#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("USAGE: copy_ln SRC_FILE DEST_FILE\n");
        return 1;
    }

    int line_number = 1;
    char buffer[BUFFER_SIZE] = { 0 };
    FILE *src_fp = fopen(argv[1], "r");
    FILE *dest_fp = fopen(argv[2], "w");

    if (src_fp == NULL) {
        printf("Could not open source file for reading.\n");
        return 1;
    } else if (dest_fp == NULL) {
        printf("Could not open destination file for writing.\n");
        return 1;
    }

    while (!feof(src_fp)) {
        char ln_buff[BUFFER_SIZE] = { 0 };
        char *read_result = fgets(buffer, BUFFER_SIZE, src_fp);

        if (read_result == NULL) {
            break;
        }

        sprintf(ln_buff, "%d: ", line_number++);
        fputs(ln_buff, dest_fp);

        while (read_result != NULL && buffer[strlen(buffer) - 1] != '\n') {
            fputs(buffer, dest_fp);
            read_result = fgets(buffer, BUFFER_SIZE, src_fp);
        }

        printf("[DEBUG] read_result = %p\n", read_result);

        if (read_result != NULL) {
            fputs(buffer, dest_fp);
        }
    }

    // Close files
    fclose(src_fp);
    fclose(dest_fp);

    return 0;
}
