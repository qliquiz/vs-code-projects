#include "point.h"

using namespace std;

struct Triangle {    
    Point vertexes[3];
    double area;

    Triangle();

    void clear();
    double calcArea();
    bool operator <=(const Triangle& tr) const;
};

ostream& operator <<(ostream& out, const Triangle& tr);