#include <vector>
#include <ostream>


class SizeException {};


class MathVector : public std::vector<double> {
public:
	MathVector() : vector<double>() {}

	MathVector(int size) : vector<double>(size) {}

	MathVector(const MathVector& v) : vector<double>(v) {}


	MathVector& operator +=(const MathVector& v) {
		if (size() != v.size()) throw SizeException();

		for (int i = 0; i < (int)size(); i++) (*this)[i] += v[i];

		return *this;
	}

	MathVector& operator -=(const MathVector& v) {
		if (size() != v.size()) throw SizeException();

		return (*this += (-v));
	}

	MathVector operator -() const {
		MathVector v(*this);

		for (int i = 0; i < (int)size(); i++) v[i] = -v[i];

		return v;
	}


	friend MathVector operator +(const MathVector& a, const MathVector& b) {
		if (a.size() != b.size()) throw SizeException();

		MathVector c(a);

		for (int i = 0; i < (int)c.size(); i++) c[i] = a[i] + b[i];

		return c;
	}

	friend MathVector operator -(const MathVector& a, const MathVector& b) {
		if (a.size() != b.size()) throw SizeException();

		return a + (-b);
	}

	friend double operator *(const MathVector& a, const MathVector& b) {
		if (a.size() != b.size()) throw SizeException();

		double res = 0.0;
		for (int i = 0; i < (int)a.size(); i++) res += a[i] * b[i];

		return res;
	}
	

	friend std::ostream& operator <<(std::ostream& out, const MathVector& v) {
		out << '[' << ' ';
		for (int i = 0; i < (int)v.size(); i++) out << v[i] << ' ';
		out << ']';

		return out;
	}
};