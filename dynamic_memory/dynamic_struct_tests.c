#include "dynamic_struct.h"

#include <stdio.h>

int main() {
    user_s *user = create_user();
    print_user(user);
    FILE *fp = fopen("user.dat", "wb");
    write_user(fp, user);
    fclose(fp);
    free_user(user);

    // fp = fopen("user.dat", "rb");
    // user_s *user2 = read_user(fp);
    // fclose(fp);
    // print_user(user2);
    // free_user(user2);
}