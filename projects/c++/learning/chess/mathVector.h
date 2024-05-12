#include <vector>
#include <ostream>
#ifndef MATHVEC_H
#define MATHVEC_H


class SizeException {};


class MathVector : public std::vector<double> {
public:
	MathVector();
	MathVector(int size);
	MathVector(const MathVector& v);

	MathVector& operator +=(const MathVector& v);
	MathVector& operator -=(const MathVector& v);
	MathVector operator -() const;

	friend MathVector operator +(const MathVector& a, const MathVector& b);
	friend MathVector operator -(const MathVector& a, const MathVector& b);
	friend double operator *(const MathVector& a, const MathVector& b);

	friend std::ostream& operator <<(std::ostream& out, const MathVector& v);
};


#endif