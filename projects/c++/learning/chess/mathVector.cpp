#include "mathVector.h"


MathVector::MathVector() : vector<double>() {}

MathVector::MathVector(int size) : vector<double>(size) {}

MathVector::MathVector(const MathVector& v) : vector<double>(v) {}


MathVector& MathVector::operator += (const MathVector& v) {
	if (size() != v.size()) throw SizeException();

	for (int i = 0; i < (int)size(); i++) (*this)[i] += v[i];

	return *this;
}

MathVector& MathVector::operator -= (const MathVector& v) {
	if (size() != v.size()) throw SizeException();
	
	return (*this += (-v));
}

MathVector MathVector::operator -() const {
	MathVector v(*this);

	for (int i = 0; i < (int)size(); i++) v[i] = -v[i];

	return v;
}

MathVector operator + (const MathVector& a, const MathVector& b)
{
	if (a.size() != b.size()) throw SizeException();

	MathVector c(a);

	for (int i = 0; i < (int)c.size(); i++) c[i] = a[i] + b[i];

	return c;
}

MathVector operator - (const MathVector& a, const MathVector& b)
{
	if (a.size() != b.size()) throw SizeException();

	return a + (-b);
}

double operator * (const MathVector& a, const MathVector& b) {
	if (a.size() != b.size()) throw SizeException();

	double res = 0.0;
	for (int i = 0; i < (int)a.size(); i++) res += a[i] * b[i];

	return res;
}


std::ostream& operator << (std::ostream& out, const MathVector& v) {
	out << '[' << ' ';
	for (int i = 0; i < (int)v.size(); i++) out << v[i] << ' ';
	out << ']';

	return out;
}