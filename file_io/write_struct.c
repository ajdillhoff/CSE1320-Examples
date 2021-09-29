/*
 * Writes struct data to a binary file in which the struct
 * itself has a pointer to variable data.
 *
 * The `name_size` is written before the name as metadata to
 * indicate how many bytes should be reserved when reading.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 128

typedef struct {
    int id;
    unsigned char name_size;
    char *name;
    double price;
    int quantity;
} product_t;

void trim(char *str) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

/*
 * Creates a dynamic pointer, make sure to free
 */
product_t *create_product() {
    product_t *product = calloc(1, sizeof(product_t));
    char buffer[BUF_SIZE] = { 0 };

    if (!product) {
        return NULL;
    }

    printf("Enter an ID: ");
    scanf("%d", &product->id);
    while (getchar() != '\n');

    printf("Enter a name: ");
    fgets(buffer, BUF_SIZE, stdin);
    trim(buffer);

    product->name_size = strlen(buffer);
    product->name = calloc(product->name_size + 1, sizeof(char));
    strcpy(product->name, buffer);

    printf("Enter a price: ");
    scanf("%lf", &product->price);
    while (getchar() != '\n');

    printf("Enter a quantity: ");
    scanf("%d", &product->quantity);
    while (getchar() != '\n');

    return product;
}

int main() {
    FILE *fp = fopen("product.dat", "wb");

    if (!fp) {
        return 1;
    }

    product_t *product = create_product();

    // Write the product data
    fwrite(&product->id, sizeof(int), 1, fp);
    fwrite(&product->name_size, sizeof(unsigned char), 1, fp);
    fwrite(product->name, sizeof(char), strlen(product->name), fp);
    fwrite(&product->price, sizeof(double), 1, fp);
    fwrite(&product->quantity, sizeof(int), 1, fp);

    free(product->name);
    free(product);

    fclose(fp);

    return 0;
}
