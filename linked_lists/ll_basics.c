#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

int main() {
    struct node *n = calloc(1, sizeof(struct node));
    n->val = 0;
    struct node *temp1, *temp2;

    temp2 = n;

    // Create nodes and initialize values
    for (int i = 1; i <= 10; i++) {
        temp1 = calloc(1, sizeof(struct node));
        temp1->val = i;
        temp2->next = temp1;
        temp2 = temp2->next;
    }

    temp2 = n;

    while (temp2->next != NULL) {
        printf("%d\n", temp2->val);
        temp2 = temp2->next;
    }

    return 0;
}
