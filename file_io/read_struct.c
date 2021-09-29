/*
 * An example of reading binary data into a struct that
 * has a member with variable data.
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

/*
 * Creates a dynamic pointer, make sure to free
 */
product_t *read_product(FILE *fp) {
    product_t *product = calloc(1, sizeof(product_t));

    if (!product) {
        return NULL;
    }

    fread(&product->id, sizeof(int), 1, fp);
    fread(&product->name_size, sizeof(unsigned char), 1, fp);
    product->name = calloc(product->name_size + 1, sizeof(char));
    fread(product->name, sizeof(char), product->name_size, fp);
    fread(&product->price, sizeof(double), 1, fp);
    fread(&product->quantity, sizeof(int), 1, fp);

    return product;
}

void print_product(product_t *p) {
    printf("ID: %d\n", p->id);
    printf("Name: %s\n", p->name);
    printf("Price: %.2lf\n", p->price);
    printf("Quantity: %d\n", p->quantity);
}

int main() {
    FILE *fp = fopen("product.dat", "rb");

    if (!fp) {
        return 1;
    }

    product_t *product = read_product(fp);    

    print_product(product);

    free(product->name);
    free(product);

    fclose(fp);

    return 0;
}
