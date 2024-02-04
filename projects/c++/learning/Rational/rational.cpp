#include "rational.h"
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    // Тестируем конструктор, +, -, *=, /, <<
    Rational a(1, 2), b(-1, 6);
    cout << "a = " << a << " b = " << b << " a + b = " << a + b << '\n';
    cout << "a(" << a << ") *= b(" << b << ")" << '\n';
    
    a *= b;
    cout << "a = " << a <<" b = " << b << " a - b = " << a - b << '\n';
    Rational c = 3;
    cout << "b = " << b << " c = " << c << " b / c = " << b / c << "\n\n";

    // Тестируем >>, !=
    Rational e(1, 3), f(2, 5);
    cout << "e = " << e << '\t' << "f = " << f << '\t' << "e + f = ? " << '\n';
    cout << "Введите результат g = m / n в формате: m n" << '\n';

    Rational g;
    cin >> g;
    if (e + f != g) cout << "Неправильно! e + f = " << e + f << '\n';
    else cout << "Правильно!" << '\n';

    return 0;
}

Rational::Rational() {
    number = 0;
    denom = 1;
}

Rational::Rational(int n) {
    number = n;
    denom = 1;
}

Rational::Rational(int n, int d) {
    number = n;
    denom = d;
}

void Rational::simplify() {
    if (denom < 0) {
        number = -number;
        denom = -denom;
    }
    for (int i = 2; i < abs(denom) && i <= abs(number); i++) {
        if (number % i == 0 && denom % i == 0) {
            number /= i;
            denom /= i;
            i--;
        }
    }
}

Rational& Rational::operator +=(const Rational& r) {
    number = (number * r.denom + denom * r.number);
    denom *= r.denom;
    simplify();
    return *this;
}

Rational& Rational::operator -=(const Rational& r) {
    return *this += -r;
}

Rational& Rational::operator *=(const Rational& r) {
    number *= r.number;
    denom *= r.denom;
    simplify();
    return *this;
}

Rational& Rational::operator /=(const Rational& r) {
    number *= r.denom;
    denom *= r.number;
    simplify();
    return *this;
}

Rational Rational::operator +(const Rational& r) const {
    Rational res(*this);
    return res += r;
}

Rational& Rational::operator -(const Rational& r) {
    number = (number * r.denom - denom * r.number);
    denom *= r.denom;
    simplify();
    return *this;
}

Rational Rational::operator -() const {
    Rational r(-number, denom);
    return r;
}

Rational Rational::operator *(const Rational& r) const {
    Rational res(*this);
    return res *= r;
}

Rational& Rational::operator /(const Rational& r) {
    number *= r.denom;
    denom *= r.number;
    simplify();
    return *this;
}

Rational& Rational::operator ++() {
    number += denom;
    return *this;
}

Rational Rational::operator ++(int) {
    Rational r(*this);
    number += denom;
    return r;
}

Rational& Rational::operator --() {
    number -= denom;
    return *this;
}

Rational Rational::operator --(int) {
    Rational r(*this);
    number -= denom;
    return r;
}

bool Rational::operator ==(const Rational& r) const {
    return (number==r.number) && (denom==r.denom);
}

bool Rational::operator !=(const Rational& r) const {
    return !(*this==r);
}

Rational::operator int() const {
    return number / denom;
}

Rational::operator double() const {
    return ((double)number)/denom;
}

istream& operator >>(istream& in, Rational& r) {
    in >> r.number >> r.denom;
    return in;
}

ostream& operator <<(ostream& out, const Rational& r) {
    out << r.number << "/" << r.denom;
    return out;
}