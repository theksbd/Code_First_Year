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
		 * TODO: set zero center's x-y and radius
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

	Circle(const Circle& circle)
	{
		/*
		 * STUDENT ANSWER
		 */
		this->center.setX(circle.center.getX());
		this->center.setY(circle.center.getY());
		this->radius = circle.radius;
	}

	void setCenter(Point point)
	{
		/*
		 * STUDENT ANSWER
		 */
		this->center.setX(point.getX());
		this->center.setY(point.getY());
	}

	void setRadius(double radius)
	{
		/*
		 * STUDENT ANSWER
		 */
		this->radius = radius;
	}

	Point getCenter() const
	{
		/*
		 * STUDENT ANSWER
		 */
		return center;
	}

	double getRadius() const
	{
		/*
		 * STUDENT ANSWER
		 */
		return radius;
	}

	void printCircle()
	{
		printf("Center: {%.2f, %.2f} and Radius %.2f\n", this->center.getX(), this->center.getY(), this->radius);
	}
};

int main() {
	Point a(2,0);
	Circle c(const Circle& a);
	Circle b(c,3);
	b.printCircle();
	return 0;
}