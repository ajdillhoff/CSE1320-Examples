#ifndef SELECTION_SORT_H_
#define SELECTION_SORT_H_

#include <stddef.h>

void selection_sort(void *base, size_t n, size_t size,
                    int (*compare)(const void *, const void *));

#endif