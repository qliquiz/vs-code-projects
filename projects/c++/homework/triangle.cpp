#include <iostream>
#include <math.h>

struct Point {
    int x, y;
};

double FindArea(Point& p1, Point& p2, Point& p3) {
    return fabs((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y)) ;
}

int main()
{
    Point points[9] = {{2, 3}, {4, 1}, {10, 10}, {8, 4}, {5, 2}, {7, 1}, {6, 5}, {2, 9}, {11, 8}};
    Point* result = new Point[3];
    double maxArea = 0;

    for (int i = 0; i < 9 - 2; i++) {
        for (int j = i + 1; j < 9 - 1; j++) {
            for (int k = j + 1; k < 9; k++) {
                if (FindArea(points[i], points[j], points[k]) > maxArea) {
                    result[0] = points[i];
                    result[1] = points[j];
                    result[2] = points[k];
                }
            }
        }
    }
    
    for (int i = 0; i < 3; i++) std::cout << '(' << result[i].x << ", " << result[i].y << ")\t";

    return 0;
}