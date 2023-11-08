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
	// return a * b.conj() / b.norm2()
	// Do powyższego zapisu potrzebujemy metody conj() która zwraca liczbę sprzężoną
	// metody norm2 która zwraca kwadrat modułu liczby zespolonej (warto też napisać norm, która zwraca moduł)
	// operator / który pozwala dzielić liczbę zespoloną przez liczbę rzeczywistą.
	
    double divisor = (b.real * b.real) + (b.imag * b.imag);
    //~ double real_part = ((a.real * b.real) + (a.imag * b.imag)) / divisor;
    //~ double imag_part = ((a.imag * b.real) - (a.real * b.imag)) / divisor;
    //~ return Complex(real_part, imag_part);
    
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

// Gdy piszemy:
// cout << a << b << c;
// to kompilator to rozumie jak:
// ((cout << a) << b) << c;
// Czyli wywołuje operator << na obiekcie "cout" który jest typu ostream (strumień danych)
// do którego jest wrzucana wartość "a". To jak działa operator << na obiekcie ostream i obiekcie "a"
// określa przeciążony operator <<. Wewnątrz tego operatora zwykle stosujemy
// ten sam operator ale wyświetlamy dane, które ostream już potrafi obsłużyć, bo ma napisaną
// obsługę tego operatora dla podstawowych typów. Na końcu dodajemy return on
// aby na zwróconym obiekcie dało się ponownie wywołać operator << i wyświetlić obiekt b, a potem jeszcze
// raz na zwróconym obiekcie wyświetlamy obiekt c.















