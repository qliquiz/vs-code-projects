#include <iostream>

using namespace std;

void umno(int result[], int& lenght, int mnozh) {
    int ost = 0;

    for (int i = 0; i < lenght; i++) {
        int product = result[i] * mnozh + ost; // Умножаем каждую цифру в результате на множитель и добавляем остаток от предыдущего шага
        result[i] = product % 10; // Записываем только последнюю цифру произведения в результат
        ost = product / 10; // Сохраняем оставшуюся часть произведения для добавления к следующей цифре
    }

    while (ost > 0) {
        result[lenght] = ost % 10; // Добавляем оставшиеся цифры к результату
        ost /= 10;
        lenght++;
    }
}

void fac(int n) {
    int result[1000] = {0}; // Инициализируем массив результата нулями
    result[0] = 1; // Устанавливаем начальное значение результата как 1
    int lenght = 1; // Устанавливаем размер результата

    for (int i = 2; i <= n; i++) umno(result, lenght, i); // Вызываем функцию умножения, чтобы умножить текущий результат на i
    cout << n << "! = "; // Выводим факториал числа n

    for (int i = lenght - 1; i >= 0; i--) cout << result[i]; // Выводим цифры результата в обратном порядке
    cout << endl;
}

int main()
{
    for (int i = 1; i <= 100; i++) fac(i);
    
    return 0;
}