#include "pch.h"
#include "Rectangle.h"


// Point class
// Default constructor for initialzing 
Point::Point() {}; 

// Constructor for taking parameter 
Point::Point(int thisX, int thisY) {
	x = thisX; 
	y = thisY; 
}

// Destructor 
Point::~Point() {}; 

// Point Accessor
// return x value
int Point::getX() { return x; }

// return y value 
int Point::getY() { return y; }

// Point Mutator
// set x value 
void Point::setX(int xParameter) { 
	x = xParameter; 
}

// set y value 
void Point::setY(int yParameter) { 
	y = yParameter;  
}

// Rectangle Class 
// Default constructor for initializing 
Rectangle::Rectangle() {}; 

// Constructor for taking parameter
// it takes object Point as parameter
Rectangle::Rectangle(Point thisPoint1, Point thisPoint2) {
	point1 = thisPoint1; 
	point2 = thisPoint2; 
}

// Destructor -- it will delete arrayPoint object 
Rectangle::~Rectangle() {};

// Rectangle Accessor
// get point 1 (x1, y1), it will return point object 
Point Rectangle::getPoint1() {
	return point1; 
}
// get point 2 (x2, y2), it will return point object
Point Rectangle::getPoint2() {
	return point2;
}

// Rectangle Mutator 
// set point 1
void Rectangle::setPoint1(Point thisPoint1) {
	point1 = thisPoint1; 
}

// set point 2 
void Rectangle::setPoint2(Point thisPoint2) {
	point2 = thisPoint2; 
}

// Fucntion to set up 4 point of rectangle 
// it will return array Point object 
Point * Rectangle::setAllPoint(Point point1, Point point2) {  

	// get all x,y point 
	// get x1,y1
	int x1 = point1.getX(); 
	int y1 = point1.getY(); 

	// get x2,y2
	int x2 = point2.getX(); 
	int y2 = point2.getY(); 

	// Get Point 3 and 4 
	Point point3 = Point(x2, y1); 
	Point point4 = Point(x1, y2);

	// initialize array of point which will cointaint 
	// 4 point of rectangle
	int count = 0; 
	Point *arrayPoint = new Point[4]; 
	for (Point i : { point1, point2, point3, point4 }) {
		arrayPoint[count] = i;
		count++;
	} 
	return arrayPoint; 
}

// Function to calculate parameter of triangle
int Rectangle::perimeter() {
	// Caculate width by taking absolute value of x2 - x1 
	int rectangleWidth = std::abs(point2.getX() - point1.getX()); 
	// Calculate length by taking absolute value of y2 - y1
	int rectangleLength = std::abs(point2.getY() - point1.getY());
	// Calculate perimeter by taking (width + length) * 2
	int perimeter = (rectangleWidth + rectangleLength) * 2;
	return perimeter;
}

// Function to calculate area of rectangle
int Rectangle::area() {
	// Caculate width by taking absolute value of x2 - x1 
	int rectangleWidth = std::abs(point2.getX() - point1.getX());
	// Calculate length by taking absolute value of y2 - y1
	int rectangleLength = std::abs(point2.getY() - point1.getY());
	// Calculate perimeter by taking (width + length) * 2
	int area = rectangleWidth * rectangleLength;
	return area;
}

// output operator 
std::ostream& operator << (std::ostream& output, Rectangle rectangle) {
	// Get point object from Rectangle Class 
	Point point1 = rectangle.getPoint1(); 
	Point point2 = rectangle.getPoint2();
	// Get array which contains all 4 corners
	Point * arrayPoint = rectangle.setAllPoint(point1, point2); 

	// Loop through object and print out each corner
	output << "Rect1's four corners are at ( "; 
	for (int i = 0; i < 4; i++) {
		output << "(" << arrayPoint[i].getX() << ", " << arrayPoint[i].getY() << ")";
		// If index less than last element, then add comma
		if (i != 3) {
			output << ", ";
		}
	}
	output << " ) \n";
	output << "Rect1's area is " << rectangle.area() << " and perimeter is " << rectangle.perimeter(); 
	return output;
}