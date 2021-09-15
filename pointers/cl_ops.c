#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double divide(double a, double b) {
    return a / b;
}

double multiply(double a, double b) {
    return a * b;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: cl_ops OPERATOR NUM1 NUM2\n");
        return 1;
    }

    double a = atof(argv[2]);
    double b = atof(argv[3]);

    if (!strcmp(argv[1], "add")) {
        printf("%lf\n", add(a, b));
    } else if (!strcmp(argv[1], "subtract")) {
        printf("%lf\n", subtract(a, b));
    } else if (!strcmp(argv[1], "divide")) {
        printf("%lf\n", divide(a, b));
    } else if (!strcmp(argv[1], "multiply")) {
        printf("%lf\n", multiply(a, b));
    } else {
        printf("Not a valid operator\nUse add, subtract, divide, or multiply\n");
        return 1;
    }

    return 0;
}
