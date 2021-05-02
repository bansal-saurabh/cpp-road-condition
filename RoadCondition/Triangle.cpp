// File: Triangle.cpp
// Version: V1.0
// Date: 1-01-2019
// Name: Saurabh Bansal
// This program defines constructors and functions for the Triangle class.

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "Triangle.h"

using namespace std;

Triangle::Triangle() : Shape()
{
	size = 0;
}

Triangle::~Triangle()
{
}

Triangle::Triangle(int pSize, const char* pShapeType, const char* pIdentifier, const char* pStatus, int pDate,
	const char* pMonth, int pYear, const char* pTime, int pDx, int pDy, string pSorter)
	: Shape(pShapeType, pIdentifier, pStatus, pDate, pMonth, pYear, pTime, pDx, pDy, pSorter)
{
	size = pSize;
}

void Triangle::display()
{
	Shape::display();
	cout << "Shape Type: " << shapeType << endl;
	cout << "Identifier: " << identifier << endl;
	cout << "Road Status: " << status << endl;
	cout << "Date & Time: " << date << " " << month << " " << year << " " << time << endl;
	cout << "Size: " << size << endl;
	cout << "X Coordinate: " << dx << endl;
	cout << "Y Coordinate: " << dy << endl;
}

void Triangle::draw(const char* status, int size, int dx, int dy)
{
	int drawStart;
	string symbol;

	char filename1[30] = "MyPattern.txt";
	string alert = "alert";
	string ok = "ok";

	int x = dx - 1;
	int y = dy - 1;
	string convertLower = status;
	transform(convertLower.begin(), convertLower.end(), convertLower.begin(), tolower);

	if (!convertLower.compare(alert))
	{
		symbol = "X";
	}
	else if (!convertLower.compare(ok))
	{
		symbol = "O";
	}

	ifstream dataIn2;
	ofstream dataOut2;

	fstream dataFile2;

	dataFile2.open(filename1, ios::in | ios::out | ios::binary);

	string testString;

	int space = size - 1;

	drawStart = (72 * y) + x;

	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= space; j++)
		{
			// cout << " ";
		}

		space--;

		for (int j = 1; j <= 2 * i - 1; j++)
		{
			testString += symbol;
		}

		dataFile2.seekp(drawStart, ios::beg);

		dataFile2.write(testString.c_str(), 2 * i - 1);

		testString.clear();

		drawStart = drawStart + 71;
	}

	dataFile2.close();

}

int Triangle::getSize()
{
	return size;
}
