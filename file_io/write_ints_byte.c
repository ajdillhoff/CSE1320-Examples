#include <stdio.h>

int main() {
    int arr[] = { 10023, 1024, 3, 43, 15 };

    FILE *fp = fopen("numbers.dat", "wb");

    fwrite(arr, sizeof(arr[0]), 5, fp);

    fclose(fp);

    return 0;
}