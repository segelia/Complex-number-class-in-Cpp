#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
public:
    double real;
    double imag;

    Complex(double real = 0.0, double imag = 0.0);

    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    double amplitude() const;
    double phase() const;
};

Complex operator+(const Complex& a, const Complex& b);
Complex operator-(const Complex& a, const Complex& b);
Complex operator*(const Complex& a, const Complex& b);
Complex operator/(const Complex& a, const Complex& b);
bool operator==(const Complex& a, const Complex& b);
bool operator!=(const Complex& a, const Complex& b);

std::ostream& operator<<(std::ostream& os, const Complex& c);

#endif // COMPLEX_H
