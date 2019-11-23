#include "pch.h"
#include "Rectangle.h"


// Point class
// Default constructor for initialzing 
Point::Point() {
	x = 0; 
	y = 0;
}; 

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
std::ostream& operator << (std::ostream& output, Rectangle &rectangle) {
	// Get point object from Rectangle Class 
	Point point1 = rectangle.getPoint1(); 
	Point point2 = rectangle.getPoint2();
	// Get array which contains all 4 corners
	Point * arrayPoint = rectangle.setAllPoint(point1, point2); 

	// Loop through object and print out each corner
	output << "Rect1's four corners are at ( "; 
	for (int i = 0; i < 4; i++) {
		output << "(" << arrayPoint[i].getX() << ", " << arrayPoint[i].getY() << ")";
		// If index is not index of last element, then add comma
		if (i != 3) {
			output << ", ";
		}
	}
	output << " ) \n";
	output << "Rect1's area is " << rectangle.area() << " and perimeter is " << rectangle.perimeter()
		<< std::endl;
	return output;
}

// input operator
std::istream & operator>>(std::istream &input, Rectangle &r){
	// Get point 1 and point 2 object
	Point point1 = r.getPoint1(); 
	Point point2 = r.getPoint2();

	// Input x1,y1,x2,y2
	std::cout << "Enter x1: "; 
	input >> point1.x;
	std::cout << "Enter y1: "; 
	input >> point1.y; 
	std::cout << "Enter x2: ";
	input >> point2.x;
	std::cout << "Enter y2: ";
	input >> point2.y;

	// Set new point1 and point2 
	r.setPoint1(point1); 
	r.setPoint2(point2);
	return input;
}



// Addition overload 
// it will add point 1 and 2 of both rectangle 
// and return new rectangle
Rectangle Rectangle::operator+(Rectangle obj) {
	// Declare new Rectangle Object 
	Rectangle newRectangle; 
	// Get Point1 of obj 
	Point objPoint1 = obj.getPoint1();

	// Get Point 2 of obj 
	Point objPoint2 = obj.getPoint2();

	// Add 2 point1 of rectangle and obj together
	Point newPoint1 = Point(point1.getX() + objPoint1.getX(), point1.getY() + objPoint1.getY()); 
	newRectangle.setPoint1(newPoint1); 

	// Add 2 point2 of rectangle and obj together
	Point newPoint2 = Point(point2.getX() + objPoint2.getX(), point2.getY() + objPoint2.getY());
	newRectangle.setPoint2(newPoint2);

	// Return new rectangle
	return newRectangle; 
}

// Subtraction overload
// If 2 rectangle overlap, it will subtract point 1 and 2 
// of 2 rectangle and return new rectangle with 2 new points 
// otherwise, it will return 0
Rectangle operator-(Rectangle obj1, Rectangle obj2)
{
	// Declare new rectangle 
	Rectangle newRectangle; 

	// Initialzie 2 new point 1 and 2 for new rectangle
	Point newPoint1, newPoint2; 

	// Checking if 2 rectangle overlaps by calling function isOverLap
	// it will return false if no overlap, otherwise return true 
	bool checkingOverLap = isOverLap(obj1, obj2); 
	
	// if it's false, point 1 and 2 of rectangle would be (0,0); 
	if (checkingOverLap == false) {
		newPoint1 = Point(0, 0); 
		newPoint2 = Point(0, 0);
		newRectangle = Rectangle(newPoint1, newPoint2);
	}
	else {
		// get point 1 and point 2 of obj1
		Point point1 = obj1.getPoint1();
		Point point2 = obj1.getPoint2();

		// get point 1 and point 2 of obj2
		Point otherPoint1 = obj2.getPoint1();
		Point otherPoint2 = obj2.getPoint2();

		// Subtract coordinator of point1 of  obj1 and obj2
		newPoint1 = Point(point1.getX() - otherPoint1.getX(), point1.getY() - otherPoint1.getY());
		newRectangle.setPoint1(newPoint1);

		// Subtract coordinator of point2 of  obj1 and obj2
		newPoint2 = Point(point2.getX() - otherPoint2.getX(), point2.getY() - otherPoint2.getY());
		newRectangle.setPoint1(newPoint2);
	}

	return newRectangle;
}

// Function to check overlab rectangle 
// Returns true if two rectangles (point1, point2) and (otherPoint1, otherPoint2) overlap
bool isOverLap(Rectangle rectangle1, Rectangle rectangle2) {
	
	// get point 1 and point 2 of rectangle1 
	Point l1 = rectangle1.getPoint1();
	Point r1 = rectangle1.getPoint2();

	// get point 1 and point 2 of rectangle2
	Point l2 = rectangle2.getPoint1();
	Point r2 = rectangle2.getPoint2();

	// If one rectangle is on left side of other 
	if (l1.getX() > r2.getX() || l2.getX() > r2.getX())
		return false;
	//If one rectangle is above other 
	if (l1.getY() < r2.getY() || l2.getY() < r2.getY())
		return false; 
	// default return true 
	return true;
}

