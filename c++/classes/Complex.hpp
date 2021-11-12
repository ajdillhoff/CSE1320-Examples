#pragma once

#include <iostream>

using namespace std;

class Complex {
    double re;
    double im;

    public:
        Complex(double r, double i) : re{r}, im{i} {}
        Complex(double r) : re{r}, im{0} {}
        Complex() : re{0}, im{0} {}

        /* Getters/Setters */
        double real() const {
            return re;
        }

        void real(double d) {
            re = d;
        }

        double imag() const {
            return im;
        }

        void imag(double d) {
            im = d;
        }

        /* Overloads */
        Complex& operator+=(Complex z) {
            re += z.re;
            im += z.im;
            return *this;
        }

        Complex& operator-=(Complex z) {
            re -= z.re;
            im -= z.im;
            return *this;
        }

        Complex& operator*=(Complex);
        Complex& operator/=(Complex);
};
