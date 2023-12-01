#include <iostream>
#include <string>
using namespace std;

void primeFactors(int n, int divisor) {
    if (n <= 1) return; // Базовый случай: если n меньше или равно 1, выходим из функции

    if (n % divisor == 0) {
        int count = 0; // Счётчик кратности
        while (n % divisor == 0) {
            n /= divisor; // Уменьшаем n на divisor
            count++;
        }
        for (int i = 0; i < count; i++) {
            cout << divisor << " "; // Выводим делитель divisor столько раз, сколько он встречается в числе n
        }
    }
    primeFactors(n, divisor + 1); // Рекурсивно вызываем функцию для поиска оставшихся делителей
}

bool isPalindrome(string word, int start, int end) {
    if (start >= end) return true;  // Базовый случай: если начальный индекс больше или равен конечному, значит, слово - палиндром
    
    if (word[start] != word[end]) return false;  // Если символы, находящиеся на начальном и конечном индексах, не совпадают - слово не является палиндромом
    
    return isPalindrome(word, start + 1, end - 1);  // Рекурсивно вызываем функцию, сдвигая начальный индекс на 1 и конечный - на 1
}

bool equal(int N, int S, int sum) {
    if (sum == S) return true;

    if (N == 0) return false;

    sum += N % 10;
    N = N / 10;

    return equal(N, S, sum);
} 

int main()
{
    // №1
    /* int n;
    cin >> n;
    primeFactors(n, 2); */

    // №2
    /* string word;
    cin >> word;
    if (isPalindrome(word, 0, word.length() - 1)) cout << "YES" << endl;
    else cout << "NO" << endl; */

    // №3
    /* if(equal(1234, 10, 0)) cout << "true" << endl;
    else cout << "false" << endl; */

    return 0;
}