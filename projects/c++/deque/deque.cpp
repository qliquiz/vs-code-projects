#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq {1, 2, 3};

    auto position_iterator = dq.cbegin();
    dq.insert(++position_iterator, 100);
    dq.erase(position_iterator);

    dq.push_front(0);
    dq.push_back(4);

    dq.pop_front();
    dq.pop_back();

    cout << dq.front() << endl;
    cout << dq.back() << endl;

    dq.clear();

    for (auto iterator = dq.cbegin(); iterator != dq.cend(); ++iterator) cout << *iterator << " ";

    return 0;
}