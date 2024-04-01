#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const vector<int>& left, const vector<int>& right) { return left[1] > right[1]; }

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> vec(n);

    for (int i = 0; i < n; i++) {
        vec[i].reserve(2);
        for (int j = 0; j < 2; j++) cin >> vec[i][j];
    }

    sort(begin(vec), end(vec), compare);

    for (int i = 0; i < n; i++) {
        cout << vec[i][0] << ' ' << vec[i][1];
        cout << endl;
    }

    return 0;
}