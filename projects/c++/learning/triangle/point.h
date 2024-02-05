#include <iostream>

using namespace std;

struct Point {
// private:
    double x, y;
// public:
    Point();

    void clear();
    double calcDistance(const Point& p) const;
    // Глобальные функции-друзья, имеющие доступ к закрытым полям
    friend istream& operator >>(istream& in, Point& p);
    friend ostream& operator <<(ostream& out, const Point& p);
};