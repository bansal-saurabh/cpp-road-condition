// File: RCDataManager.cpp
// Version: V1.0
// Date: 1-01-2019
// Name: Saurabh Bansal
// This program defines constructors and functions for the Link and List class.

#include "RCDataManager.h"
#include "Shape.h"

#include <iostream>
#include <conio.h>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

Link::Link(Shape* pshape)
{
	shape = pshape;
	Next = 0;
}

List::List()
{
	// 'head' points to 0 initially and when the list is empty.  
	// Otherwise 'head' points to most recently added object
	head = 0;
}

int List::add(Shape* shape)
{
	// pointer 'temp' used to instantiate objects to add to list 
	Link* temp;
	// memory allocated and the object is given a value
	temp = new Link(shape);
	if (temp == 0)
	{
		return 0;  // shows error in memory allocation
	}
	// the pointer in the object is set to whatever 'head' is currently pointing at
	temp->Next = head;
	// 'head' is re-directed to point to the last created object
	head = temp;

	return 1;
}

void List::display()
{
	cout << endl << "Displaying road condition objects:" << endl;
	// pointer 'temp' used to iterate through the list 
	Link* temp;
	// 'head' points to last object.  The rest can only be located 
	// by pointers inside other objects. Now iterate back through 
	// the linked list until reach the last pointer (which is 0)
	for (temp = head; temp != 0; temp = temp->Next)
	{
		temp->shape->display();
	}

	cout << endl << "Press any key to return to the main menu..." << endl;
	_getch();
}

void List::draw()
{
	int notCounted = 0;
	char filename1[30] = "MyPattern.txt";

	ofstream dataOut1;
	dataOut1.open(filename1);

	string blankString;

	for (int i = 0; i < 110; i++)
	{
		for (int j = 0; j < 70; j++)
		{
			blankString += " ";
		}

		blankString += "\n";
	}

	dataOut1 << blankString;

	dataOut1.close();

	cout << endl << "Drawing complete road objects:" << endl;

	Link* temp;

	for (temp = head; temp != 0; temp = temp->Next)
	{
		int drawSize = temp->shape->getSize();

		int dx = temp->shape->getDx();
		int dy = temp->shape->getDy();

		if (drawSize != 0)
		{
			if (dx >= drawSize)
			{
				temp->shape->draw(temp->shape->getStatus(), drawSize, dx, dy);
			}
			else
			{
				notCounted++;
			}
		}
		else
		{
			int height = temp->shape->getHeight();
			int width = temp->shape->getWidth();
			temp->shape->draw(temp->shape->getStatus(), height, width, dx, dy);
		}
	}

	ifstream dataIn;
	char textLine[128];

	dataIn.open(filename1);

	// Read ahead
	dataIn.getline(textLine, sizeof(textLine) - 1, '\n');
	// USE

	while (!dataIn.eof())
	{// Process the whole file
		cout << textLine << endl;
		dataIn.getline(textLine,
			sizeof(textLine) - 1, '\n');
	}
	cout << textLine;

	if (notCounted != 0)
	{
		cout << notCounted++ << " object(s) not displayed due to x-coordinate smaller than the size!" << endl;
	}
	// Close access to the files
	dataIn.close();  // CLOSE

	cout << endl << "Press any key to return to the main menu..." << endl;
	_getch();
}

void List::write(char* fileName)
{
	ofstream dataOut;
	dataOut.open(fileName);

	dataOut << "Name Identifier Alert/OK Date Time Size Width (1-5) Size Height (1-5) Grid position across x (1-60) Grid position down y (1-100)" << endl;

	Link* temp;
	for (temp = head; temp != 0; temp = temp->Next)
	{
		if (temp->shape->getWidth() != 0) {

			dataOut << temp->shape->getShapeType() << " " << temp->shape->getIdentifier() << " " << temp->shape->getStatus()
				<< " " << temp->shape->getDate() << " " << temp->shape->getMonth() << " " << temp->shape->getYear()
				<< " " << temp->shape->getTime() << " " << temp->shape->getHeight() << " " << temp->shape->getWidth()
				<< " " << temp->shape->getDx() << " " << temp->shape->getDy() << endl;

		}
		else {
			dataOut << temp->shape->getShapeType() << " " << temp->shape->getIdentifier() << " " << temp->shape->getStatus()
				<< " " << temp->shape->getDate() << " " << temp->shape->getMonth() << " " << temp->shape->getYear()
				<< " " << temp->shape->getTime() << " " << temp->shape->getSize()
				<< " " << temp->shape->getDx() << " " << temp->shape->getDy() << endl;
		}
	}

	dataOut.close();
	cout << "File saved successfully!" << endl;

	cout << endl << "Press any key to return to the main menu..." << endl;
	_getch();
}

int List::remove_first()
{
	Link* temp;
	// Link* curent;

	if (head == 0)		// check for empty list 
	{
		return 0;
	}

	temp = head;		// point to one to remove (i.e. first)
	head = head->Next;	// point head second object
	delete temp;		// free the memory
	cout << endl << "Road condition object deleted from top of the linked list." << endl;

	cout << endl << "Press any key to return to the main menu..." << endl;
	_getch();

	return 1;
}

void List::linear_search(string sorted)
{
	int count = 0;
	Link* temp;

	for (temp = head; temp != 0; temp = temp->Next)
	{
		if (sorted.compare(temp->shape->getSorter()) == 0)
		{
			cout << endl << "Road object found with following attributes: " << endl;
			temp->shape->display();
			count++;
		}
	}

	if (!count)
	{
		cout << endl << "No matching road objects found!" << endl;
	}
}

Link* List::middleNode(Link* startNode, Link* endNode)
{
	if (startNode == NULL)
	{
		//  If the linked list is empty 
		return NULL;
	}

	if (startNode == endNode)
	{
		//  If the start node is equal to the end node
		return NULL;
	}

	Link* slowPtr = startNode;
	Link* fastPtr = startNode->Next;

	while (fastPtr != endNode)
	{
		fastPtr = fastPtr->Next;
		if (fastPtr != endNode)
		{
			slowPtr = slowPtr->Next;
			fastPtr = fastPtr->Next;
		}
	}
	return slowPtr;
	// At the end, the slowPtr will be pointing to the middle node
}

void List::binary_search(string sorted)
{

	int count = 0;

	Link* startNode = head;
	Link* endNode = NULL;

	do
	{
		Link* middle = middleNode(startNode, endNode);
		if (middle == NULL)
		{
			// Searched Element Not Present 
			// return NULL;
		}

		if (sorted.compare(middle->shape->getSorter()) == 0)
		{
			cout << endl << "Road object found with following attributes: " << endl;
			middle->shape->display();
			count++;
			break;
		}
		else if (stoll(middle->shape->getSorter()) < stoll(sorted))
		{
			// Search in upper half 
			startNode = middle->Next;
		}
		else
		{
			// Search in lower half 
			endNode = middle;
		}
	} while (endNode == NULL ||
		endNode->Next != startNode);

	if (!count)
	{
		cout << endl << "No matching road objects found!" << endl;
	}
	// data not present 
	// return NULL;
}

void List::sort()
{
	long long fullDateInt;
	long long fullDateIntNext;

	Link* temp = head;
	int counter = 0;

	while (temp)
	{
		temp = temp->Next;
		counter++;
	}

	for (int i = 0; i < counter; i++)
	{
		for (temp = head; temp != 0; temp = temp->Next)
		{
			if (temp->Next)
			{
				fullDateInt = stoll(temp->shape->getSorter());
				fullDateIntNext = stoll(temp->Next->shape->getSorter());

				if (fullDateInt > fullDateIntNext)
				{
					swap(temp->shape, temp->Next->shape);
				}
			}
		}
	}

	cout << endl << "Linked list sorted successfully." << endl;
}

void List::clear()
{
	// CODE FOR CLEAR FUNCTION
	Link* temp;

	while (head != 0)
	{
		temp = head;
		head = head->Next;
		delete temp;
	}

	cout << endl << "Linked list deleted. Program exiting!" << endl;
}

List::~List()
{
	// CODE FOR DESTRUCTOR
	clear();
}
