// Regtangle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Rectangle.h"

using namespace std; 

int main()
{
	string outputFileName; 

	// Enter file name: 
	cout << "Please enter your output folder: ";
	cin >>  outputFileName;
	cin.ignore();
	ofstream output(outputFileName);

	Rectangle rectangle1, rectangle2;
	// Input and output for rectangle 1
	cin >> rectangle1;
	cout << rectangle1;
	cout << endl;
	// Output to file info of rectangle 1
	output << rectangle1; 
	output << endl; 

	//Input and output rectangle 2
	cin >> rectangle2;
	cout << rectangle2;
	cout << endl;
	// Output to file info of rectangle 2
	output << rectangle2;
	output << endl;

	//Input and output rectangle 3
	Rectangle rectangle3;
	rectangle3 = rectangle1 + rectangle2;
	rectangle3.setName("name1"); 
	cout << rectangle3;
	cout << endl;
	// Output to file info of rectangle 3
	output << rectangle3;
	output << endl;

	std::cout << "Programmed by Thanh Le\n";
	return 0;
}