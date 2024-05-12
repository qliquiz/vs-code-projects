#include <iostream>
#include "figures.cpp"
#include "mathVector.cpp"


int main()
{
	MathVector v(3), w(3);

	v[0] = 1;
	v[1] = 3;
	v[2] = 6;
	w[0] = 2;
	w[1] = -1;
	w[2] = 4;

	std::cout << v << " + " << w << " = " << v + w << std::endl;
	std::cout << v << " - " << w << " = " << v - w << std::endl;
	std::cout << v << " * " << w << " = " << v * w << std::endl;
	
	return 0;
}