#include "file.h"
#include "search.h"
#include <iostream>
#include <locale.h>

// using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");

	if (argc < 3) {
		std::cout << "Запуск: Triangles.exe inf.txt outf.txt" << std::endl;
		return -1;
	}

	const char* inFileName = argv[1]; // Имя входного файла 
	const char* outFileName = argv[2]; // Имя выходного файла 
	int pointNum = countPoints(inFileName);

	if (pointNum < 0) {
		std::cout << "Входной файл не существует" << std::endl;
		return -2;
	} else if (pointNum < 4) {
		std::cout << "Входной файл слишком мал" << std::endl;
		return -3;
	}

	Point* pointArray = new Point[pointNum];
	
	if (!readPoints(inFileName, pointArray, pointNum)) {
		std::cout << "Неизвестная ошибка при вводе точек " << std::endl;
		return -3;
	}

	const int maxTrNum = 3;

	Triangle trArray[maxTrNum];

	searchLargestTriangles(pointArray, pointNum, trArray, maxTrNum);

	if (!writeTriangles(outFileName, trArray, maxTrNum)) {
		std::cout << "Не удалось записать результат" << std::endl;
		return -4;
	}

	std::cout << "Программа успешно завершена" << std::endl;

	delete[] pointArray;

	return 0;
}