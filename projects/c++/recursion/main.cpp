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
    if (sum == S) return true; // Если сумма чисел равна числу S, возвращаем true

    if (N == 0) return false; // Если не вернули true, а N уже закончилось, возвращаем false

    sum += N % 10; // sum + одно число из N
    N = N / 10; // N на число меньше

    return equal(N, S, sum);
} 

int divs(int n, int i, int count) {
    if (i == 1) return count;
    else {
        if (n % i == 0) return divs(n, i - 1, count + 1);
        else return divs(n, i - 1, count);
    }
}

int binomialCoefficient(int n, int k) {
    if (k == 0 || k == n) return 1; // Базовый случай: C(n,0) или C(n,n) всегда равно 1
    // Рекурсивный вызов для двух вариантов: выбор k-го элемента и не выбор k-го элемента
    else return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

void pascal(int n, int line) {
    if (line >= n) return;  // Завершаем рекурсию
    else {
        // Выводим binomialCoefficient для данной строки и i-го элемента
        for (int i = 0; i < line; i++) cout << binomialCoefficient(line, i) << " ";
        cout << endl;
        pascal(n, line + 1);  // Рекурсивный вызов для следующей строки
    }
}

int fib(int n) {
    if (n <= 1) return n; // Базовый случай: fib(0) = 0, fib(1) = 1
    else return fib(n - 1) + fib(n - 2); // Рекурсивный вызов для fib(n-1) и fib(n-2)
}

int nod(int a, int b) {
    if (b == 0) return a; // Базовый случай: НОД(a, 0) = a
    else return nod(b, a % b); // Рекурсивный вызов с использованием алгоритма Евклида: НОД(a, b) = НОД(b, a % b)
}

int main()
{
    // №1
    // primeFactors(18, 2);

    // №2
    /* string word;
    cin >> word;
    if (isPalindrome(word, 0, word.length() - 1)) cout << "YES" << endl;
    else cout << "NO" << endl; */

    // №3
    // cout << equal(1234, 10, 0);

    // №4
    // cout << divs(18, 18 - 1, 0);

    // №5
    // pascal(8, 0);

    // №6
    // cout << fib(6);

    // №10
    // cout << nod(27, 81);

    return 0;
}