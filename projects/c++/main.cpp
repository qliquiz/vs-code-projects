#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    setlocale(LC_ALL, "ru");

    return 0;
}

/* Основные функции и типы при работе с файлами.
<fstream> – подключаемый файл
ifstream – тип «входной файл»
ofstream – тип «выходной файл»
in – имя переменной типа ifstream
in.is_open() – был ли файл открыт
in.fail() – была ли ошибка при последней операции
in.eof() – закончился ли файл */

/* Прототипы функций
void fun(int a, int b); */