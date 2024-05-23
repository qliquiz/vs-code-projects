#include "geometricFigure.h"


class Polygon : public GeometricFigure {
private:
    std::vector<Point> vertices;

public:
    Polygon(const std::vector<Point>& vertices) : vertices(vertices) {}

    Polygon(const std::string& filename) {
        std::ifstream file(filename);

        if (file.is_open()) {
            int n;
            file >> n;
            vertices.resize(n);

            for (int i = 0; i < n; i++) file >> vertices[i].x >> vertices[i].y;
            
            file.close();
        } else std::cerr << "File opening error!" << std::endl;
    }

    double calc_area() const override {
        double area = 0;
        for (int i = 0; i < vertices.size() - 1; i++) area += vertices[i].x * vertices[i + 1].y - vertices[i + 1].x * vertices[i].y;
        area += vertices[vertices.size() - 1].x * vertices[0].y - vertices[0].x * vertices[vertices.size() - 1].y;
        return abs(area) / 2;
    }

    double calc_perimetr() const override {
        double perimeter = 0;
        for (int i = 0; i < vertices.size() - 1; i++) perimeter += distance(vertices[i], vertices[i + 1]);
        perimeter += distance(vertices[vertices.size() - 1], vertices[0]);
        return perimeter;
    }

    void name() const override { std::cout << "Polygon" << std::endl; }

private:
    double distance(const Point& p1, const Point& p2) const { return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)); }
};