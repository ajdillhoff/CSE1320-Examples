#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node {
    int data;
    Node *prev;
    Node *next;
};

int dequeue(Node **head, Node **tail) {
    int val = (*tail)->data;

    if (*head == *tail) {
        free(*tail);
        *head = NULL;
        *tail = NULL;
    } else {
        Node *prev = (*tail)->prev;
        prev->next = NULL;
        free(*tail);
        *tail = prev;
    }

    return val;
}

void enqueue(int data, Node **head, Node **tail) {
    Node *new_node = calloc(1, sizeof(Node));
    new_node->data = data;
    new_node->next = *head;

    if (*head != NULL) {
        (*head)->prev = new_node;
    } else {
        *tail = new_node;
    }

    *head = new_node;
}

void print_queue(Node *head) {
    int i = 0;
    while (head != NULL) {
        printf("(%d, %d)\n", i++, head->data);
        head = head->next;
    }
}

int main() {
    Node *head = NULL, *tail = NULL;

    enqueue(10, &head, &tail);
    enqueue(-5, &head, &tail);
    enqueue(7, &head, &tail);

    print_queue(head);

    int val = dequeue(&head, &tail);
    printf("val = %d\n", val);
    print_queue(head);

    val = dequeue(&head, &tail);
    printf("val = %d\n", val);
    print_queue(head);

    val = dequeue(&head, &tail);
    printf("val = %d\n", val);
    print_queue(head);

    return 0;
}
