#include <iostream>

using namespace std;

void turingMachine(char tape[], int n) {
    for (int i = 0; i < n - 2; i++) {
        if (tape[i] == '0' && tape[i + 1] == '1' && tape[i + 2] == '0') {
            tape[i] = '1';
            tape[i + 1] = '#'; // заменяем символ 1 на #, чтобы отличать от исходных символов
            tape[i + 2] = '#'; // заменяем символ 0 на #, чтобы отличать от исходных символов
        }
    }
}

int main() {
    int n;
    cout << "Enter the length of the tape (multiple of 3): ";
    cin >> n;

    char tape[n];

    cout << "Enter the tape: ";
    for (int i = 0; i < n; i++) {
        cin >> tape[i];
    }

    turingMachine(tape, n);

    cout << "Modified tape: ";
    for (int i = 0; i < n; i++) {
        cout << tape[i] << " ";
    }
    cout << endl;

    return 0;
}