#include <stdio.h>

int main() {
    int arr[100] = { 0 };
    int nvals = 0;

    FILE *fp = fopen("numbers.dat", "rb");

    fseek(fp, 0, SEEK_END);

    long file_size = ftell(fp);

    printf("There are %ld bytes in the file.\n", file_size);
    nvals = file_size / sizeof(int);
    printf("There are %d values in the value.\n", nvals);

    fseek(fp, 0, SEEK_SET);

    fread(arr, sizeof(int), nvals, fp);

    for (int i = 0; i < nvals; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    printf("Read %ld bytes\n", ftell(fp));

    return 0;
}