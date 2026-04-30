#include <stdio.h>

struct Complex {
    double real;
    double imaginary;
};


int main() {

    struct Complex c1 = {0.0,1.0};
    struct Complex c2 = {1.0,0.0};
    struct Complex c3;

    c1 = c2;

    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;

    printf("c1: %.2f + %.2fi\n", c1.real, c1.imaginary);
    printf("c2: %.2f + %.2fi\n", c2.real, c2.imaginary);
    printf("c3: %.2f + %.2fi\n", c3.real, c3.imaginary);

    return 0;
}