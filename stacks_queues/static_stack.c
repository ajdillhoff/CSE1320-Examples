#include <stdio.h>

#define CAPACITY 10

int push(int data, int stack[], int num_items) {
    if (num_items >= CAPACITY) {
        return num_items;
    }

    stack[num_items] = data;

    return num_items + 1;
}

int pop(int stack[], int *num_items) {
    if (*num_items == 0) {
        return 0;
    }

    int data = stack[*num_items - 1];

    *num_items = *num_items - 1;

    return data;
}

void print_stack(int stack[], int num_items) {
    for (int i = num_items - 1; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
    printf("\n");
}

int main() {
    int stack[CAPACITY] = { 0 };
    int num_items = 0;

    num_items = push(10, stack, num_items);
    num_items = push(20, stack, num_items);
    num_items = push(30, stack, num_items);
    num_items = push(40, stack, num_items);
    print_stack(stack, num_items);

    pop(stack, &num_items);
    print_stack(stack, num_items);

    return 0;
}
