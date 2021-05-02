// File: RoadCondition.cpp
// Version: V1.0
// Date: 2-01-2019
// Name: Saurabh Bansal
// This program implements functionality to store and display a set of graphical shape Objects using a Linked List. 
// The shape objects represent the status of the condition of areas of a road surface. 
// The status will be either 'ok or 'alert' i.e. in need of repair.

#include <iostream>
#include <conio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <Time.h>

#include "RCDataManager.h"
#include "Shape.h"
#include "Diamond.h"
#include "Triangle.h"
#include "Rectangle.h"

using namespace std;

void displayMenu();
void loadFile();

Shape * newObject;
void insertObject();

string sorterCreated;
string createSorter(int date, string month, int year, string shapeTime);

clock_t start, finish;
double duration;

char shapeType[15];
char identifier[5];
char status[10];

string fullDate;
string dateSearch;
char timeSearch[15];

int date;
char month[5];
int year;
char shapeTime[15];

int dx;
int dy;
int shapeSize;
int width;
int height;

int addCount = 0;
const int MAXBUFF = 256;
const int MAXPATH = 30;

ifstream dataIn;

int intVar;
char name[15];
char dateshapeTime[15];

char fileName[MAXPATH];
char textLine[MAXBUFF];

List list;

int main()
{
	char choice;

	do
	{
		displayMenu();
		cin >> choice;

		switch (choice)
		{
		case 'Q':
			// Quit
			return 0;

			break;
		case 'I':
			// Insert an object
			insertObject();

			break;
		case 'D':
			// Delete an object
			list.remove_first();

			break;
		case 'C':
			// Contents of the display
			list.display();

			break;
		case 'S':
			// Save to file
			cout << "Enter file name (Format: filename.txt): ";
			cin >> fileName;
			list.write(fileName);

			break;
		case 'L':
			// Load from file
			loadFile();

			break;
		case 'R':
			// Display
			list.draw();

			break;
		case 'N':
			// Linear Search
			cout << endl << "Enter the following to search road object: " << endl;
			cout << "Date (Format: 01 Jan 2019): ";
			cin.ignore();

			getline(cin, dateSearch);
			date = stoi(dateSearch.substr(0, 2));
			strcpy_s(month, dateSearch.substr(3, 3).c_str());
			year = stoi(dateSearch.substr(7, 4));

			cout << "Time (Format: HH:MM:SS): ";
			cin >> timeSearch;
			sorterCreated = createSorter(date, month, year, timeSearch);

			start = clock();
			list.linear_search(sorterCreated);
			finish = clock();
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			cout << endl << "Time taken for linear search: " << duration << " seconds " << endl;
			cout << endl << "Press any key to return to the main menu..." << endl;
			_getch();

			break;
		case 'B':
			// Binary Search
			cout << endl << "Enter the following to search road object: " << endl;
			cout << "Date (Format: 01 Jan 2019): ";
			cin.ignore();
			getline(cin, dateSearch);

			date = stoi(dateSearch.substr(0, 2));
			strcpy_s(month, dateSearch.substr(3, 3).c_str());
			year = stoi(dateSearch.substr(7, 4));

			cout << "Time (Format: HH:MM:SS): ";
			cin >> timeSearch;

			sorterCreated = createSorter(date, month, year, timeSearch);

			start = clock();
			list.binary_search(sorterCreated);
			finish = clock();

			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			cout << endl << "Time taken for binary search: " << duration << " seconds " << endl;
			cout << endl << "Press any key to return to the main menu..." << endl;
			_getch();

			break;
		case 'T':
			// Sort
			start = clock();
			list.sort();
			finish = clock();
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			cout << endl << "Time taken for sorting: " << duration << " seconds " << endl;
			cout << endl << "Press any key to return to the main menu..." << endl;
			_getch();

			break;
		default:
			break;
		}

	} while (choice != 0);

	cout << endl << endl;

	return 0;
}

void displayMenu()
{
	system("CLS");

	// Display the Menu

	cout << endl << "Main Menu" << endl << endl;

	cout << "Q - Quit" << endl;
	cout << "I - Insert an object" << endl;
	cout << "D - Delete an object" << endl;
	cout << "C - Contents of the display" << endl;
	cout << "S - Save to file" << endl;
	cout << "L - Load from file" << endl;
	cout << "R - Display" << endl;
	cout << "N - Linear Search" << endl;
	cout << "B - Binary Search" << endl;
	cout << "T - Sort" << endl << endl;

	cout << "Enter choice: ";
}

void loadFile()
{
	string nshapeTime;

	cout << "Enter file name to load road condition objects (Format: filename.txt): ";
	cin >> fileName;

	dataIn.open(fileName);

	cout << endl;

	dataIn.getline(textLine, sizeof(textLine), '\n');

	while (!dataIn.eof())
	{
		dataIn >> textLine;
		strcpy_s(shapeType, strlen(textLine) + 1, textLine);

		dataIn >> textLine;
		strcpy_s(identifier, strlen(textLine) + 1, textLine);

		dataIn >> textLine;
		strcpy_s(status, strlen(textLine) + 1, textLine);

		dataIn >> intVar;
		date = intVar;

		dataIn >> textLine;
		strcpy_s(month, strlen(textLine) + 1, textLine);

		dataIn >> intVar;
		year = intVar;

		dataIn >> textLine;
		strcpy_s(shapeTime, strlen(textLine) + 1, textLine);

		if (strlen(shapeType) > 6) {
			sorterCreated = createSorter(date, month, year, shapeTime);
		}

		if (strlen(shapeType) == 9) {
			dataIn >> intVar;
			height = intVar;

			dataIn >> intVar;
			width = intVar;
		}
		else
		{
			dataIn >> intVar;
			shapeSize = intVar;
		}

		dataIn >> intVar;
		dx = intVar;

		dataIn >> intVar;
		dy = intVar;

		if (strlen(shapeType) == 9)
		{
			newObject = new Rectangle(height, width, shapeType, identifier, status, date, month, year, shapeTime, dx, dy, sorterCreated);
			list.add(newObject);
			addCount++;
		}
		else if (strlen(shapeType) == 8)
		{
			newObject = new Triangle(shapeSize, shapeType, identifier, status, date, month, year, shapeTime, dx, dy, sorterCreated);
			list.add(newObject);
			addCount++;
		}
		else if (strlen(shapeType) == 7)
		{
			newObject = new Diamond(shapeSize, shapeType, identifier, status, date, month, year, shapeTime, dx, dy, sorterCreated);
			list.add(newObject);
			addCount++;
		}
	}

	dataIn.close();

	cout << endl << addCount << " road objects(s) inserted into the linked list." << endl;
	addCount = 0;
	cout << endl << "Press any key to return to the main menu..." << endl;
	_getch();
}

void insertObject()
{
	cout << endl << "You have chosen to insert a road object. Enter the following attributes:" << endl << endl;

	cout << "Shape Type (Diamond/Triangle/Rectangle): ";
	cin >> shapeType;

	cout << "Shape Identifier (Di/Tr/Re): ";
	cin >> identifier;

	cout << "Status (Ok/Alert): ";
	cin >> status;

	cout << "Date (Format: 01 Jan 2019): ";
	cin.ignore();
	getline(cin, fullDate);

	date = stoi(fullDate.substr(0, 2));
	strcpy_s(month, fullDate.substr(3, 3).c_str());
	year = stoi(fullDate.substr(7, 4));

	cout << "Time (Format: HH:MM:SS): ";
	cin >> shapeTime;

	sorterCreated = createSorter(date, month, year, shapeTime);

	if (strlen(shapeType) == 9)
	{
		cout << "Enter Height: ";
		cin >> height;
		cout << "Enter Width: ";
		cin >> width;
	}
	else
	{
		cout << "Enter Size (Odd values only): ";
		cin >> shapeSize;
	}

	cout << "Enter X-coordinate (Must be equal or greater than size): ";
	cin >> dx;

	cout << "Enter Y-coordinate: ";
	cin >> dy;

	if (strlen(shapeType) == 9)
	{
		newObject = new Rectangle(height, width, shapeType, identifier, status, date, month, year, shapeTime, dx, dy, sorterCreated);
		list.add(newObject);
		cout << endl << "1 road object inserted into the linked list." << endl;
		cout << endl << "Press any key to return to the main menu..." << endl;
		_getch();
	}
	else if (strlen(shapeType) == 8)
	{
		newObject = new Triangle(shapeSize, shapeType, identifier, status, date, month, year, shapeTime, dx, dy, sorterCreated);
		list.add(newObject);
		cout << endl << "1 road object inserted into the linked list." << endl;
		cout << endl << "Press any key to return to the main menu..." << endl;
		_getch();
	}
	else if (strlen(shapeType) == 7)
	{
		newObject = new Diamond(shapeSize, shapeType, identifier, status, date, month, year, shapeTime, dx, dy, sorterCreated);
		list.add(newObject);
		cout << endl << "1 road object inserted into the linked list." << endl;
		cout << endl << "Press any key to return to the main menu..." << endl;
		_getch();
	}
	else
	{
		cout << endl << "Wrong shape added!" << endl;
	}
}

string createSorter(int date, string month, int year, string shapeTime)
{
	string sDate;
	string sMonth;
	string month2;
	string sYear;
	string sshapeTime;
	string fullDate;
	string hh;
	string mm;
	string ss;

	sDate = to_string(date);
	sMonth = month;
	sYear = to_string(year);
	sshapeTime = shapeTime;

	if (sDate.length() == 1)
	{
		sDate = "0" + sDate;
	}

	hh = shapeTime.substr(0, 2);
	mm = shapeTime.substr(3, 2);
	ss = shapeTime.substr(6, 2);

	transform(month.begin(), month.end(), month.begin(), tolower);

	if (month.compare("jan") == 0)
	{
		month2 = "01";
	}
	else if (month.compare("feb") == 0)
	{
		month2 = "02";
	}
	else if (month.compare("mar") == 0)
	{
		month2 = "03";
	}
	else if (month.compare("apr") == 0)
	{
		month2 = "04";
	}
	else if (month.compare("may") == 0)
	{
		month2 = "05";
	}
	else if (month.compare("jun") == 0)
	{
		month2 = "06";
	}
	else if (month.compare("jul") == 0)
	{
		month2 = "07";
	}
	else if (month.compare("aug") == 0)
	{
		month2 = "08";
	}
	else if (month.compare("sep") == 0)
	{
		month2 = "09";
	}
	else if (month.compare("oct") == 0)
	{
		month2 = "10";
	}
	else if (month.compare("nov") == 0)
	{
		month2 = "11";
	}
	else if (month.compare("dec") == 0)
	{
		month2 = "12";
	}

	fullDate = sYear + month2 + sDate + hh + mm + ss;
	return fullDate;
}