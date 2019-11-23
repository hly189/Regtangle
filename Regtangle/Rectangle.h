#ifndef Rectangle_h
#define Rectangle_h
#include <iostream>

// Small class to store point (x, y)
struct Point {
	// initialize x and y
	int x, y; 
		
	// Default constructor for initialzing 
	Point(); 
		
	// Constructor to take parameter
	Point(int thisX, int thisY); 

	// Destructor 
	~Point(); 

	// Accessor 
	// return x value 
	int getX(); 

	// return y value
	int getY(); 

	// Mutator 
	// set x value
	void setX(int x); 

	// set y value
	void setY(int y); 
};


// Define class rectangle
class Rectangle {
private:
	// initialize varibale for 2 point 
	Point point1, point2; 
	
public: 
	// Initialize constructor 
	Rectangle(); 

	// Constructor with parameter 
	Rectangle(Point thisPoint1, Point thisPoint2); 

	// Destructor 
	~Rectangle(); 

	// Accessor
	// Get point 1 
	Point getPoint1();

	// Get point 2
	Point getPoint2(); 

	// Mutator 
	// set point 1 
	void setPoint1(Point point1); 
	
	// set Point 2
	void setPoint2(Point point2);

	// Overload operator
	
	// output operator 
	friend std::ostream& operator << (std::ostream& output, Rectangle &R);

	// input operator 
	friend std::istream& operator >> (std::istream& output, Rectangle &r);

	// Addition operator +
	Rectangle operator + (Rectangle obj);

	// Substraction operator - 
	friend Rectangle operator - (Rectangle obj1, Rectangle obj2); 

	// Function to check overlab rectangle 
	friend bool isOverLap(Rectangle rectangle1, Rectangle rectangle2);

	// Function to set up all 4 point of rectangle 
	Point* setAllPoint(Point point1, Point point2); 

	// Function to calculate perimeter of rectangle
	int perimeter();

	// Function to calculate area of rectangle
	int area();
};


#endif