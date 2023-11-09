#include <iostream>
#include "Complex.h"
#include <cmath>

Complex::Complex(double real, double imag)
	: real(real), imag(imag) {}

Complex& Complex::operator+=(const Complex& other) {
    //~ *this = *this + other;
    //~ return *this;
    
    real += other.real;
    imag += other.imag;
    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    real -= other.real;
    imag -= other.imag;
    return *this;
}

Complex& Complex::operator*=(const Complex& other) {
    double temp_real = (real * other.real) - (imag * other.imag);
    imag = (real * other.imag) + (imag * other.real);
    real = temp_real;
    return *this;
}

Complex& Complex::operator/=(const Complex& other) {	
    double divisor = (other.real * other.real) + (other.imag * other.imag);
    double temp_real = ((real * other.real) + (imag * other.imag)) / divisor;
    imag = ((imag * other.real) - (real * other.imag)) / divisor;
    real = temp_real;
    return *this;
}

double Complex::amplitude() const {
    return std::sqrt(real * real + imag * imag);
}

double Complex::phase() const {
    return atan2(imag, real);
}

Complex operator+(const Complex& a, const Complex& b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}

Complex operator-(const Complex& a, const Complex& b) {
    return Complex(a.real - b.real, a.imag - b.imag);
}

Complex operator*(const Complex& a, const Complex& b) {
    return Complex((a.real * b.real) - (a.imag * b.imag), (a.real * b.imag) + (a.imag * b.real));
}

Complex operator/(const Complex& a, const Complex& b) {	
    double divisor = (b.real * b.real) + (b.imag * b.imag);
    
	return Complex(
		((a.real * b.real) + (a.imag * b.imag)) / divisor,	// Real part.
		((a.imag * b.real) - (a.real * b.imag)) / divisor	// Imaginary part.
	);    
}

bool operator==(const Complex& a, const Complex& b) {
    return a.real == b.real && a.imag == b.imag;
}

bool operator!=(const Complex& a, const Complex& b) {
    return !(a == b);
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real << " + " << c.imag << "i";
    return os;
}















