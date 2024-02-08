#include "file.h"
#include "search.h"
#include <iostream>
#include <locale.h>

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");

	if (argc < 3) {
		std::cout << "������: Triangles.exe inf.txt outf.txt" << std::endl;
		return -1;
	}

	const char* inFileName = argv[1]; // ��� �������� ����� 
	const char* outFileName = argv[2]; // ��� ��������� ����� 
	int pointNum = countPoints(inFileName);

	if (pointNum < 0) {
		std::cout << "������� ���� �� ����������" << std::endl;
		return -2;
	} else if (pointNum < 4) {
		std::cout << "������� ���� ������� ���" << std::endl;
		return -3;
	}

	Point* pointArray = new Point[pointNum];
	
	if (!readPoints(inFileName, pointArray, pointNum)) {
		std::cout << "����������� ������ ��� ����� ����� " << std::endl;
		return -3;
	}

	const int maxTrNum = 3;

	Triangle trArray[maxTrNum];

	searchLargestTriangles(pointArray, pointNum, trArray, maxTrNum);

	if (!writeTriangles(outFileName, trArray, maxTrNum)) {
		std::cout << "�� ������� �������� ���������" << std::endl;
		return -4;
	}

	std::cout << "��������� ������� ���������" << std::endl;

	delete[] pointArray;

	return 0;
}