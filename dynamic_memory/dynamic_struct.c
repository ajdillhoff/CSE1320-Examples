#include "dynamic_struct.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trim(char *str) {
    str[strcspn(str, "\r\n")] = 0;
}

/*
 * Uses getline to read a string of arbitrary length from the given file stream.
 */
char *read_string(FILE *restrict stream) {
    char *line = NULL;
    size_t size = 0;

    ssize_t num_read = getline(&line, &size, stream);

    printf("[DEBUG] num_read: %ld\n", num_read);

    if (num_read == -1) {
        free(line);
        return NULL;
    }

    // `getline2` will allocate memory in chunks of `BUFSIZE`.
    // If the string is shorter than the capacity, we can free the extra memory.
    if (num_read + 1 < size) {
        line = realloc(line, num_read + 1);
    }

    trim(line);

    return line;
}

/*
* Creates a new user based on input from the user.
*/
user_s *create_user() {
    user_s *user = malloc(sizeof(user_s));

    printf("Enter a name: ");
    user->name = read_string(stdin);

    printf("Enter an email address: ");
    user->email = read_string(stdin);

    return user;
}

/*
* Reads a `user_s` from the given binary FILE stream.
*/
user_s *read_user(FILE *stream) {
    user_s *user = malloc(sizeof(user_s));

    // TODO: Read the name and email from the file.

    return user;
}

/*
 * Writes the given `user_s` to the given binary FILE stream.
 */
void write_user(FILE *stream, user_s *user) {
    fwrite(user->name, sizeof(char), strlen(user->name) + 1, stream);
    fwrite(user->email, sizeof(char), strlen(user->email) + 1, stream);
}

/*
 * Frees the memory allocated to the given `user_s`.
 */
void free_user(user_s *user) {
    free(user->name);
    free(user->email);
    free(user);
}

/*
 * Prints the given `user_s` to the console.
 */
void print_user(user_s *user) {
    printf("Name: %s\n", user->name);
    printf("Email: %s\n", user->email);
}