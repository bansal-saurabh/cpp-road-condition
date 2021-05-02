// File: RCDataManager.h
// Version: V1.0
// Date: 1-01-2019
// Name: Saurabh Bansal
// This program creates a Link and List class and declares variables, constructors and functions prototypes.

#if !defined(RCDATAMANAGER_h_INCLUDED)
#define RCDATAMANAGER_h_INCLUDED
#include "Shape.h"

class Link
{
	friend class List;

private:
	Shape* shape;
	Link* Next;

public:
	Link(Shape*);
};

class List
{

private:
	Link* head;

public:
	List();
	int add(Shape* shape);
	void display();
	void draw();
	void write(char* fileName);
	int remove_first();
	void linear_search(string sorted);
	Link* middleNode(Link* startNode, Link* endNode);
	void binary_search(string sorted);
	void sort();
	void clear();
	~List();

};
#endif	//#if !defined(RCDATAMANAGER_h_INCLUDED)