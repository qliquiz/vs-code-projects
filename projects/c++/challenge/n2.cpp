#include <iostream>
#include <cmath>

struct Point {
    int x, y;
};

int main()
{
    Point points[] = {{3, 3}, {-2, 2}, {2, -2}, {-3, -3}};
    int length = sizeof(points) / sizeof(points[0]);
    Point minX1 = {100000000, 0}, minX2 = {100000000, 0}, maxX1 = {-100000000, 0}, maxX2 = {-100000000, 0}, first, second, third, fourth;

    for (int i = 0; i < length; i++) {
        if (points[i].x < minX1.x) {
            minX2 = minX1;
            minX1 = points[i];
        } else if (points[i].x < minX2.x) minX2 = points[i];
    }

    (minX1.y > minX2.y) ? (first = minX1, fourth = minX2) : (first = minX2, fourth = minX1);

    for (int i = 0; i < length; i++) {
        if (points[i].x > maxX1.x) {
            maxX2 = maxX1;
            maxX1 = points[i];
        } else if (points[i].x > maxX2.x) maxX2 = points[i];
    }

    (maxX1.y > maxX2.y) ? (second = maxX1, third = maxX2) : (second = maxX2, third = maxX1);

    std::cout << '(' << first.x << "; " << first.y << "), (" << second.x << "; " << second.y << "), (" << third.x << "; " << third.y << "), (" << fourth.x << "; " << fourth.y << ')';

    return 0;
}