// File: Shape.h
// Version: V1.0
// Date: 1-01-2019
// Name: Saurabh Bansal
// This program creates a Shape class and declares variables, constructors and functions prototypes.

#if !defined(SHAPE_h_INCLUDED)
#define SHAPE_h_INCLUDED
#include<string>

using namespace std;

class Shape
{
public:
	Shape();
	virtual ~Shape();
	Shape(const char* pShapeType, const char* pIdentifier, const char* pStatus, int pDate, const char* pMonth,
		int pYear, const char* pTime, int pDx, int pDy, string pSorter);

	virtual void display();
	virtual void draw(const char* status, int size, int dx, int dy);
	virtual void draw(const char* status, int height, int width, int dx, int dy);

	char* getShapeType();
	char* getIdentifier();
	char* getStatus();
	char* getMonth();
	char* getTime();

	int getDate();
	int getYear();
	int getDx();
	int getDy();

	string getSorter();

	virtual int getSize();
	virtual int getWidth();
	virtual int getHeight();

protected:
	char* shapeType;
	char* identifier;
	char* status;
	char* month;
	char* time;

	int date;
	int year;
	int dx;
	int dy;

	string sorter;
};
#endif	//#if !defined(SHAPE_h_INCLUDED)