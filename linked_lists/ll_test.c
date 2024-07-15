#include <stdio.h>

#include "ll_utils.h"

void print_function(void *data) {
    int *a = (int *)data;
    printf("data = %d\n", *a);
}

int equals(const void *elem1, const void *elem2) {
    int *a = (int *)elem1;
    int *b = (int *)elem2;

    return *a == *b;
}

int main() {
    int a = 1, b = 2, c = 3;

    Node *head = create_node(&a);
    Node *node2 = create_node(&b);
    Node *node3 = create_node(&c);

    insert_node(&head, node2, 1);
    insert_node(&head, node3, 0);

    traverse(head, print_function);

    printf("Removing node with key = %d\n", a);
    remove_node(&head, &a, equals);

    traverse(head, print_function);

    return 0;
}
