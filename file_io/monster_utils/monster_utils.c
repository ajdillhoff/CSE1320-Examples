#include "monster_utils.h"

void trim(char *str) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

int write_monster_binary(monster_t m, char *filename) {
    FILE *fp = fopen(filename, "ab");

    if (!fp) {
        printf("Cannot open the file.\n");
        return 1;
    }

    fwrite(&m, sizeof(monster_t), 1, fp);

    fclose(fp);

    return 0;
}

int write_monster_csv(monster_t m, char *filename) {
    FILE *fp = fopen(filename, "a");

    if (!fp) {
        printf("Cannot open the file.\n");
        return 1;
    }

    fprintf(fp, "%s,%s,%d,%d\n", m.name, m.type, m.hp, m.level);

    fclose(fp);

    return 0;
}

monster_t parse_csv_line(char *csv_line) {
    char *token = strtok(csv_line, ",");
    monster_t m = { 0 };
    int property = 0;

    while (token != NULL) {
        switch (property) {
            case 0:
                strcpy(m.name, token);
                break;
            case 1:
                strcpy(m.type, token);
                break;
            case 2:
                m.hp = atoi(token);
                break;
            case 3:
                m.level = atoi(token);
                break;
            default:
                break;
        }

        property++;
        token = strtok(NULL, ",");
    }

    return m;
}

void read_monsters_csv(char *filename) {
    FILE *fp = fopen(filename, "r");

    if (!fp) {
        printf("Cannot open file.\n");
        return;
    }
    
    char buffer[BUFFER_SIZE] = { 0 };

    while (fgets(buffer, BUFFER_SIZE, fp)) {
        trim(buffer);
        monster_t m = parse_csv_line(buffer);
        print_monster(m);
    }
}

void read_monsters_binary(char *filename) {
    FILE *fp = fopen(filename, "r");

    if (!fp) {
        printf("Cannot open file.\n");
        return;
    }

    monster_t m = { 0 };

    while (1) {
        fread(&m, sizeof(monster_t), 1, fp);

        if (feof(fp)) {
            return;
        }

        print_monster(m);
    }
}

void print_monster(monster_t m) {
    printf("Name: %s\n", m.name);
    printf("Type: %s\n", m.type);
    printf("HP: %d\n", m.hp);
    printf("Level: %d\n", m.level);
}
