#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAP_SIZE 10
#define BUF_SIZE 128

typedef struct node Node;
struct node {
    char *key;
    char *value;
    Node *next;
};

int hash_function(char *key) {
    printf("key: %s\n", key);

    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }

    printf("hash: %d\n", sum);

    return sum;
}

int compute_index(char *key, int array_size) {
    int hash = hash_function(key);
    int index = hash % array_size;

    printf("index = %d\n", index);

    return index;
}

void add_node(Node **head, Node *new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *temp = *head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = new_node;
    }
}

void traverse(Node *n) {
    if (n != NULL) {
        printf("(%s %s)\n", n->key, n->value);
        traverse(n->next);
    }
}

int main() {
    char buffer[BUF_SIZE] = { 0 };
    Node *hash_map[MAP_SIZE] = { NULL };

    while (1) {
        Node *new_node = calloc(1, sizeof(Node));

        // get key from user
        printf("Enter key: ");
        fgets(buffer, BUF_SIZE, stdin);
        buffer[strlen(buffer) - 1] = 0;

        // copy key data to node
        new_node->key = malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(new_node->key, buffer);

        // convert key to an index
        int index = compute_index(new_node->key, MAP_SIZE);

        // check for collision
        if (hash_map[index] != NULL) {
            printf("COLLISION DETECTED!\n");
        }

        // get value from user
        printf("Enter value: ");
        fgets(buffer, BUF_SIZE, stdin);
        buffer[strlen(buffer) - 1] = 0;

        // copy value data to node
        new_node->value = malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(new_node->value, buffer);

        // Add node to the index
        add_node(&hash_map[index], new_node);
        traverse(hash_map[index]);
    }

    return 0;
}
