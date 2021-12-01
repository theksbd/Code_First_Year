#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

using namespace std;

enum Color
{
	red,
	green,
	blue
};
enum Size
{
	small,
	medium,
	big
};

class Toy
{
protected:
	double price;

public:
	Toy(double price)
	{
		this->price = price;
	}

	virtual void printType() = 0;
	friend class ToyBox;
};

class CarToy : public Toy
{
private:
	Color color;

public:
	CarToy(double price, Color color) : Toy(price)
	{
		/*
		 * STUDENT ANSWER
		 */
		this->price = price;
		this->color = color;
	}

	void printType()
	{
		cout << "This is a car toy\n";
	}

	friend class ToyBox;
};

class PuzzleToy : public Toy
{
private:
	Size size;

public:
	PuzzleToy(double price, Size size) : Toy(price)
	{
		/*
		 * STUDENT ANSWER
		 */
		this->price = price;
		this->size = size;
	}

	void printType()
	{
		cout << "This is a puzzle toy\n";
	}

	friend class ToyBox;
};

class ToyBox
{
private:
	Toy* toyBox[5];
	int numberOfItems;

public:
	ToyBox()
	{
		/*
		 * STUDENT ANSWER
		 * TODO: set zero numberOfItems and nullptr toyBox
		 */
		for (int i = 0; i < numberOfItems; i++) {
			toyBox[i] = nullptr;
		}
		numberOfItems = 0;
	}

	int addItem(const CarToy& carToy)
	{
		/*
		 * STUDENT ANSWER
		 * TODO: function add a new Car toy to the box.
				 If successfully added, the function returns the current number of toys in the box.
				 If the box is full, return -1.
		 */
		//int isFull = 1;
		//for (int i = 0; i < 5; i++) {
		//	if (isFull == 5 && toyBox[4] != NULL) {
		//		return -1;
		//	}
		//	else if (toyBox[i] != NULL)
		//		isFull++;
		//	else {
		//		toyBox[i] = new CarToy(carToy.price, carToy.color);
		//		numberOfItems++;
		//		return numberOfItems;
		//		//toyBox[i] -> printType();

		//	}
		//}
		Color a = carToy.color;
		double b = carToy.price;
		if (this->numberOfItems < 5) {
			toyBox[numberOfItems] = new CarToy(b, a);
			return numberOfItems++;
		}
		else return -1;
	}

	int addItem(const PuzzleToy& puzzleToy)
	{
		/*
		 * STUDENT ANSWER
		 * TODO: function add a new Puzzle toy to the box.
				 If successfully added, the function returns the current number of toys in the box.
				 If the box is full, return -1.
		 */
		//int isFull = 1;
		//for (int i = 0; i < 5; i++) {
		//	if (isFull == 5 && toyBox[4] != NULL) {
		//		return -1;
		//	}
		//	else if (toyBox[i] != NULL)
		//		isFull++;
		//	else {
		//		toyBox[i] = new PuzzleToy(puzzleToy.price,puzzleToy.size);
		//		numberOfItems++; 
		//		return numberOfItems;
		//		//toyBox[i]->printType();
		//	}
		//}
		Size a = puzzleToy.size;
		double b = puzzleToy.price;
		if (this->numberOfItems < 5) {
			toyBox[numberOfItems] = new PuzzleToy(b, a);
			return numberOfItems++;
		}
		else return -1;
	}

	void printBox()
	{
		for (int i = 0; i < numberOfItems; i++)
			toyBox[i]->printType();
	}
};

int main() {
	/*CarToy car(20000, red);
	PuzzleToy puzzle(30000, small);
	car.printType();
	puzzle.printType();*/

	CarToy car1(20000, red), car2(15000,red),car3(10000,red),car4(150000,red),car5(12000,red);
	PuzzleToy puzzle(30000, small);
	ToyBox box;
	box.addItem(car1);
	box.addItem(car2);
	box.addItem(car3);
	box.addItem(car4);
	box.addItem(car5);
	box.addItem(puzzle);
	box.printBox();

	/*Toy* toy = new CarToy(30000, red);
	toy->printType();*/

	return 0;
}