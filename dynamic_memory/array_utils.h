#include <stdlib.h>

typedef struct {
    void **data;
    int numel;
    int capacity;
} array_s;

int add(void *data, array_s *arr, int pos);
int push(void *data, array_s *arr);
void *pop_p(array_s *, int);
void *pop(array_s *);