#ifndef RB_UTILS_H
#define RB_UTILS_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_HEIGHT 1000
#define BUFFER_SIZE 32

typedef enum {
    RED,
    BLACK
} color_t;

typedef struct RBNode RBNode;
struct RBNode {
    int data;
    color_t color;
    RBNode *p;
    RBNode *left;
    RBNode *right;
};

typedef struct {
    RBNode *root;
} RBTree;

typedef struct {
    int height;
    int width;
    char **buffer;
} print_buffer;

RBNode *add_rbnode(int);
void print_tree(RBTree *);
void rotate_left(RBTree*, RBNode *);
void rotate_right(RBTree *, RBNode *);
void insert(RBTree *, RBNode *);
void insert_fixup(RBTree *, RBNode *);
void delete_node(RBTree *, RBNode *);
RBNode *search(RBNode *, int);
void free_tree(RBNode *);

#endif  // RB_UTILS_H
