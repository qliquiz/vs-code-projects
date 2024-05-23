#include "geometricFigure.h"


class Ellipse : public GeometricFigure {
private:
    Point center;
    double radius1, radius2;

public:
    Ellipse(const Point& center, double radius1, double radius2) : center(center), radius1(radius1), radius2(radius2) {}

    double calc_area() const override { return M_PI * radius1 * radius2; }

    double calc_perimetr() const override { return 2 * M_PI * sqrt((radius1 * radius1 + radius2 * radius2) / 2); }

    void name() const override { std::cout << "Ellipse" << std::endl; }
};