#define _USE_MATH_DEFINES
#ifndef GEOMETRICFIGURE_CPP
#define GEOMETRICFIGURE_CPP
#include <math.h>
#include <iostream>
#include <vector>
#include <fstream>


struct Point {
    double x, y;
};


class GeometricFigure {
public:
    virtual double calc_area() const = 0;
    virtual double calc_perimetr() const = 0;
    virtual void name() const = 0;
};


#endif