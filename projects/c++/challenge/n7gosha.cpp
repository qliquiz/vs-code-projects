#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;


int main() {

    int pointsCount;
    cout << "Enter count of points: ";
    cin >> pointsCount;

    int*** groups = new int**[pointsCount*pointsCount];
    int** points = new int*[pointsCount];
    for(int i = 0; i < pointsCount * pointsCount; i++) {
        groups[i] = new int*[pointsCount];
        for(int k = 0; k < pointsCount; k++) {
            groups[i][k] = new int[4];
            groups[i][k][0] = -1;
        }
    }

    for(int i = 0; i < pointsCount; i++) {
        points[i] = new int[3];
        points[i][0] = i;
        cout << "Enter x and y of " << i << " point: ";
        cin >> points[i][1] >> points[i][2];
    }

    // Вывод точек
    for(int i = 0; i < pointsCount; i++) {
        cout << "Points(" << points[i][0] << ';' << points[i][1] << ';' << points[i][2] << ")" << endl;
    }


    int* currentPoint = new int[3];
    int* workPoint = new int[3];
    double* phi = new double[pointsCount];
    int groupLen;
    int currentGroup = 0;

    for(int i = 0; i < pointsCount; i++) {

        // Высчитываем углы
        for(int j = 0; j < pointsCount; j++) {
            if (points[j][2] < points[i][2] || j == i) {
                phi[j] = -1;
                continue;
            }
            phi[j] = ((points[j][1] - points[i][1]) * 1) / sqrt((points[j][1] - points[i][1])*(points[j][1] - points[i][1])+(points[j][2] - points[i][2])*(points[j][2] - points[i][2]));
        }

        // Находим группы
        for(int j = 0; j < pointsCount; j++) {
            if(phi[j] < 0) continue;

            // Ищем длину группы
            groupLen = 0;
            for(int k = 0; k < pointsCount; k++) {
                if(phi[k] < 0) continue;
                if(phi[k] == phi[j]) groups[currentGroup][k] = points[k];
            }
            if(groupLen < 3) continue;
            // елси длина меньше 3-ёх, то не увелчиваем текущую группу и дальше значения будут перезаписаны
            currentGroup++;
        }
    }

    int j = 0;
    for(int i = 0; i < pointsCount * pointsCount; i++) {
        while(groups[i][j][0] != -1) {
            cout << "Point(" << groups[i][j][0] << ';' << groups[i][j][1] << ';' << groups[i][j][2] << ")" << "  ";
            j++;
        }
        if(groups[i][0][0] != -1) cout << endl;
    }

    return 0;
}