#include <math.h>

#ifndef _GEOMETRY_H
#define _GEOMETRY_H
double calcDistance(const Point& p1, const Point& p2);
double calcAreaBySides(double a, double b, double c);
#endif 

struct Point {
    double x, y;
};

struct Triangle {
    Point vertexes[3];
    double area;

    bool operator <=(const Triangle& triangle) const;
};

double calcArea(const Point& p1, const Point& p2, const Point& p3);

double calcDistance(const Point& p1, const Point& p2);

double calcAreaBySides(double a, double b, double c);

double calcTriangleArea(Triangle& tr);

double calcArea(const Point& p1, const Point& p2, const Point& p3) {
    return fabs((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y));
}

double calcDistance(const Point& p1, const Point& p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

double calcAreaBySides(double a, double b, double c) {
    double p2 = (a + b + c) / 2.0;
    if (p2 <= 0.0 || p2 <= a || p2 <= b || p2 <= c) return 0.0;
    return sqrt(p2 * (p2 - a) * (p2 - b) * (p2 - c));
}

double calcTriangleArea(Triangle& tr) {
    Point* v = tr.vertexes;
    double a = calcDistance(v[0], v[1]);
    double b = calcDistance(v[1], v[2]);
    double c = calcDistance(v[2], v[0]);
    return tr.area = calcAreaBySides(a, b, c);
}

bool Triangle::operator <=(const Triangle& triangle) const {
    return area <= triangle.area;
}