#include <stdio.h>

#include "ll_utils.h"

void traverse_nodes(Node *n) {
    if (n != NULL) {
        int a = *((int *)n->data);
        printf("data = %d\n", a);
        traverse_nodes(n->next);
    }
}

int equals(const void *elem1, const void *elem2) {
    int *a = (int *)elem1;
    int *b = (int *)elem2;

    return *a != *b;
}

int main() {
    int a = 1, b = 2, c = 3;

    Node *head = create_node(&a);
    Node *node2 = create_node(&b);
    Node *node3 = create_node(&c);

    insert_node(&head, node2, 1);
    insert_node(&head, node3, 0);

    traverse_nodes(head);

    printf("Removing node with key = %d\n", a);
    remove_node(&head, &a, equals);

    traverse_nodes(head);

    return 0;
}
