#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAP_SIZE 10
#define BUF_SIZE 128

typedef struct {
    char *key;
    char *value;
} hash_element_t;

typedef struct node node_t;
struct node {
    hash_element_t *data;
    node_t *next;
};

int hash_function(char *key) {
    printf("key: %s\n", key);

    int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash += key[i];
    }

    printf("hash: %d\n", hash);

    return hash;
}

// unsigned long djb2(unsigned char *str) {
//     unsigned long hash = 5381;
//     int c;

//     while (c = *str++)
//         hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

//     return hash;
// }

int compute_index(char *key, int array_size) {
    int hash = hash_function(key);
    int index = hash % array_size;

    printf("index: %d\n", index);

    return index;
}

void add_node(node_t **head, hash_element_t *data) {
    node_t *new_node = calloc(1, sizeof(node_t));
    new_node->data = data;

    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t *temp = *head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = new_node;
    }
}

void traverse(node_t *n) {

    if (n == NULL) {
        printf("EMPTY");
    }

    while (n != NULL) {
        printf("(\"%s\", \"%s\") ", n->data->key, n->data->value);

        n = n->next;

        if (n != NULL) {
            printf("-> ");
        }
    }
    printf("\n");
}

void print_map(node_t *map[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        printf("map[%d] = ", i);
        traverse(map[i]);
    }
}

int main() {
    char buffer[BUF_SIZE] = { 0 };
    node_t *map[MAP_SIZE] = { NULL };

    while (1) {
        printf("Enter a key: ");
        fgets(buffer, BUF_SIZE, stdin);
        buffer[strlen(buffer) - 1] = 0;

        // Copy the data to a hash_element_t
        hash_element_t *elem = calloc(1, sizeof(hash_element_t));
        elem->key = malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(elem->key, buffer);

        // Convert the key to an index
        int index = compute_index(elem->key, MAP_SIZE);

        // Check for collisions
        if (map[index] != NULL) {
            printf("COLLISION DETECTED\n");
        }

        // Get value from the user
        printf("Enter a value: ");
        fgets(buffer, BUF_SIZE, stdin);
        buffer[strlen(buffer) - 1] = 0;

        elem->value = malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(elem->value, buffer);

        // Add element to the map
        add_node(&map[index], elem);
        print_map(map, MAP_SIZE);
    }

    return 0;
}
