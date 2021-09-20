#include "combat_log.h"

void get_choice(char *choice) {
    scanf("%c", choice);
    *choice = toupper(*choice);
    while (getchar() != '\n');
}

void print_menu() {
    printf("L - Log Combat Round\n");
    printf("N - Get Number of Rounds\n");
    printf("Q - Quit\n");
}

int log_combat(FILE *fp) {
    ACTION action = { 0 };

    printf("Enter attacker ID: ");
    scanf("%d", &action.attacker_id);
    while (getchar() != '\n');
    printf("Enter target ID: ");
    scanf("%d", &action.target_id);
    while (getchar() != '\n');
    printf("Enter damage: ");
    scanf("%d", &action.damage);
    while (getchar() != '\n');

    fwrite(&action, sizeof(ACTION), 1, fp);
}

int get_num_rounds(FILE *fp) {
    int num_rounds = 0;
    size_t result = 1;
    ACTION a;

    // Get current pointer
    long pos = ftell(fp);

    // Go to beginning of file
    fseek(fp, 0, SEEK_SET);

    while (result != 0 && !feof(fp)) {
        result = fread(&a, sizeof(ACTION), 1, fp);
        num_rounds++;
    }

    // Reset file pointer
    fseek(fp, pos, SEEK_SET);

    return num_rounds;
}

int main() {
    FILE *log_fp = NULL;
    char choice = 0;
    int num_rounds = 0;

    // Attempt to open the log
    log_fp = fopen("log.dat", "a+");

    while (choice != 'Q') {
        print_menu();
        get_choice(&choice);

        switch (choice) {
            case 'L':
                // Log a round
                log_combat(log_fp);
                break;
            case 'N':
                // Get the number of rounds logged
                num_rounds = get_num_rounds(log_fp);
                printf("%d\n", num_rounds);
                break;
            case 'Q':
                printf("Goodbye\n");
                break;
            default:
                printf("Invalid Command.\n");
        }
    }

    fclose(log_fp);

    return 0;
}
