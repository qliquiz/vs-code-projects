#include <math.h>
#include "point.h"
#include "triangle.h"

#ifndef _GEOMETRY_H
#define _GEOMETRY_H
double calcDistance(const Point& p1, const Point& p2);
double calcAreaBySides(double a, double b, double c);
double calcTriangleArea(Triangle& tr);
#endif 

Point::Point() {
    x = y = 0.0;
}

Triangle::Triangle() {
    // конструктор вершин-точек вызовется автоматически
    area = 0.0;
}

double calcDistance(const Point& p1, const Point& p2);

double calcAreaBySides(double a, double b, double c);

double calcTriangleArea(Triangle& tr);

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

void Point::clear() {
    x = y = 0.0;
}

double Point::calcDistance(const Point& p) const {
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
}

void Triangle::clear() {
    for (int i = 0; i < 3; i++) vertexes[i].clear();
    area = 0.0;
}

double Triangle::calcArea() {
    double a = vertexes[0].calcDistance(vertexes[1]);
    double b = vertexes[1].calcDistance(vertexes[2]);
    double c = vertexes[2].calcDistance(vertexes[0]);
    return area = calcAreaBySides(a, b, c);
}

bool Triangle::operator <=(const Triangle& tr) const {
    return area <= tr.area;
}

/* bool operator <=(const Triangle& tr1, const Triangle& tr2) {
    return tr1.area <= tr2.area;
} */