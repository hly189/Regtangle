// Regtangle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "Rectangle.h"

int main()
{
	Rectangle rectangle1, rectangle2;
	// Input and output for rectangle 1
	std::cin >> rectangle1;
	std::cout << rectangle1;
	std::cout << std::endl;

	//Input and output rectangle 2
	std::cin >> rectangle2;
	std::cout << rectangle2;
	std::cout << std::endl;

	std::cout << "Programmed by Thanh Le\n";
	return 0;
}