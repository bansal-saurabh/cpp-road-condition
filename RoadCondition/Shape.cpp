// File: Shape.cpp
// Version: V1.0
// Date: 1-01-2019
// Name: Saurabh Bansal
// This program defines constructors and functions for the Shape class.

#include <iostream>
#include "Shape.h"

using namespace std;

Shape::Shape()
{
	shapeType = new char[2];
	identifier = new char[2];
	status = new char[2];
	month = new char[2];
	time = new char[2];

	strcpy_s(shapeType, 2, "");
	strcpy_s(identifier, 2, "");
	strcpy_s(status, 2, "");
	strcpy_s(month, 2, "");
	strcpy_s(time, 2, "");

	date = 0;
	year = 0;
	dx = 0;
	dy = 0;

	sorter = "";
}

Shape::~Shape()
{
	if (shapeType != 0)
	{
		delete[] shapeType;
		shapeType = 0;
	}
	if (identifier != 0)
	{
		delete[] identifier;
		identifier = 0;
	}
	if (status != 0)
	{
		delete[] status;
		status = 0;
	}

}

Shape::Shape(const char* pShapeType, const char* pIdentifier, const char* pStatus, int pDate, const char* pMonth,
	int pYear, const char* pTime, int pDx, int pDy, string pSorter)
{
	shapeType = new char[strlen(pShapeType) + 1];
	strcpy_s(shapeType, strlen(pShapeType) + 1, pShapeType);

	identifier = new char[strlen(pIdentifier) + 1];
	strcpy_s(identifier, strlen(pIdentifier) + 1, pIdentifier);

	status = new char[strlen(pStatus) + 1];
	strcpy_s(status, strlen(pStatus) + 1, pStatus);

	month = new char[strlen(pMonth) + 1];
	strcpy_s(month, strlen(pMonth) + 1, pMonth);

	time = new char[strlen(pTime) + 1];
	strcpy_s(time, strlen(pTime) + 1, pTime);

	date = pDate;
	year = pYear;
	dx = pDx;
	dy = pDy;

	sorter = pSorter;
}

void Shape::display()
{
	cout << endl;
}

void Shape::draw(const char* status, int size, int dx, int dy)
{
}

void Shape::draw(const char* status, int height, int width, int dx, int dy)
{
}

char* Shape::getShapeType()
{
	return shapeType;
}

char * Shape::getIdentifier()
{
	return identifier;
}

char * Shape::getStatus()
{
	return status;
}

int Shape::getDate()
{
	return date;
}

char * Shape::getMonth()
{
	return month;
}

int Shape::getYear()
{
	return year;
}

char * Shape::getTime()
{
	return time;
}

int Shape::getDx()
{
	return dx;
}

int Shape::getDy()
{
	return dy;
}

string Shape::getSorter()
{
	return sorter;
}

int Shape::getSize()
{
	return 0;
}

int Shape::getHeight()
{
	return 0;
}

int Shape::getWidth()
{
	return 0;
}
