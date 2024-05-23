#include "geometricFigure.h"


class Circle : public GeometricFigure {
private:
    Point center;
    double radius;

public:
    Circle(const Point& center, double radius) : center(center), radius(radius) {}

    double calc_area() const override { return M_PI * radius * radius; }

    double calc_perimetr() const override { return 2 * M_PI * radius; }

    void name() const override { std::cout << "Cirlce" << std::endl; }
};