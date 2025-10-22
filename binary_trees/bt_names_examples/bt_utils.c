#include <string.h>

#include "bt_utils.h"

BTNode *add_btnode(User u) {
    BTNode *node = calloc(1, sizeof(BTNode));
    node->user = u;

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
        printf("%s %s\n", temp->user.fname, temp->user.lname);

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
        printf("%s %s\n", root->user.fname, root->user.lname);
    }

    dfs(root->left, t);

    if (t == INORDER) {
        printf("%s %s\n", root->user.fname, root->user.lname);
    }

    dfs(root->right, t);

    if (t == POSTORDER) {
        printf("%s %s\n", root->user.fname, root->user.lname);
    }
}

void insert(BTNode **root, User u) {
    BTNode **temp = root;
    while (*temp != NULL) {
        // Pre-process names for comparison
        User t_user = (*temp)->user;
        char name1[MAX_LEN*2] = { 0 };
        char name2[MAX_LEN*2] = { 0 };
        strcat(name1, u.fname);
        strcat(name1, u.lname);
        strcat(name2, t_user.fname);
        strcat(name2, t_user.lname);

        if (compare_name(u.fname, u.lname, t_user.fname, t_user.lname)) {
            temp = &(*temp)->right;
        } else {
            temp = &(*temp)->left;
        }
    }

    *temp = add_btnode(u);
}

BTNode *search(BTNode *node, char *name) {
    char name1[MAX_LEN*2] = { 0 };
    strcat(name1, node->user.fname);
    strcat(name1, " ");
    strcat(name1, node->user.lname);
    if (node == NULL || !strcmp(name, name1)) {
        return node;
    } else if (strcmp(name, name1) > 0) {
        return search(node->right, name);
    } else {
        return search(node->left, name);
    }
}

void release_tree(BTNode *node) {
    if (node != NULL) {
        release_tree(node->left);
        release_tree(node->right);
        free(node);
    }
}

User *load_users(char *filename) {
    FILE *fp = fopen(filename, "r");
    User *users = calloc(14, sizeof(User));
    char buffer[MAX_LEN * 2] = { 0 };
    int i = 0;

    while (fgets(buffer, MAX_LEN*2, fp)) {
        buffer[strcspn(buffer, "\n")] = 0;

        char *name = strtok(buffer, " ");
        strcpy(users[i].fname, name);

        name = strtok(NULL, " ");
        strcpy(users[i].lname, name);

        i++;
    }

    return users;
}

int compare_name(char *fname1, char *lname1, char *fname2, char *lname2) {
    if (strcmp(lname1, lname2) < 0) {
        return -1;
    } else if (strcmp(lname1, lname2) > 0) {
        return 1;
    }

    if (strcmp(fname1, fname2) < 0) {
        return -1;
    } else if (strcmp(fname1, fname2) > 0) {
        return 1;
    }
}
