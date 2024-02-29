#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int joseph(int n, int k) {
    vector<int> people;
    for (int i = 1; i <= n; i++) people.push_back(i); // Заполняем вектор участниками

    auto it = people.begin();
    while (people.size() > 1) {
        for (int c = 1; c < k; c++) { 
            it++; // Поиск k-ого шага
            if (it == people.end()) it = people.begin();
        }
        it = people.erase(it); // Убийство
        if (it == people.end()) it = people.begin();
    }
    return people.front();
}

int main() {
    int n = 1000 ; // Количество участников
    int k = 2; // Шаг для убийства

    clock_t start = clock();
    int survivor = joseph(n, k);
    clock_t end = clock();

    double time = (end - start);

    cout << "Survivor number: " << survivor << endl;
    cout << "The time: " << time << endl;

    return 0;
}