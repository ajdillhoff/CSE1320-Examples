#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 128

typedef struct {
    char **data;
    int num_items;
} mystack_t;

void push(char *val, mystack_t *stack) {
    stack->data = realloc(stack->data, (stack->num_items + 1) * sizeof(void *));
    stack->data[stack->num_items++] = val;
}

char *pop(mystack_t *stack) {
    char *str = stack->data[stack->num_items - 1];
    stack->data = realloc(stack->data, --stack->num_items * sizeof(void *));

    return str;
}

void print_stack(mystack_t *stack) {
    for (int i = stack->num_items - 1; i >= 0; i--) {
        printf("%s\n", stack->data[i]);
    }
    printf("\n");
}

char *read_string() {
    char buffer[BUF_SIZE] = { 0 };
    printf("Enter a string: ");
    fgets(buffer, BUF_SIZE, stdin);
    buffer[strlen(buffer) - 1] = 0;

    char *str = calloc(strlen(buffer) + 1, sizeof(char));
    strcpy(str, buffer);

    return str;
}

int main() {
    mystack_t *stack = calloc(1, sizeof(mystack_t));

    char *str = read_string();
    push(str, stack);
    str = read_string();
    push(str, stack);

    print_stack(stack);

    pop(stack);

    print_stack(stack);

    for (int i = 0; i < stack->num_items; i++) {
        free(stack->data[i]);
    }
    free(stack->data);
    free(stack);

    return 0;
}

