#include <stdlib.h>

typedef struct {
    void **data;
    int numel;
    int capacity;
} array_s;

int add(void *, array_s *, int);
int push(void *, array_s *);
void *pop_p(array_s *, int);
void *pop(array_s *);