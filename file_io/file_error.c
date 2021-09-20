#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *f = NULL;
    int errnum = 0;

    f = fopen("test.txt", "r");

    if (f == NULL) {
        printf("[ERROR] File could not be opened (errno %d).\n", errno); // from errno.h
        printf("%s\n", strerror(errno)); // from string.h

        return errno;
    } else {
        fclose(f);
    }

    return 0;
}
