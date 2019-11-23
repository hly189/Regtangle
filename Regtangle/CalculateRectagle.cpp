// Regtangle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "Rectangle.h"

int main()
{
	std::string answer; 
	do {
		Rectangle rectangle1, rectangle2, rectanle3, rectangle4; 
		// Input and output for rectangle 1 
		std::cout << "Infor for fitst rectangle: " << std::endl; 
		std::cin >> rectangle1; 
		std::cout << rectangle1; 
		std::cout << std::endl; 
		
		//Input and output rectangle 2
		std::cout << "Infor for second rectangle: " << std::endl;
		std::cin >> rectangle2;
		std::cout << rectangle2;
		std::cout << std::endl;
		
		// Addiition both rectangle 1 and 2. Then output 
		rectanle3 = rectangle1 + rectangle2; 
		std::cout << rectanle3; 
		std::cout << std::endl;

		// Subtraction both rectangle 1 and 2. Then output 
		rectangle4 = rectangle2 - rectangle1;
		std::cout << rectangle4;
		std::cout << std::endl;
		std::cin.ignore(); 

		// Asking user to continue or not
		std::cout << "Do you want to continue (y/n): "; 
		getline(std::cin, answer); 
	} while (answer != "n"); 

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
