#include "rb_utils.h"
#include <string.h>
#include <stdlib.h>


int get_tree_height(RBNode *node) {
    if (!node) return 0;
    int left = get_tree_height(node->left);
    int right = get_tree_height(node->right);
    return 1 + (left > right ? left : right);
}

print_buffer* create_buffer(int height) {
    print_buffer *pb = malloc(sizeof(print_buffer));
    pb->height = height * 3;  // Increased height multiplier
    pb->width = 1 << (height + 3);  // Increased width
    pb->buffer = malloc(pb->height * sizeof(char*));
    
    for (int i = 0; i < pb->height; i++) {
        pb->buffer[i] = calloc(pb->width + 1, sizeof(char));
        memset(pb->buffer[i], ' ', pb->width);
        pb->buffer[i][pb->width] = '\0';
    }
    return pb;
}

void free_buffer(print_buffer *pb) {
    for (int i = 0; i < pb->height; i++) {
        free(pb->buffer[i]);
    }
    free(pb->buffer);
    free(pb);
}

void print_node(RBNode *node, int row, int col, int level, int height, 
                      print_buffer *pb) {
    if (!node) return;

    // Calculate spacing based on level
    int gap = 3 << (height - level - 1);
    int left_pos = col - gap;
    int right_pos = col + gap;

    // Print value
    char value[BUFFER_SIZE];
    snprintf(value, BUFFER_SIZE, "%d(%c)", node->data, node->color == RED ? 'R' : 'B');
    int len = strlen(value);
    int start = col - len/2;
    if (start >= 0 && start + len < pb->width) {
        memcpy(&pb->buffer[row][start], value, len);
    }

    if (node->left) {
        if (row + 1 < pb->height && left_pos >= 0) {
            // Draw left connection
            for (int i = left_pos + 1; i < col; i++) {
                pb->buffer[row + 1][i] = '-';
            }
            pb->buffer[row + 1][left_pos + 1] = '+';
            pb->buffer[row + 1][col] = '+';
            pb->buffer[row + 2][left_pos + 1] = '|';
        }
        print_node(node->left, row + 3, left_pos + 1, level + 1, height, pb);
    }

    if (node->right) {
        if (row + 1 < pb->height && right_pos < pb->width) {
            // Draw right connection
            for (int i = col + 1; i < right_pos; i++) {
                pb->buffer[row + 1][i] = '-';
            }
            pb->buffer[row + 1][col] = '+';
            pb->buffer[row + 1][right_pos - 1] = '+';
            pb->buffer[row + 2][right_pos - 1] = '|';
        }
        print_node(node->right, row + 3, right_pos - 1, level + 1, height, pb);
    }
}

void print_tree(RBTree *tree) {
    if (!tree || !tree->root) {
        printf("Empty tree\n");
        return;
    }

    int height = get_tree_height(tree->root);
    print_buffer *pb = create_buffer(height);
    
    print_node(tree->root, 0, pb->width/2, 0, height, pb);

    // Print and trim trailing spaces
    for (int i = 0; i < pb->height; i++) {
        char *line = pb->buffer[i];
        int j = pb->width - 1;
        while (j >= 0 && line[j] == ' ') {
            line[j] = '\0';
            j--;
        }
        if (strlen(line) > 0) {
            printf("%s\n", line);
        }
    }

    free_buffer(pb);
}

RBNode *add_rbnode(int data) {
    RBNode *node = calloc(1, sizeof(RBNode));
    node->data = data;

    return node;
}

void rotate_left(RBTree *tree, RBNode *x) {
    RBNode *y = x->right;
    x->right = y->left;
    if (y->left != NULL) {
        y->left->p = x;
    }
    y->p = x->p;

    if (x->p == NULL) {
        tree->root = y;
    } else if (x == x->p->left) {
        x->p->left = y;
    } else {
        x->p->right = y;
    }

    y->left = x;
    x->p = y;
}

void rotate_right(RBTree *tree, RBNode *x) {
    RBNode *y = x->left;
    x->left = y->right;
    if (y->right != NULL) {
        y->right->p = x;
    }
    y->p = x->p;

    if (x->p == NULL) {
        tree->root = y;
    } else if (x == x->p->left) {
        x->p->left = y;
    } else {
        x->p->right = y;
    }

    y->right = x;
    x->p = y;
}

void insert(RBTree *tree, RBNode *z) {
    RBNode *y = NULL;
    RBNode *x = tree->root;
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
        tree->root = z;
    } else if (z->data < y->data) {
        y->left = z;
    } else {
        y->right = z;
    }

    insert_fixup(tree, z);
}

void insert_fixup(RBTree *tree, RBNode *z) {
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
                    rotate_left(tree, z);
                }
                // Case 3
                z->p->color = BLACK;
                z->p->p->color = RED;
                rotate_right(tree, z->p->p);
            }
        } else {
            // z is on the right side of the tree
            y = z->p->p->left;
            // Case 1
            if (y && y->color == RED) {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            } else {
                // Case 2
                if (z == z->p->left) {
                    z = z->p;
                    rotate_right(tree, z);
                }
                // Case 3
                z->p->color = BLACK;
                z->p->p->color = RED;
                rotate_left(tree, z->p->p);
            }
        }
    }

    tree->root->color = BLACK;
}

void transplant(RBTree *tree, RBNode *u, RBNode *v) {
    if (u->p == NULL) {
        tree->root = v;
    } else if (u == u->p->left) {
        u->p->left = v;
    } else {
        u->p->right = v;
    }

    if (v != NULL) {
        v->p = u->p;
    }
}

RBNode *tree_minimum(RBNode *node) {
    while (node->left != NULL) {
        node = node->left;
    }

    return node;
}

void delete_fixup(RBTree *tree, RBNode *x) {
    RBNode *w = NULL;
    printf("[DEBUG] x = %p\n", x);
    while (x != tree->root && x->color == BLACK) {
        if (x == x->p->left) {
            w = x->p->right;
            if (w->color == RED) {
                printf("Case 1\n");
                w->color = BLACK;
                x->p->color = RED;
                rotate_left(tree, x->p);
                w = x->p->right;
            }

            if (w->left->color == BLACK && w->right->color == BLACK) {
                printf("Case 2\n");
                w->color = RED;
                x = x->p;
            } else {
                if (w->right->color == BLACK) {
                    printf("Case 3\n");
                    w->left->color = BLACK;
                    w->color = RED;
                    rotate_right(tree, w);
                    w = x->p->right;
                }
                printf("Case 4\n");
                w->color = x->p->color;
                x->p->color = BLACK;
                w->right->color = BLACK;
                rotate_left(tree, x->p);
                x = tree->root;
            }
        } else {
            w = x->p->left;
            if (w->color == RED) {
                printf("Case 1\n");
                w->color = BLACK;
                x->p->color = RED;
                rotate_right(tree, x->p);
                w = x->p->left;
            }

            if (w->right->color == BLACK && w->left->color == BLACK) {
                printf("Case 2\n");
                w->color = RED;
                x = x->p;
            } else {
                if (w->left->color == BLACK) {
                    printf("Case 3\n");
                    w->right->color = BLACK;
                    w->color = RED;
                    rotate_left(tree, w);
                    w = x->p->left;
                }
                printf("Case 4\n");
                w->color = x->p->color;
                x->p->color = BLACK;
                w->left->color = BLACK;
                rotate_right(tree, x->p);
                x = tree->root;
            }
        }
    }

    x->color = BLACK;
}

void delete_node(RBTree *tree, RBNode *z) {
    RBNode *y = z;
    RBNode *x = NULL;
    int y_original_color = y->color;

    if (z->left == NULL) {
        x = z->right;
        transplant(tree, z, z->right);
    } else if (z->right == NULL) {
        x = z->left;
        transplant(tree, z, z->left);
    } else {
        y = tree_minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->p == z) {
            if (x != NULL) {
                x->p = y;
            }
        } else {
            transplant(tree, y, y->right);
            y->right = z->right;
            y->right->p = y;
        }

        transplant(tree, z, y);
        y->left = z->left;
        y->left->p = y;
        y->color = z->color;
    }

    if (x != NULL && y_original_color == BLACK) {
        delete_fixup(tree, x);
    }
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

void free_tree(RBNode *node) {
    if (node != NULL) {
        free_tree(node->left);
        free_tree(node->right);
        free(node);
    }
}
