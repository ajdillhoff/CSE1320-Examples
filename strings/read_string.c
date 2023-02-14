/*
 * An educational attempt at replicating `getline`.
 * More information: https://stackoverflow.com/questions/20036074/length-of-line-in-getline-function-c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 32

/*
 * A clone of `getline`
 */
ssize_t getline2(char **restrict lineptr, size_t *restrict n, FILE *restrict stream) {
    ssize_t num_read = 0;

    // Set a default size for the buffer if none is given.
    if (*n == 0) {
        *n = BUFSIZE;
    }

    // Allocate memory for the buffer if none is given.
    if (*lineptr == NULL) {
        *lineptr = calloc(*n, sizeof(char));
    }

    // Read from the stream until we reach the end of the file or a newline.
    while (fgets(*lineptr + num_read, BUFSIZE, stream)) {
        num_read = strlen(*lineptr);

        // If we read less than the buffer size, we must have reached the end of the file.
        if (num_read + 1 < *n) break;

        // Otherwise, we need to increase the size of the buffer.
        *n += BUFSIZE;
        *lineptr = realloc(*lineptr, *n);
    }

    return num_read;
}

/*
 * Uses getline2 to read a string of arbitrary length from the given file stream.
 */
char *read_string(FILE *restrict stream) {
    char *line = NULL;
    size_t size = 0;

    ssize_t num_read = getline2(&line, &size, stream);

    if (num_read == -1) {
        free(line);
        return NULL;
    }

    // `getline2` will allocate memory in chunks of `BUFSIZE`.
    // If the string is shorter than the capacity, we can free the extra memory.
    if (num_read + 1 < size) {
        line = realloc(line, num_read + 1);
    }

    return line;
}

int main() {
    char *line = NULL;
    size_t size = 0;

    ssize_t num_read = getline2(&line, &size, stdin);

    printf("Line: %s\nSize: %ld\nCapacity: %ld\n", line, num_read, size);

    free(line);

    // Test read_string
    line = read_string(stdin);

    if (line == NULL) {
        return 1;
    }

    printf("Line: %s\nLength: %ld\n", line, strlen(line));

    free(line);

    return 0;
}
