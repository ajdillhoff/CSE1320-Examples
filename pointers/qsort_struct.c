#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 64

typedef struct {
    char name[MAX_NAME];
    int hp;
    int ac;
} creature;

int compare_name(const void *elem1, const void *elem2) {
    creature *a = (creature *) elem1;
    creature *b = (creature *) elem2;

    return strcmp(a->name, b->name);
}

int compare_hp(const void *elem1, const void *elem2) {
    creature *a = (creature *) elem1;
    creature *b = (creature *) elem2;

    return a->hp - b->hp;
}

int compare_ac(const void *elem1, const void *elem2) {
    creature *a = (creature *) elem1;
    creature *b = (creature *) elem2;

    return a->ac - b->ac;
}

void print_creatures(creature c[], int numel) {
    for (int i = 0; i < numel - 1; i++) {
        printf("{ \"%s\", %d, %d }, ", c[i].name, c[i].hp, c[i].ac);
    }
    printf("{ \"%s\", %d, %d }\n", c[numel-1].name, c[numel-1].hp, c[numel-1].ac);
}

int main() {
    creature creatures[] = {
        { "Raishan", 520, 22 },
        { "Thordak", 1452, 23 },
        { "Umbrasyl", 340, 20 },
        { "Vorugal", 300, 20 },
        { "Brimscythe", 280, 19 }
    };

    printf("Before qsort\n");
    print_creatures(creatures, 5);

    qsort(creatures, 5, sizeof(creature), compare_name);

    printf("After qsort\n");
    print_creatures(creatures, 5);

    return 0;
}
