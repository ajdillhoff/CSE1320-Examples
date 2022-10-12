#include <stdlib.h>

typedef struct {
    void **data;
    int numel;
} array_s;

int add(void *data, array_s *arr);
void *pop_p(array_s *, int);
void *pop(array_s *);