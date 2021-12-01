#include <iostream>
#include <math.h>
using namespace std;

class Point
{
	/*
	 * STUDENT ANSWER
	 * TODO: using code template in previous question
	 */
private:
	double x, y;

public:
	Point()
	{
		/*
		 * STUDENT ANSWER
		 * TODO: set zero x-y coordinate
		 */
		x = 0;
		y = 0;
	}

	Point(double x, double y)
	{
		/*
		 * STUDENT ANSWER
		 */
		this->x = x;
		this->y = y;
	}

	void setX(double x)
	{
		/*
		 * STUDENT ANSWER
		 */
		this->x = x;
	}

	void setY(double y)
	{
		/*
		 * STUDENT ANSWER
		 */
		this->y = y;
	}

	double getX() const
	{
		/*
		 * STUDENT ANSWER
		 */
		return x;
	}

	double getY() const
	{
		/*
		 * STUDENT ANSWER
		 */
		return y;
	}

	double distanceToPoint(const Point& pointA)
	{
		/*
		 * STUDENT ANSWER
		 * TODO: calculate the distance from this point to point A in the coordinate plane
		 */
		double x1 = pointA.x - this->x;
		double y1 = pointA.y - this->y;
		double d = sqrt(pow(x1, 2) + pow(y1, 2));
		return d;
	}
};

class Circle
{
private:
	Point center;
	double radius;

public:
	Circle()
	{
		/*
		 * STUDENT ANSWER
		 */
		center.setX(0);
		center.setY(0);
		radius = 0;
	}

	Circle(Point center, double radius)
	{
		/*
		 * STUDENT ANSWER
		 */
		this->center.setX(center.getX());
		this->center.setY(center.getY());
		this->radius = radius;
	}

	bool containsPoint(const Point point)
	{
		/*
		 * STUDENT ANSWER
		 * TODO: check if a given point is entirely within the circle (does not count if the point lies on the circle).
				 If contain, return true.
		 */
		if (center.distanceToPoint(point) < radius)
			return true;
		else return false;
	}

	bool containsTriangle(const Point pointA, const Point pointB, const Point pointC)
	{
		/*
		 * STUDENT ANSWER
		 * TODO: check if a given triangle ABC (A, B, C are not on the same line) is entirely within the circle (does not count if any point of the triangle lies on the circle).
				 If contain, return true.
		 */
		if (center.distanceToPoint(pointA) < radius && center.distanceToPoint(pointB) < radius && center.distanceToPoint(pointC) < radius)
			return true;
		else return false;
	}
};

int main() {
	Point a(1, 0);
	Circle a1(a, 1);
	//Circle b;
	Point b(0.2, 0), c(0.5, 0.1), d(0.5, 0.6);
	cout << a1.containsPoint(b) << '\t' << a1.containsPoint(c) << '\t' << a1.containsPoint(d) << endl;
	cout << a1.containsTriangle(b, c, d);
	return 0;
}