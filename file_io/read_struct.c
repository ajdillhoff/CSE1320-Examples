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

    // Get the number of characters in the string
    long cur_pos = ftell(fp);
    char c = -1;
    int size = 0;
    while ((c = getc(fp))) {
        size++;
    }

    printf("[DEBUG] size is %d\n", size);

    product->name = calloc(size, sizeof(char));

    fseek(fp, cur_pos, SEEK_SET);

    printf("[DEBUG] file pointer at %ld\n", ftell(fp));

    fread(product->name, sizeof(char), size + 1, fp);

    printf("[DEBUG] file pointer at %ld\n", ftell(fp));

    fread(&product->price, sizeof(double), 1, fp);

    printf("[DEBUG] price is %lf\n", product->price);

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
