#include <iostream>
#define COLUMNS 3

using namespace std;

void insert(int* arr, int length, int ins_index, int n) {
    for (int i = length - 1; i > ins_index; i--) arr[i] = arr[i - 1];
    arr[ins_index] = n;
}

void del(int* arr, int length, int del_index) {
    for (int i = del_index; i < length - 1; i++) arr[i] = arr[i + 1];
}

void insertSort(int* arr, int length) {
    int buf, i, j;
    for (i = 1; i < length; i++) {
        buf = arr[i];
        for (j = i - 1; j >= 0 && buf < arr[j]; j--) arr[j + 1] = arr[j];
        arr[j + 1] = buf;
    }
}

void showDoubleArr(int (*arr)[COLUMNS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLUMNS; j++) cout << arr[i][j] << ' ';
        cout << '\n';
    }
}

void showDoubleArr2(int* arr, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) cout << arr[i * columns + j] << ' ';
        cout << '\n';
    }
}

void FillArray(int* const arr, const int size) {
    for (int i = 0; i < size; i++) arr[i] = rand() % 10;
}

void ShowArray(const int* const arr, const int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << "\t";
    cout << endl;
}

void push_back(int *&arr, int &size, const int value) {
    int *newArray = new int[size + 1];
    for (int i = 0; i < size; i++) newArray[i] = arr[i];
    newArray[size] = value;
    size++;
    delete[] arr;
    arr = newArray;
}

void pop_back(int *&arr, int &size) {
    size--;
    int *newArray = new int[size];
    for (int i = 0; i < size; i++) newArray[i] = arr[i];
    delete[] arr;
    arr = newArray;
}

int main()
{
    /* int arr[10] = {4, 2, 1};
    int length = sizeof(arr)/sizeof(*arr);

    insert(arr, length, 2, 3);

    del(arr, length, 3);

    insertSort(arr, length);
    
    for (int i = 0; i < length; i++) cout << arr[i] << ' '; */

    /* int arr2[][COLUMNS] = {{1, 2, 3}, {4, 5, 6}};
    int arr3[] = {1, 2, 3, 4, 5, 6};

    showDoubleArr(arr2, sizeof(arr2)/sizeof(*arr2));
    showDoubleArr2(arr3, 2, 3); */

    /* int size = 5;

    int *arr = new int[size];

    FillArray(arr, size);

    ShowArray(arr, size);

    push_back(arr, size, 111);

    ShowArray(arr, size);

    pop_back(arr, size);

    ShowArray(arr, size);

    delete[] arr; */

    return 0;
}