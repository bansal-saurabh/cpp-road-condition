// File: Rectangle.h
// Version: V1.0
// Date: 1-01-2019
// Name: Saurabh Bansal
// This program creates a Rectangle class by extending the Shape class and constructor overloading.
// It also declares additional variables or functions.

#if !defined(RECTANGLE_h_INCLUDED)
#define RECTANGLE_h_INCLUDED
#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle();
	~Rectangle();
	Rectangle(int pHeight, int pWidth, const char* pShapeType, const char* pIdentifier, const char* pStatus,
		int pDate, const char* pMonth, int pYear, const char* pTime, int pDx, int pDy, string pSorter);
	void display();
	void draw(const char* status, int height, int width, int dx, int dy);
	int getWidth();
	int getHeight();

private:
	int width;
	int height;
};
#endif	//#if !defined(RECTANGLE_h_INCLUDED)