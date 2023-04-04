#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "utils.h"

void trim(char *str) {
    str[strcspn(str, "\r\n")] = 0;
}

char *read_string(FILE *restrict stream) {
    char *line = NULL;
    size_t size = 0;

    size_t num_read = getline(&line, &size, stream);

    if (num_read == (size_t) -1) {
        free(line);
        return NULL;
    }

    // If the string is shorter than the capacity, we can free the extra memory.
    if (num_read + 1 < size) {
        line = realloc(line, num_read + 1);
    }

    return line;
}