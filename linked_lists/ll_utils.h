#ifndef LL_UTILS_H_
#define LL_UTILS_H_

#include <stdlib.h>

typedef struct node Node;
struct node {
    void *data;
    Node *next;
};

Node *create_node(void *);
void insert_node(Node **, Node *, int);
void remove_node(Node **, void *, int (*)(const void *, const void *));

#endif // LL_UTILS_H_
