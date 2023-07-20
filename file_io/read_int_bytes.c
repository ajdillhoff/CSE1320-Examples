#include <stdio.h>

int main() {
    int arr[5] = { 0 };

    FILE *fp = fopen("numbers.dat", "rb");

    fread(arr, sizeof(int), 5, fp);

    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    printf("Read %ld bytes\n", ftell(fp));

    return 0;
}