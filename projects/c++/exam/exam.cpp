#include <iostream>

using namespace std;

// Структура для представления точки на плоскости
struct Point {
    int x, y;
};

// Функции проверки трёх точек
bool arePointsCollinear(Point p1, Point p2, Point p3) {
    int x1 = p1.x, y1 = p1.y;
    int x2 = p2.x, y2 = p2.y;
    int x3 = p3.x, y3 = p3.y;
    // Проверка пропорциональности разностей координат
    return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1);
}

// Функция для вычисления всех возможных групп точек, лежащих на одной прямой
void findCollinearPoints(struct Point points[], int n) {
    int count = 0; 
    int maxCount = 0;
    int duplicate = 0; // количество дублирующихся точек

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int l = j + 1; l < n; l++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y || points[i].x == points[l].x && points[i].y == points[l].y || points[l].x == points[j].x && points[l].y == points[j].y)
                    duplicate++;
                else if (arePointsCollinear(points[i], points[j], points[l])) {
                    cout << "(" << points[i].x << ", " << points[i].y << ")" << '\t' << "(" << points[j].x << ", " << points[j].y << ")" << '\t' << "(" << points[l].x << ", " << points[l].y << ")" << '\n';
                    count++;
                }
            }
        }
    }
    if (count > 0 && count < 4) count += 3; // компенсация первой проверки
    count -= duplicate; // удаляем дубликаты
    if (count < 2) count = 0; // базовый случай
    if (count > maxCount) maxCount = count;
    count = 0;
    duplicate = 0;
    cout << "Максимальное количество точек на одной прямой: " << maxCount; // ответ
}

int main() {
    struct Point points[] = {{1, 1}, {2, 2}, {3, 2}, {3, 3}, {4, 4}, {5, 4}}; // пример входных данных
    int n = sizeof(points) / sizeof(points[0]); // вычисляем количество точек
    findCollinearPoints(points, n); // вызываем функцию

    return 0;
}