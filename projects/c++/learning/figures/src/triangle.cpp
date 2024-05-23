#include "geometricFigure.h"


class Triangle : public GeometricFigure {
private:
    std::vector<Point> vertices;

public:
    Triangle(const std::vector<Point>& vertices) : vertices(vertices) {}

    Triangle(const Point& v1, const Point& v2, const Point& v3) : vertices({ v1, v2, v3 }) {}

    Triangle(double side1, double side2, double side3) {
        // Конструктор, принимающий стороны
        vertices.push_back({ 0, 0 });
        vertices.push_back({ side1, 0 });
        // Вычисляем координаты третьей вершины по теореме косинусов
        double angle = acos((side1 * side1 + side2 * side2 - side3 * side3) / (2 * side1 * side2));
        vertices.push_back({ side1 * cos(angle), side1 * sin(angle) });
    }

    double calc_area() const override {
        // Формула Герона
        double s = (calc_perimetr() / 2);
        return sqrt(s * (s - distance(vertices[0], vertices[1])) * (s - distance(vertices[1], vertices[2])) * (s - distance(vertices[2], vertices[0])));
    }

    double calc_perimetr() const override { return distance(vertices[0], vertices[1]) + distance(vertices[1], vertices[2]) + distance(vertices[2], vertices[0]); }

    void name() const override { std::cout << "Triangle" << std::endl; }

private:
    double distance(const Point& p1, const Point& p2) const { return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)); }
};