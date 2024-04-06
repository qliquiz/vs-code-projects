#include <iostream>
#include <string>

using namespace std;

string guess(int low = 1, int up = 1000000) {
    if (low + 1 >= up) cout << "! " << to_string(low) << endl;
    else
    {
        cout << (low + up) / 2 << endl;
        fflush(stdout);
        string res = "";
        while (low + 1 < up) {
            cin >> res;
            if (res[0] == '>') guess((low + up) / 2, up);
            if (res[0] == '<') guess(low, (low + up) / 2);
        }
    }
}

int main()
{
    guess();

    return 0;
}