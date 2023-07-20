#ifndef BT_UTILS_H
#define BT_UTILS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode BTNode;
struct BTNode {
    void *data;
    BTNode *left;
    BTNode *right;
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

BTNode *add_btnode(int);
void enqueue(Node **, void *);
Node *dequeue(Node **);
void bfs(BTNode *);
void dfs(BTNode *, traverse_type);
void insert(BTNode **, int);
BTNode *search(BTNode *, int);
void release_tree(BTNode *, void (*release)(void *));

#endif  // BT_UTILS_H
