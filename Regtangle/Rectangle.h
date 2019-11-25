#ifndef Rectangle_h
#define Rectangle_h
#include <iostream>
#include <string>

struct Point
{ //Use struct to have global access
	double x, y;
	Point(); //default constrcutor for initiallization
	Point(double getX, double getY); // Constructor to take parameters
	~Point(); //default destructor to remove objects after done

	//Accessor
	double getX();
	double getY();

	//Mutator
	void setX(double x);
	void setY(double y);
};

class Rectangle
{
private:
	Point point1, point3; //rectangle class has two points: point1, point2 of data type Point
protected: 
	std::string name;
public:
	Rectangle(); // Default constructor
	Rectangle(Point, Point, std::string); // Constructor that takes parameters
	~Rectangle(); //Default destructor

	 //Accessor
	Point getP1();
	Point getP3();
	std::string getName();

	//Mutator
	void setP1(Point point1);
	void setP3(Point point3);
	void setName(std::string);

	//Function
	//1. Get rectangle 4 corners
	Point * getCorners(Point, Point);
	//3. Get perimeter
	double perimeter();
	//4. Get area
	double area();

	//Overload operator
	//1.Input
	friend std::istream & operator>>(std::istream&, Rectangle&);

	//2.Output
	friend std::ostream & operator << (std::ostream&, Rectangle&);

	//3.Add
     Rectangle operator+ (Rectangle&);

	//4. Substraction
	friend Rectangle operator- (Rectangle&, Rectangle&);
};

#endif /* Rectangle_hpp */