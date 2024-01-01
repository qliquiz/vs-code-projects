#include <iostream>

using namespace std;

void SortByInserts(int *arr) {
    int buf, i, j, size = sizeof(arr);
    for (i = 1; i < size; i++) {
        buf = arr[i];
        for (j = i - 1; j >= 0 && buf < arr[j]; j--) arr[j + 1] = arr[j];
        arr[j + 1] = buf;
    }
}

void HeapSort(int *arr) {
    int buf, size = sizeof(arr);
    for (int i = size; i > 1; i--) {
        // построение двоичного дерева
        bool flag = false;
        int sh = 0; // смещение
        for (int j = 0; j < i / 2; ) {
            int largest = j, left = 2 * j + 1, right = 2 * j + 2;
            if(arr[left] > arr[largest]) {
                buf = arr[left];
                arr[left] = arr[largest];
                arr[largest] = buf;
                flag = true;
            }
            if (right < i) {
                if (arr[right] > arr[largest]) {
                    buf = arr[right];
                    arr[right] = arr[largest];
                    arr[largest] = buf;
                    flag = true;
                }
            }
            if (flag && j > 0) {
                // возврат к корню для упорядочения ветки
                j = (j - 1) / 2;
                sh++;
                flag = false;
            } else {
                // продолжение построения дерева
                j = j + 1 + sh;
                sh = 0;
            }
        }
        // перестановка первого и последнего элементов
        buf = arr[i - 1];
        arr[i - 1] = arr[0];
        arr[0] = buf;
    }
}

int main()
{
    int arr[] = { 6, 5, 3, 1, 8, 7, 2, 4 };

    /* Сортировка вставками. 
    Метод хорош для сортировки данных, получаемых из входного потока.
    Наилучший случай: О(n). Средний, наихудший случаи: O(n^2). */
    // SortingByInserts(arr);
    
    /* Пирамидальная сортировка
    Краткое описание алгоритма:
    1. Подготовка (просеивание) – вершина дерева должна быть больше любого элемента в поддеревьях.
    2. Выбор – выкидываем вершину.
    3. Повтор – переходим к 1 с меньшим количеством вершин.
    Наилучший, средний, наихудший случаи: O(n*log(n)) */
    // HeapSort(arr);

    for (int i = 0; i < 8; i++) cout << arr[i];

    return 0;
}