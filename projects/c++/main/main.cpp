#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    // TODO

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