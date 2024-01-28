#include <iostream>

using namespace std;

void showArr(int** arr, int length) {
    for (int i = 0; i < length; i++) cout << "(" << arr[i][0] << ", " << arr[i][1] << ") ";
    cout << endl;
}

// Сортировка пузырьком
void mySort(int** arr, int length) {
    for (int i = 1; i < length; i++) {
        int sorted = i - 1;
        int* temp;
        while (sorted > -1 && *arr[sorted] > *arr[sorted + 1]) {
            temp = arr[sorted];
            arr[sorted] = arr[sorted + 1];
            arr[sorted + 1] = temp;
            sorted--;
            if (sorted > -1 && *arr[sorted] == *arr[sorted + 1] && arr[sorted][1] > arr[sorted + 1][1]) {
                temp = arr[sorted];
                arr[sorted] = arr[sorted + 1];
                arr[sorted + 1] = temp;
                sorted--;
            }
        }
    }
}

bool arePointsLinear(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1);
}

// Функция для вычисления всех возможных групп точек, лежащих на одной прямой
void findLinearPoints(int** arr, int length) {
    int** result = new int*[length];
    for (int i = 0; i < length; i++) {
        if (arePointsLinear(*arr[i], arr[i][1], *arr[i + 1], arr[i + 1][1], *arr[i + 2], arr[i + 2][1])) {

        }
    }
}

int main() {
    int length;
    cout << "Введите количество точек: ";
    cin >> length;

    int** points = new int* [length];
    for (int i = 0; i < length; i++) points[i] = new int[2];

    cout << "Введите элементы массива: " << endl;
    for (int i = 0; i < length; i++) {
        cout << "Точка " << i + 1 << ": x = ";
        cin >> points[i][0];
        cout << "\t y = ";
        cin >> points[i][1];
        cout << endl;
    }

    showArr(points, length);

    mySort(points, length);

    // Удаление повторов
    for (int i = 0; i < length - 1; i++) {
        if (*points[i] == *points[i + 1] && points[i][1] == points[i + 1][1]) {
            /* int** newPoints = new int*[--length];
            for (int i = 0; i < length; i++) newPoints[i] = new int[2];
            for (int j = 0; j < length; j++) {
                if (j == i) {
                    *newPoints[j] = *points[j + 1];
                    newPoints[j][1] = points[j + 1][1];
                } else {
                    *newPoints[j] = *points[j];
                    newPoints[j][1] = points[j][1];
                }
            } */
            length--;
            for (int j = i; j < length; j++) {
                *points[j] = *points[j + 1];
                points[j][1] = points[j + 1][1];
            }
        }
    }
    // delete [] points;

    showArr(points, length);

    // find2linearPoints(points, n); // вызываем функцию

    // delete [] newPoints;

    return 0;
}