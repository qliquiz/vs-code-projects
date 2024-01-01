#include <iostream>

using namespace std;

string turing(string str) {
    int state = 0, i = 0;

    while (state != -1) {
        switch (state) {
            case 0:
                if (str[i] == '0') {
                    str[i] = '0';
                    i++;
                    state = 0;
                } else {
                    str[i] = '0';
                    i--;
                    state = 1;
                }
                break;
            case 1:
                if (str[i] == '0') {
                    str[i] = '1';
                    i--;
                    state = 2;
                } else {
                    str[i] = '1';
                    i = i;
                    state = 1;
                }
                break;
            case 2:
                if (str[i] == '0') {
                    str[i] = '1';
                    i++;
                    state = 2;
                } else {
                    str[i] = '1';
                    i++;
                    state = 3;
                }
                break;
            case 3:
                if (str[i] == '0') {
                    str[i] = '1';
                    i++;
                    state = 4;
                } else {
                    str[i] = '1';
                    i++;
                    state = 3;
                }
                break;
            case 4:
                if (str[i] == '0') {
                    state = -1;
                } else {
                    str[i] = '0';
                    i--;
                    state = 5;
                }
                break;
            case 5:
                if (str[i] == '0') {
                    str[i] = '1';
                    i--;
                    state = 2;
                } else {
                    str[i] = '1';
                    i--;
                    state = 5;
                }
                break;

            default:
                break;
        }
    }
    
    return str;
}

// Функция для перевода символа в число
int charToInt(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    else if (c >= 'A' && c <= 'Z') return 10 + (c - 'A');
    return -1;  // в случае ошибки
}
// Функция для проверки, справедливо ли умножение в данной системе счисления
bool isValidMultiplication(const string& expression, int base) {
    size_t pos = expression.find('*');
    string num1 = expression.substr(0, pos);
    string num2 = expression.substr(pos + 1, expression.find('=') - pos - 1);
    string result = expression.substr(expression.find('=') + 1);
    int n1 = 0, n2 = 0, res = 0;

    for (char c : num1) n1 = n1 * base + charToInt(c);

    for (char c : num2) n2 = n2 * base + charToInt(c);

    for (char c : result) res = res * base + charToInt(c);

    return (n1 * n2) == res;
}

int main()
{
    setlocale(0, "");

    string expression = "213*3=1144";

    for (int base = 2; base <= 16; ++base) if (isValidMultiplication(expression, base)) cout << "Умножение справедливо в системе счисления " << base << endl;

    // cout << turing("10101");

    return 0;
}