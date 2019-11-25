#include "pch.h"
#include "Rectangle.h"


//Point struct
//Constructor/Destructor definition
//Constructor
Point::Point()
{
	x = 0;
	y = 0;

}
Point::Point(double thisX, double thisY)
{
	x = thisX;
	y = thisY;
}
//Destructor
Point::~Point() {}; //default destructor to remove objects after done

//Accessor/mutator definition
//Accessor
double Point::getX() { return x; }
double Point::getY() { return y; }
//Mutator
void Point::setX(double xP) { x = xP; }
void Point::setY(double yP) { y = yP; }

//Rectangle Class
//Constructor/Destructor definition
//Constructor
Rectangle::Rectangle() {};
Rectangle::Rectangle(Point thisPoint1, Point thisPoint3, std::string thisName)
{
	point1 = thisPoint1; 
	point3 = thisPoint3;
	name = thisName;
}
//Destructor
Rectangle::~Rectangle() {}; //Default destructor

Point Rectangle::getP1() { return point1; }
Point Rectangle::getP3() { return point3; }
std::string Rectangle::getName() { return name; }


void Rectangle::setP1(Point p1) { point1 = p1; }
void Rectangle::setP3(Point p3) { point3 = p3; }
void Rectangle::setName(std::string n) { name = n; }

//Function
Point * Rectangle::getCorners(Point point1, Point point3)
{
	// Get 2 points for the top-left and bottom-right of the rectangle
	//point1(x1,y1)
	double x1 = point1.getX();
	double y1 = point1.getY();
	//point2(x2,y2)
	double x2 = point3.getX();
	double y2 = point3.getY();
	//Populate the remaining two point from the set values.
	Point point2 = Point(x1, y2);
	Point point4 = Point(x2, y1);

	//Put the value of all four points in an array
	//*arrayP is a pointer to an array of 4 points type Point
	Point *arrayP = new Point[4]; //remember to delete this in main after calling
	Point temp[4] = { point1, point2, point3, point4 };
	//Assign the value for each position in the arrayP
	for (int i = 0; i < 4; i++)
	{
		arrayP[i] = temp[i];
	}
	return arrayP;
}

//3. Get perimeter
double Rectangle::perimeter()
{
	double s1 = std::abs(point3.getX() - point1.getX());
	// Calculate length by taking absolute value of y2 - y1
	double s2 = std::abs(point3.getY() - point1.getY());
	double perimeter;
	perimeter = (s1 + s2) * 2;
	return perimeter;
}

//4. Get area
double Rectangle::area()
{
	double s1 = std::abs(point3.getX() - point1.getX());
	// Calculate length by taking absolute value of y2 - y1
	double s2 = std::abs(point3.getY() - point1.getY());
	double area;
	area = s1 * s2;
	return area;
}


//Overload operator
//1.Inputhow
std::istream & operator>>(std::istream &input, Rectangle &r)
{
	// Get point 1 and point 2 object
	Point point1 = r.getP1();
	Point point3 = r.getP3();
	// Input x1,y1,x2,y2
	std::cout << "Please name your rectangle: ";
	input >> r.name; 
	std::cout << "Please enter the bottom-left(x1,y1) and top-right(x2,y2) points of " << r.name << std::endl;
	std::cout << "Enter x1: ";
	input >> point1.x;
	std::cout << "Enter y1: ";
	input >> point1.y;
	std::cout << "Enter x2: ";
	input >> point3.x;
	std::cout << "Enter y2: ";
	input >> point3.y;

	//Check if input is correct
	while (point1.x > point3.x || point1.y > point3.y)
	{
		std::cout << "Invalid input. The (x1,y1) has to be smaller than (x2,y2). Re-enter your point: " << std::endl;
		std::cout << "Enter x1: ";
		input >> point1.x;
		std::cout << "Enter y1: ";
		input >> point1.y;
		std::cout << "Enter x2: ";
		input >> point3.x;
		std::cout << "Enter y2: ";
		input >> point3.y;
	}

	// Set new point1 and point2
	r.setP1(point1);
	r.setP3(point3);
	//r.setName(name) no need 
	return input;
}

//2.Output

// output operator
std::ostream& operator << (std::ostream& output, Rectangle &rectangle)
{
	// Get point object from Rectangle Class
	Point point1 = rectangle.getP1();
	Point point3 = rectangle.getP3();
	//std::string name = rectangle.getName();

	   // Get array which contains all 4 corners
	Point * arrayPoint = rectangle.getCorners(point1, point3);

	// Loop through object and print out each corner
	output << rectangle.getName() << "'s four corners are at ";
	for (int i = 0; i < 4; i++)
	{
		output << "(" << arrayPoint[i].getX() << ", " << arrayPoint[i].getY() << ")";
		// If index is not index of last element, then add comma
		if (i != 3)
		{
			output << ", ";
		}
	}
	output << "\n";
	//output << getSides(rectangle.getP1(),rectangle.getP1(),side1,side2);
	output << rectangle.getName() << "'s area is " << rectangle.area() << " and perimeter is " << rectangle.perimeter() << std::endl;
	return output;
}

//3.Add
Rectangle Rectangle::operator+ (Rectangle &obj1)
{
	// Declare new Rectangle Object
	Rectangle newRectangle;
	// Get Point1 and Point2 of obj1
	Point objPoint1 = obj1.getP1();
	Point objPoint2 = obj1.getP3();

	// Determine the new set of (x1,y1), (x2,y2) for the new rectangle
	int newX1, newX2, newY1, newY2;
	if (point1.getX() < objPoint1.getX())
	{
		newX1 = point1.getX();
	}
	else
	{
		newX1 = objPoint1.getX();
	}
	if (point1.getY() < objPoint1.getY())
		newY1 = point1.getY();
	else
		newY1 = objPoint1.getY();

	Point newPoint1 = Point(newX1, newY1);
	newRectangle.setP1(newPoint1);

	if (point3.getX() < objPoint2.getX())
		newX2 = objPoint2.getX();
	else
		newX2 = point3.getX();
	if (point3.getY() < objPoint2.getY())
		newY2 = objPoint2.getY();
	else
		newY2 = point3.getY();

	Point newPoint2 = Point(newX2, newY2);
	newRectangle.setP3(newPoint2);
	return newRectangle;
}

