#include <iostream>

using namespace std;

class Rational {
public:
    int number; // числитель
    int denom; // знаменатель

    Rational();
    Rational(int n);
    Rational(int n, int d);

    void simplify();

    Rational operator +(const Rational& r) const;
    Rational& operator -(const Rational& r);
    Rational operator -() const;
    Rational operator *(const Rational& r) const;
    Rational& operator /(const Rational& r);
    Rational& operator +=(const Rational& r);
    Rational& operator -=(const Rational& r);
    Rational& operator *=(const Rational& r);
    Rational& operator /=(const Rational& r);
    Rational& operator ++(); // префикс
    Rational operator ++(int); // постфикс
    Rational& operator --();
    Rational operator --(int);

    bool operator ==(const Rational& r) const;
    bool operator !=(const Rational& r) const;

    operator int() const;
    operator double() const;
    
    friend istream& operator >>(istream& in, Rational& r);
    friend ostream& operator <<(ostream& out, const Rational& r);
};