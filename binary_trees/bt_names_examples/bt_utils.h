#ifndef BT_UTILS_H
#define BT_UTILS_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 32

typedef struct {
    char fname[MAX_LEN];
    char lname[MAX_LEN];
} User;

typedef struct BTNode BTNode;
struct BTNode {
    User user;
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

BTNode *add_btnode(User);
void enqueue(Node **, void *);
Node *dequeue(Node **);
void bfs(BTNode *);
void dfs(BTNode *, traverse_type);
void insert(BTNode **, User);
BTNode *search(BTNode *, char *);
void release_tree(BTNode *);
User *load_users(char *);
int compare_name(char *, char *, char *, char *);

#endif  // BT_UTILS_H
