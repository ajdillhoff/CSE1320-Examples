#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;
struct node {
    double data;
    node_t *next;
};

node_t *create_node(double data) {
    node_t *node = calloc(1, sizeof(node_t));
    node->data = data;
    return node;
}

node_t *push(node_t *head, double data) {
    node_t *new_node = create_node(data);
    new_node->next = head;

    return new_node;
}

double pop(node_t **head) {
    double data = (*head)->data;

    node_t *temp = *head;
    *head = (*head)->next;
    free(temp);

    return data;
}

void traverse(node_t *n) {
    if (n != NULL) {
        printf("%.2lf\n", n->data);
        traverse(n->next);
    }
}

int main() {
    node_t *head = NULL;

    head = push(head, 8.5);
    head = push(head, 3.14);

    traverse(head);

    pop(&head);

    traverse(head);

    return 0;
}
