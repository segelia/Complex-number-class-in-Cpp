#include <iostream>
#include "Complex.h"

int main() {
    Complex a(3.0, 4.0);
    Complex b(1.0, -2.0);
    Complex c(0.5, 1.5);

    a += b += c;
    std::cout << "a += b += c: " << a << std::endl;

    Complex d = a;
    (d += b) += c;
    std::cout << "(d += b) += c: " << d << std::endl;

    Complex e = a;
    e *= b *= c;
    std::cout << "e *= b *= c: " << e << std::endl;

    Complex f = a;
    (f *= b) *= c;
    std::cout << "(f *= b) *= c: " << f << std::endl;

    Complex g = a + 7;
    std::cout << "a + 7: " << g << std::endl;

    Complex h = 7 + a;
    std::cout << "7 + a: " << h << std::endl;

    Complex i = b * 5;
    std::cout << "b * 5: " << i << std::endl;

    Complex j = 5 * b;
    std::cout << "5 * b: " << j << std::endl;

    Complex k(3.5, 0.0);
    std::cout << "c == 3.5: " << (c == k) << std::endl;
    std::cout << "3.5 == c: " << (k == c) << std::endl;

    return 0;
}
