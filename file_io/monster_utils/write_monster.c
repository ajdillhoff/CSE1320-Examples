#include "monster_utils.h"

int main() {
    monster_t m = { 0 };

    printf("Enter a name: ");
    fgets(m.name, MAX_STR, stdin);
    trim(m.name);

    printf("Enter a type: ");
    fgets(m.type, MAX_STR, stdin);
    trim(m.type);

    printf("Enter hp: ");
    scanf("%d", &m.hp);

    printf("Enter level: ");
    scanf("%d", &m.level);

    /* int result = write_monster_csv(m, "monsters.csv"); */
    int result = write_monster_binary(m, "monsters.bin");

    if (result) {
        printf("Unable to write monster.\n");
        return 1;
    }

    return 0;
}
