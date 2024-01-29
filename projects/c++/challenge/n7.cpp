#include <iostream>

using namespace std;

// Вывод массива
void showArr(int** arr, int length) {
    for (int i = 0; i < length; i++) cout << "(" << *arr[i] << ", " << arr[i][1] << ") ";
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

// Удаление одинаковых точек
void deleteRepeats(int** arr, int& length) {
    for (int i = 0; i < length - 1; i++) {
        if (*arr[i] == *arr[i + 1] && arr[i][1] == arr[i + 1][1]) {
            length--;
            for (int j = i; j < length; j++) {
                *arr[j] = *arr[j + 1];
                arr[j][1] = arr[j + 1][1];
            }
        }
    }
}

/* void showArr2(int* arr, int length) {
    for (int i = 0; i < length; i += 2) cout << "(" << arr[i] << ", " << arr[i + 1] << ") ";
    cout << endl;
}

void mySort2(int* arr, int length) {
    for (int i = 1; i < length; i++) {
        int sorted = i - 1;
        int temp;
        while (sorted > -1 && arr[sorted] > arr[sorted + 1]) {
            temp = arr[sorted];
            arr[sorted] = arr[sorted + 1];
            arr[sorted + 1] = temp;
            sorted--;
        }
    }
}

void deleteRepeats2(int* arr, int& length) {
    for (int i = 0; i < length - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            length--;
            for (int j = i; j < length; j++) arr[j] = arr[j + 1];
        }
    }
} */

// Проверка, лежат ли 3 точки на одной прямой
bool arePointsLinear(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1);
}

// Функция для вычисления всех возможных групп точек, лежащих на одной прямой
void findLinearPoints(int** arr, int length) {
    for (int i = 0; i < length - 2; i++) {
        for (int j = i + 1; j < length - 1; j++) {
            for (int k = j + 1; k < length; k++) {
                if (arePointsLinear(*arr[i], arr[i][1], *arr[j], arr[j][1], *arr[k], arr[k][1])) 
                    cout << '(' << *arr[i] << ", " << arr[i][1] << ") (" << *arr[j] << ", " << arr[j][1] << ") (" << *arr[k] << ", " << arr[k][1] << ')' << endl;
            }
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

    deleteRepeats(points, length);

    // showArr(points, length);

    findLinearPoints(points, length); // вызываем функцию

    delete [] points;

    return 0;
}