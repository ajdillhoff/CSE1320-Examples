#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
    int val;
    Node *next;
};

Node *pop(Node *n) {
    Node *temp = n->next;
    free(n);

    return temp;
}

Node *push(Node *n, Node *list) {
    n->next = list;
    return n;
}

void traverse(Node *n) {
    if (n != NULL) {
        printf("%d\n", n->val);
        traverse(n->next);
    }
}

int main() {
    Node *n = NULL;
    Node *temp = NULL;

    for (int i = 0; i < 10; i++) {
        if (n == NULL) {
            n = calloc(1, sizeof(Node));
            n->val = i;
        } else {
            temp = calloc(1, sizeof(Node));
            temp->val = i;
            n = push(temp, n);
        }
    }

    traverse(n);

    while (n != NULL) {
        n = pop(n);
    }

    return 0;
}
