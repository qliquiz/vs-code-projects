#include <iostream>
#include <string>

using namespace std;

void guess(int low = 1, int up = 1000000) {
    if (low + 1 >= up) {
        cout << up << endl;
        fflush(stdout);
        string res = "";
        cin >> res;
        if (res == ">=") cout << "! " << to_string(up) << endl;
        else cout << "! " << to_string(low) << endl;
    }
    else {
        cout << (low + up) / 2 << endl;
        fflush(stdout);
        string res = "";
        cin >> res;
        if (res == ">=") guess((low + up) / 2, up);
        else if (res == "<") guess(low, (low + up) / 2);
    }
}

int main()
{
    guess();

    return 0;
}