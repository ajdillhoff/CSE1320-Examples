/*
 * An example of using a function pointer as a parameter
 * to a function. 
 */

#include <stdio.h>
#include <string.h>
#include <float.h>
#include <stdlib.h>
#include <ctype.h>

typedef double (*choose_ptr)(double, double);

void trim(char *str) {
    int l = strlen(str);
    if (str[l-1] == '\n') {
        str[l-1] = 0;
    }
}

double add(double a, double b) {
    return a + b;
}

double mult(double a, double b) {
    return a * b;
}

double subtract(double a, double b) {
    return a - b;
}

double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        return DBL_MAX;
    }
}

choose_ptr choose_op(char *c) {
    if (!strcmp(c, "add")) {
        return add;
    } else if (!strcmp(c, "mult")) {
        return mult;
    } else if (!strcmp(c, "subtract")) {
        return subtract;
    } else if (!strcmp(c, "divide")) {
        return divide;
    } else {
        return NULL;
    }
}

int isnum(char *str) {
    while (*str != 0) {
        if (!isdigit(*str)) {
            return 0;
        }

        str++;
    }

    return 1;
}

int main(int argc, char **argv) {
    double a = 0, b = 0;

    if (argc != 4) {
        printf("USAGE: ./a.out OPERATOR NUM1 NUM2\n");
        return 1;
    }

    if (!isnum(argv[2]) || !isnum(argv[3])) {
        printf("Enter integers only.\n");
        return 1;
    }

    a = atof(argv[2]);
    b = atof(argv[3]);

    /* double (*op)(double, double) = choose_op(argv[1]); */
    choose_ptr op = choose_op(argv[1]);

    if (op == NULL) {
        printf("Invalid operator.\n");
        return 1;
    }

    double op_result = op(a, b);

    printf("op(%.2lf, %.2lf) = %.2lf\n", a, b, op_result);

    return 0;
}

