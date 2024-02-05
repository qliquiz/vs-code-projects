#include "geometry.h"

#ifndef _FILE_H
#define _FILE_H
int countPoints(const char* fileName);
bool readPoints(const char* fileName, Point* pointArray, int maxPointNum);
bool writeTriangles(const char* fileName, Triangle* trArray, int trNum);
#endif 