#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    string str;
    cin >> str;

    int size = str.size();

    stack<char> st;
    vector<char> res;
    
    for (int i = 0; i < size; i++) {
        if (!st.empty() && st.top() == str[i]) st.pop();
        else st.push(str[i]);
    }
    
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }

    for (int i = 0; i < res.size(); i++) cout << res[res.size() - 1 - i];

    return 0;
}