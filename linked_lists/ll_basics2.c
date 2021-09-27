#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
    int val;
    Node *next;
};

Node *add_node(int val) {
    Node *n = calloc(1, sizeof(Node));
    n->val = val;

    return n;
}

void traverse(Node *n) {
    if (n != NULL) {
        printf("%d\n", n->val);
        traverse(n->next);
    }
}

// Why must we return Node * instead of relying on the pointer argument?
Node *reverse(Node *n) {
    Node *current = n;
    Node *prev = NULL;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void release(Node *n) {
    if (n != NULL) {
        Node *temp = n->next;
        free(n);
        release(temp);
    }
}

int main() {
    Node *n = NULL;
    Node *temp = NULL;

    for (int i = 0; i < 10; i++) {
        if (n == NULL) {
            n = add_node(i);
            temp = n;
        } else {
            temp->next = add_node(i);
            temp = temp->next;
        }
    }

    traverse(n);

    n = reverse(n);

    traverse(n);

    release(n);

    return 0;
}
