/*
 * Author: Alex Dillhoff
 *
 * An example of matrix multiplication of dynamically allocated arrays.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    double *data;
} matrix_t;

// Fills a matrix with random integer values between `min` and `max`.
void fill_matrix(matrix_t *m, int min, int max) {
    if (m == NULL) {
        return;
    }

    if (m->data == NULL) {
        m->data = malloc(m->rows * m->cols * sizeof(double));
    }

    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->data[i * m->cols + j] = rand() % (max - min + 1) + min;
        }
    }
}

// Prints a matrix to stdout.
void print_matrix(matrix_t *m) {
    if (m == NULL) {
        return;
    }

    if (m->data == NULL) {
        return;
    }

    // Return a 2D view of the matrix
    // The parentheses around `array2D` indicate that this is a pointer to an array, not an array of pointers
    // On the right side, we are casting `m->data` to an array of `double` with `m->cols` columns.
    double (*array2D)[m->cols] = (double (*)[m->cols]) m->data;

    for (int i = 0; i < m->rows; i++) {
        printf("[");
        for (int j = 0; j < m->cols; j++) {
            printf("%.2f", array2D[i][j]);
            if (j < m->cols - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

// Multiplies two matrices together and returns the result.
matrix_t *matmul(matrix_t *a, matrix_t *b) {
    if (a == NULL || b == NULL) {
        return NULL;
    }

    if (a->cols != b->rows) {
        printf("[ERROR] Cannot multiply matrices of size %dx%d and %dx%d.\n", a->rows, a->cols, b->rows, b->cols);
        return NULL;
    }

    matrix_t *c = malloc(sizeof(matrix_t));
    c->rows = a->rows;
    c->cols = b->cols;
    c->data = malloc(c->rows * c->cols * sizeof(double));

    for (int i = 0; i < c->rows; i++) {
        for (int j = 0; j < c->cols; j++) {
            c->data[i * c->cols + j] = 0;
            for (int k = 0; k < a->cols; k++) {
                c->data[i * c->cols + j] += a->data[i * a->cols + k] * b->data[k * b->cols + j];
            }
        }
    }

    return c;
}

int main() {
    matrix_t *a = malloc(sizeof(matrix_t));
    a->rows = 3;
    a->cols = 2;
    a->data = NULL;

    matrix_t *b = malloc(sizeof(matrix_t));
    b->rows = 2;
    b->cols = 3;
    b->data = NULL;

    matrix_t *c = NULL;

    fill_matrix(a, 0, 10);
    fill_matrix(b, 0, 10);

    printf("a:\n");
    print_matrix(a);

    printf("b:\n");
    print_matrix(b);

    c = matmul(a, b);

    printf("c:\n");
    print_matrix(c);

    free(a->data);
    free(a);
    free(b->data);
    free(b);
    free(c->data);
    free(c);

    return 0;
}