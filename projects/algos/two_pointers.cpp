#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n, s, sum = 0, res = 0, ans = 0;
    cin >> n >> s;

    vector<int> vec(n);

    for (int i = 0; i < n; i++) cin >> vec[i];

    int l = 0;
    int r = l;

    while (r < n) {
        if (sum + vec[r] <= s) {
            sum += vec[r];
            res++;
            r++;
            ans = max(res, ans);
        } else {
            l++;
            r = l;
            ans = max(res, ans);
            res = 0;
            sum = 0;
        }
    }

    cout << ans;

    return 0;
}