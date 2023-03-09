#include <stdlib.h>
#include <string.h>

void selection_sort(void *base, size_t n, size_t size,
                    int (*compare)(const void *, const void *)) {
    for (size_t i = 0; i < n - 1; i++) {
        size_t min = i;
        for (size_t j = i + 1; j < n; j++) {
            // The `compare` function will return a negative number
            // if the element at j is relatively less than the element at min.
            // This is our indication to swap the two elements.
            if (compare(base + j * size, base + min * size) < 0) {
                min = j;
            }
        }

        // If the minimum element is not the current element, swap them.
        if (min != i) {
            void *temp = malloc(size);
            memcpy(temp, base + i * size, size);
            memcpy(base + i * size, base + min * size, size);
            memcpy(base + min * size, temp, size);
            free(temp);
        }
    }
}