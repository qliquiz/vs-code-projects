#include <sstream>
#include "circle.cpp"
#include "ellipse.cpp"
#include "polygon.cpp"
#include "rectangle.cpp"
#include "triangle.cpp"


int main() {
    Point point1(0, 0), point2(4, 0), point3(4, 4), point4(0, 4);
    std::vector<Point> vertices;
    Rectangle rectangle(vertices);

    rectangle.calc_perimetr();
    rectangle.calc_area();

    return 0;
}