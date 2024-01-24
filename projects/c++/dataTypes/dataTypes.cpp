#include <iostream>

using namespace std;

int main()
{
    int a = 5;
    int* pa = &a;
    int& aref = *pa;
    int* ppa = &aref;

    cout << *ppa << endl;

    *ppa = 12;

    cout << *ppa << endl;

    return 0;
}