#include <stdio.h>

int main() {
    char buffer[128] = { 0 };
    int hp = 0;

    printf("Enter some text: ");
    scanf("%s", buffer);

    // Buffer flush from library -- doesn't always work
    // fflush(stdin);
    // Buffer flush - manual
    while (getchar() != '\n');

    printf("[DEBUG] You entered %s\n", buffer);

    printf("Enter hp: ");
    scanf("%d", &hp);
    // getchar(); // Eat the newline character if it was left in buffer

    printf("[DEBUG] You entered %s\n", buffer);

    printf("Enter some text: ");
    fgets(buffer, 128, stdin);

    printf("[DEBUG] first character is %d\n", buffer[0]);

    return 0;
}