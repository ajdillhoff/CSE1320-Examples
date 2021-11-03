#include <iostream>

int main() {
    double *a = new double[100];

    for (int i = 0; i < 100; i++) {
        std::cout << a[i] << std::endl;
    }

    delete a;
}
