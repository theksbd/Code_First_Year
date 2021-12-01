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
	}

	void operator=(const Circle& circle)
	{
		/*
		 * STUDENT ANSWER
		 */
		this->center.setX(circle.center.getX());
		this->center.setY(circle.center.getY());
		this->radius = circle.radius;
	}

	bool operator==(const Circle& circle)
	{
		/*
		 * STUDENT ANSWER
		 */
		if (this->center.getX() == circle.center.getX() && this->center.getY() == circle.center.getY() && this->radius == circle.radius)
			return 1;
		else return 0;
	}

	friend istream& operator >> (istream& in, Circle& circle)
	{
		/*
		 * STUDENT ANSWER
		 */
		double x, y;
		in >> x >> y;
		in >> circle.radius;
		circle.center = Point(x, y);
		return in;
	}

	void printCircle()
	{
		printf("Center: {%.2f, %.2f} and Radius %.2f\n", this->center.getX(), this->center.getY(), this->radius);
	}
};

int main() {
	Point a(2, 0), b(1, 0), c(1, 2), o(0,0);
	Circle O,I,J;
	cin >> O >> I;
	if (O == I)
		cout << "Hay" << endl;
	J = O;
	J.printCircle();
	return 0;
}