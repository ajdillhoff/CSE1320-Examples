#include "bt_utils.h"

BTNode *add_btnode(int data) {
    BTNode *node = calloc(1, sizeof(BTNode));
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

void bfs(BTNode *root) {
    BTNode *temp = root;
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

void dfs(BTNode *root, traverse_type t) {
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

void insert(BTNode **root, int val) {
    BTNode **temp = root;
    while (*temp != NULL) {
        if (val >= (*temp)->data) {
            temp = &(*temp)->right;
        } else {
            temp = &(*temp)->left;
        }
    }

    *temp = add_btnode(val);
}

BTNode *search(BTNode *node, int val) {
    if (node == NULL || val == node->data) {
        return node;
    } else if (val > node->data) {
        return search(node->right, val);
    } else {
        return search(node->left, val);
    }
}

void release_tree(BTNode *node, void (*free_data)(void *)) {
    if (node != NULL) {
        release_tree(node->left, free_data);
        release_tree(node->right, free_data);
        free_data(node->data);
        free(node);
    }
}
