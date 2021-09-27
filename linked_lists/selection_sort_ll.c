#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 10

typedef struct node Node;
struct node {
    int data;
    Node *next;
};

void traverse(Node *head) {
    if (head != NULL) {
        printf("%d ", head->data);
        traverse(head->next);
    } else {
        printf("\n");
    }
}

// TODO: Debug this, not sorting past the middle two
void selection_sort(Node **head, int size) {
    Node *start_prev = NULL;

    // sort linked list
    for (Node *start = *head; start != NULL; start = start->next) {
        Node *min_compare = start;
        Node *compare_prev_min = start;
        Node *compare_prev = start;

        for (Node *compare = start->next; compare != NULL; compare = compare->next) {
            if (compare->data < min_compare->data) {
                min_compare = compare;
                compare_prev_min = compare_prev;
            }

            compare_prev = compare;
        }

        // Check if a swap should be made
        if (min_compare != start) {
            // DEBUG
            printf("Swapping %d and %d\n", start->data, min_compare->data);
            if (start == *head) {
                Node *temp = min_compare->next;
                min_compare->next = start->next;
                start->next = temp;
                compare_prev_min->next = start;
                *head = min_compare;
            } else {
                Node *temp = min_compare->next;
                min_compare->next = start->next;
                start->next = temp;
                start_prev->next = min_compare;
                compare_prev_min->next = start;
            }
            start = min_compare;
        }

        start_prev = start;
    }
}

void add_node(int data, Node **head) {
    Node *new_node = calloc(1, sizeof(Node));
    new_node->data = data;
    new_node->next = *head;

    *head = new_node;
}

int main() {
    Node *head = NULL;

    for (int i = 0; i < LIST_SIZE; i++) {
        add_node(i, &head);
    }

    printf("Unsorted Linked List\n");
    traverse(head);

    selection_sort(&head, LIST_SIZE);

    printf("Sorted Linked List\n");
    traverse(head);

    return 0;
}
