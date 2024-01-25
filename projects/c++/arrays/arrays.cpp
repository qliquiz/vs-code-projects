#include <iostream>

using namespace std;

void insert(int* arr, int size, int insert_index, int n) {
    for (int i = size - 1; i > insert_index; i--) arr[i] = arr[i - 1];
    arr[insert_index] = n;
}

int main()
{
    int arr[10] = {1, 2, 4};
    int size = sizeof(arr)/sizeof(arr[0]);

    insert(arr, size, 2, 3);
    insert(arr, size, 4, 5);
    
    for (int i = 0; i < size; i++) cout << arr[i] << '\t';

    return 0;
}