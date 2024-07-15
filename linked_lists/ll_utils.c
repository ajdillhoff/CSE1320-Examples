#include "ll_utils.h"

void traverse(Node *n, void (*callback)(void *)) {
    if (n != NULL) {
        callback(n->data);
        traverse(n->next, callback);
    }
}

Node *create_node(void *data) {
    Node *n = calloc(1, sizeof(Node));
    n->data = data;

    return n;
}

void insert_node(Node **head, Node *new_node, int position) {
    Node *prev = NULL;
    Node *current = *head;
    int cur_pos = 0;

    while (current != NULL && cur_pos < position) {
        cur_pos++;
        prev = current;
        current = current->next;
    }

    if (current == *head) {
        new_node->next = current;
        *head = new_node;
    } else {
        new_node->next = current;
        prev->next = new_node;
    }
}

void *remove_node(Node **head, void *key, int (*equals)(const void *, const void *)) {
    Node *prev = NULL;
    Node *current = *head;
    void *data = NULL;

    while (current != NULL && !equals(key, current->data)) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return NULL;
    }

    if (current == *head) {
        // Removing head node
        Node *temp = current;
        *head = current->next;
        data = temp->data;
        free(temp);
    } else {
        // Removing some other node
        prev->next = current->next;
        data = current->data;
        free(current);
    }

    return data;
}

void free_list(Node *n) {
    while (n != NULL) {
        Node *temp = n->next;
        free(n);
        n = temp;
    }
}

void free_list_recursive(Node *n) {
    if (n != NULL) {
        Node *temp = n->next;
        free(n);
        free_list_recursive(temp);
    }
}
