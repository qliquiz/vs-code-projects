#include <iostream>

using namespace std;

int main()
{
    char dict[4][10] = {"fram", "farm", "fish", "famr"};
    char*** result = new char**[][];
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            int sum1 = 0;
            int sum2 = 0;
            for (int k = 0; k < 4; k++) {
                sum1 += dict[i][k];
                sum2 += dict[j][k];
            }
            if (sum1 == sum2) {
                cout << dict[i] << '\t' << dict[j] << '\t';
                result[i][0] = dict[i];
            }
            sum1 = 0;
            sum2 = 0;
        }
        cout << '\n';
    }

    return 0;
}