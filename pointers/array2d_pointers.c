#include <stdio.h>

void print_array2d(int **arr, int dim1, int dim2) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", *(*(arr + i) + j));
            /*printf("%2d ", arr[i][j]);*/
        }
        printf("\n");
    }
}

int main() {
    int row1[] = { 0, 1, 2, 3 };
    int row2[] = { 4, 5, 6, 7 };
    int row3[] = { 8, 9, 10, 11 };
    int row4[] = { 12, 13, 14, 15 };

    // Compare with reverse order
    int *ptr_arr[] = {
        row1,
        row2,
        row3,
        row4
    };

    print_array2d(ptr_arr, 4, 4);

    return 0;
}
