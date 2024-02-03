#include <iostream>

using namespace std;

class Rational {
public:
    int number; // числитель
    int denom; // знаменатель

    Rational();
    Rational(int number);
    Rational(int number, int denom);

    void simplify();

    Rational& operator +=(const Rational& r);
    Rational operator +(const Rational& r) const;
    Rational operator -() const;
    Rational& operator -=(const Rational& r);
    Rational& operator ++(); // префикс
    Rational operator ++(int); // постфикс

    bool operator ==(const Rational& r) const;
    bool operator !=(const Rational& r) const;

    operator int() const;
    operator double() const;
    
    friend istream& operator >>(istream& in, Rational& r);
    friend ostream& operator <<(ostream& out, const Rational& r);
};