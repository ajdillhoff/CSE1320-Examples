#include <stdio.h>

int init_2d(int arr2d[][10], int dim1, int dim2) {
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) {
            arr2d[i][j] = (i + 1) * (j + 1);
        }
    }

    return 0;
}

void print_2d(int arr2d[][10], int dim1, int dim2) {
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) {
            printf("%3d ", arr2d[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr2d[10][10] = { 0 };

    init_2d(arr2d, 10, 10);
    print_2d(arr2d, 10, 10);

    return 0;
}
