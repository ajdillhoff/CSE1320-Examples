#include "Complex.hpp"

Complex operator+(Complex a, Complex b) {
    return a += b;
}

Complex operator-(Complex a, Complex b) {
    return a -= b;
}

Complex operator-(Complex a) {
    return {-a.real(), -a.imag()};
}

