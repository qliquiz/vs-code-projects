#include <iostream>
#include <random>

using namespace std;

string guess(int n = 500000, int low = 1, int up = 1000000) {
    cout << n;
    string res = "";
    while (low + 1 < up) {
        cin >> res;
        if (res == ">=") guess(n, n, up);
        if (res == "<=") guess(n, low, n);
        if (res == ">") guess(n * 1.5, n, up);
        if (res == "<") guess(n / 2, low, n);
    }
}

int main()
{
    guess();

    return 0;
}