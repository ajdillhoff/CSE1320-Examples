#ifndef ARRAY_UTILS_H_
#define ARRAY_UTILS_H_

typedef struct {
  void **data;
  int size;
  int capacity;
} array_t;

array_t *array_new(int capacity);
void array_free(array_t *array, void (*free_func)(void *));
void array_add(array_t *array, void *data);

#endif