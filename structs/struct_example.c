/*
 * Example of using a struct with typedef.
 */

#include "struct_example.h"

void trim(char *str) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

/*
 * Since the input is a pointer, we use '->' notation to access
 * members instead of '.'.
 */
void print_monster(monster_t monster) {
    printf("Name: %s\n", monster.name);
    printf("Type: %s\n", monster.type);
    printf("HP: %d\n", monster.hp);
    printf("Level: %d\n", monster.level);
}

monster_t create_monster() {
    monster_t monster = { 0 };

    printf("Enter name: ");
    fgets(monster.name, STR_MAX, stdin);
    trim(monster.name);

    printf("Enter type: ");
    fgets(monster.type, STR_MAX, stdin);
    trim(monster.type);

    printf("Enter HP: ");
    scanf("%d", &monster.hp);

    printf("Enter level: ");
    scanf("%d", &monster.level);

    return monster;
}

int main() {
    /* struct monster_t dragon = create_monster(); */

    /* print_monster(dragon); */

    printf("%ld\n", sizeof(monster_t));

    monster_t dragons[5] = {
        { "Thordak", "Adult Red Dragon", 1100, 20 },
        { "Raishan", "Adult Green Dragon", 1000, 19 },
        { "Vorugal", "Adult White Dragon", 900, 18 },
        { "Brimscythe", "Adult Blue Dragon", 800, 17 },
        { "Umbrasyl", "Adult Dragon Dragon", 700, 16 },
    };

    FILE *fp = fopen("dragons.bin", "wb");

    fwrite(dragons, sizeof(monster_t), 5, fp);

    fclose(fp);

    fp = fopen("dragons.bin", "rb");

    monster_t new_dragons[5] = { 0 };

    fread(new_dragons, sizeof(monster_t), 5, fp);

    for (int i = 0; i < 5; i++) {
        print_monster(new_dragons[i]);
    }

    return 0;
}
