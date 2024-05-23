#include "geometricFigure.h"


class Rectangle : public GeometricFigure {
private:
    std::vector<Point> vertices;

public:
    Rectangle(const std::vector<Point>& vertices) : vertices(vertices) {}

    Rectangle(double side1, double side2) {
        vertices.push_back({ 0, 0 });
        vertices.push_back({ side1, 0 });
        vertices.push_back({ side1, side2 });
        vertices.push_back({ 0, side2 });
    }

    double calc_area() const override { return distance(vertices[0], vertices[1]) * distance(vertices[1], vertices[2]); }

    double calc_perimetr() const override { return 2 * (distance(vertices[0], vertices[1]) + distance(vertices[1], vertices[2])); }

    void name() const override { std::cout << "Rectangle" << std::endl; }

private:
    double distance(const Point& p1, const Point& p2) const { return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)); }
};