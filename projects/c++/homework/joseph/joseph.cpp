#include <iostream>
#include <vector>

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
    int n = 13; // Количество участников
    int k = 3; // Шаг для убийства

    int survivor = joseph(n, k);
    cout << "Survivor number: " << survivor;

    return 0;
}