#include "rb_utils.h"

RBNode *add_rbnode(int data) {
    RBNode *node = calloc(1, sizeof(RBNode));
    node->data = data;

    return node;
}

void enqueue(Node **queue, void *data) {
    if (*queue == NULL) {
        *queue = calloc(1, sizeof(Node));
        (*queue)->data = data;

        return;
    }

    Node *temp = *queue;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = calloc(1, sizeof(Node));
    temp->next->data = data;
}

Node *dequeue(Node **queue) {
    Node *n = *queue;
    *queue = (*queue)->next;

    return n;
}

void bfs(RBNode *root) {
    RBNode *temp = root;
    Node *n = NULL;
    Node *queue = NULL;
    enqueue(&queue, temp);
    while (queue != NULL) {
        n = dequeue(&queue);
        temp = n->data;
        printf("%d\n", temp->data);

        if (temp->left != NULL) {
            enqueue(&queue, temp->left);
        }

        if (temp->right != NULL) {
            enqueue(&queue, temp->right);
        }

        free(n);
    }
}

void dfs(RBNode *root, traverse_type t) {
    if (root == NULL) {
        return;
    }

    if (t == PREORDER) {
        printf("%d\n", root->data);
    }

    dfs(root->left, t);

    if (t == INORDER) {
        printf("%d\n", root->data);
    }

    dfs(root->right, t);

    if (t == POSTORDER) {
        printf("%d\n", root->data);
    }
}

void rotate_left(RBNode **root, RBNode *x) {
    RBNode *y = x->right;
    x->right = y->left;
    if (y->left != NULL) {
        y->left->p = x;
    }
    y->p = x->p;

    if (x->p == NULL) {
        *root = y;
    } else if (x == x->p->left) {
        x->p->left = y;
    } else {
        x->p->right = y;
    }

    y->left = x;
    x->p = y;
}

void rotate_right(RBNode **root, RBNode *x) {
    RBNode *y = x->left;
    x->left = y->right;
    if (y->right != NULL) {
        y->right->p = x;
    }
    y->p = x->p;

    if (x->p == NULL) {
        *root = y;
    } else if (x == x->p->left) {
        x->p->left = y;
    } else {
        x->p->right = y;
    }

    y->right = x;
    x->p = y;
}

void insert(RBNode **root, RBNode *z) {
    RBNode *y = NULL;
    RBNode *x = *root;
    while (x != NULL) {
        y = x;
        if (z->data >= x->data) {
            x = x->right;
        } else {
            x = x->left;
        }
    }

    z->p = y;

    if (y == NULL) {
        *root = z;
    } else if (z->data < y->data) {
        y->left = z;
    } else {
        y->right = z;
    }

    insert_fixup(root, z);
}

void insert_fixup(RBNode **root, RBNode *z) {
    RBNode *y = NULL;
    while (z->p && z->p->color == RED) {
        if (z->p == z->p->p->left) {
            // z is on the left side of the tree
            y = z->p->p->right;
            // Case 1
            if (y && y->color == RED) {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            } else {
                // Case 2
                if (z == z->p->right) {
                    z = z->p;
                    rotate_left(root, z);
                }
                // Case 3
                z->p->color = BLACK;
                z->p->p->color = RED;
                rotate_right(root, z->p->p);
            }
        } else {
            // z is on the right side of the tree
        }
    }

    (*root)->color = BLACK;
}

RBNode *search(RBNode *node, int val) {
    if (node == NULL || val == node->data) {
        return node;
    } else if (val > node->data) {
        return search(node->right, val);
    } else {
        return search(node->left, val);
    }
}

void release_tree(RBNode *node) {
    if (node != NULL) {
        release_tree(node->left);
        release_tree(node->right);
        free(node);
    }
}
