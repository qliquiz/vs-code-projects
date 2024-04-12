#include <iostream>
#include <vector>


void insertSort(std::vector< std::vector<int> > &arr, int size) {
    std::vector<int> buf;
    buf.reserve(2);
    int i, j;
    for (i = 1; i < size; i++) {
        buf[0] = arr[i][0];
        buf[1] = arr[i][1];
        for (j = i - 1; j >= 0 && buf[1] > arr[j][1]; j--) {
            arr[j + 1][0] = arr[j][0];
            arr[j + 1][1] = arr[j][1];
        }
        arr[j + 1][0] = buf[0];
        arr[j + 1][1] = buf[1];
    }
}


int main()
{
    int n;
    std::cin >> n;

    std::vector< std::vector<int> > vec(n);

    for (int i = 0; i < n; i++) {
        vec[i].reserve(2);
        for (int j = 0; j < 2; j++) std::cin >> vec[i][j];
    }

    insertSort(vec, n);

    for (int i = 0; i < n; i++) std::cout << vec[i][0] << ' ' << vec[i][1] << '\n';

    return 0;
}