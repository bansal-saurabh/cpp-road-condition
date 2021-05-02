// File: Triangle.h
// Version: V1.0
// Date: 1-01-2019
// Name: Saurabh Bansal
// This program creates a Triangle class by extending the Shape class and constructor overloading.
// It also declares additional variables or functions.

#if !defined(TRIANGLE_h_INCLUDED)
#define TRIANGLE_h_INCLUDED
#include "Shape.h"

class Triangle : public Shape
{
public:
	Triangle();
	~Triangle();
	Triangle(int pSize, const char* pShapeType, const char* pIdentifier, const char* pStatus, int pDate,
		const char* pMonth, int pYear, const char* pTime, int pDx, int pDy, string pSorter);
	void display();
	void draw(const char* status, int size, int dx, int dy);
	int getSize();

private:
	int size;
};
#endif	//#if !defined(TRIANGLE_h_INCLUDED)