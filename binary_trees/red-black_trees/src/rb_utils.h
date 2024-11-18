#ifndef RB_UTILS_H
#define RB_UTILS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct RBNode RBNode;
struct RBNode {
    int data;
    RBNode *p;
    RBNode *left;
    RBNode *right;
};

typedef struct Node Node;
struct Node {
    void *data;
    Node *next;
};

typedef enum {
    PREORDER,
    INORDER,
    POSTORDER
} traverse_type;

RBNode *add_btnode(int);
void enqueue(Node **, void *);
Node *dequeue(Node **);
void bfs(RBNode *);
void dfs(RBNode *, traverse_type);
void rotate_left(RBNode **root, RBNode *x);
void rotate_right(RBNode **root, RBNode *x);
void insert(RBNode **, int);
RBNode *search(RBNode *, int);
void release_tree(RBNode *);

#endif  // RB_UTILS_H
