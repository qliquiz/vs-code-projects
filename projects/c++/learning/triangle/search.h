#include "geometry.h"

#ifndef _SEARCH_H
#define _SEARCH_H
void findAndInsert(Triangle* trArray, int length, const Triangle& triangle);
void searchLargestTriangles(const Point* pointArray, int pointNum, Triangle* trArray, int maxTrNum);
void clearPoint(Point& p);
void clearTriangle(Triangle& tr);
#endif