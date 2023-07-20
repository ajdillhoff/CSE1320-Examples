#include <stdio.h>

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };

    FILE *fp = fopen("numbers.dat", "wb");

    fwrite(arr, sizeof(arr[0]), 5, fp);

    fclose(fp);

    return 0;
}