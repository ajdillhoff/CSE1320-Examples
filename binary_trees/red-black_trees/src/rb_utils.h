#ifndef RB_UTILS_H
#define RB_UTILS_H

#define RED 0
#define BLACK 1

#include <stdio.h>
#include <stdlib.h>

typedef struct RBNode RBNode;
struct RBNode {
    int data;
    unsigned char color;
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

RBNode *add_rbnode(int);
void enqueue(Node **, void *);
Node *dequeue(Node **);
void bfs(RBNode *);
void dfs(RBNode *, traverse_type);
void rotate_left(RBNode **, RBNode *);
void rotate_right(RBNode **, RBNode *);
void insert(RBNode **, RBNode *);
void insert_fixup(RBNode **, RBNode *);
RBNode *search(RBNode *, int);
void release_tree(RBNode *);

#endif  // RB_UTILS_H
