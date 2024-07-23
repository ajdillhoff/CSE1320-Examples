#include <stdio.h>

#include "user.h"
#include "array_utils.h"

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    array_t *users = load_users(argv[1]);

    if (users == NULL) {
        printf("Error loading users from file %s\n", argv[1]);
        return 1;
    }

    printf("test\n");

    print_users(users);

    array_free(users, free_user);

    return 0;

}
