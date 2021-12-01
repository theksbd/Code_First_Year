#include <iostream>
using namespace std;


void printHailstone(int number)
{
	/*
	 * STUDENT ANSWER
	 */
	if (number == 2)
		cout << "2 1";
	else {
		if (number % 2 == 0) {
			cout << number << " ";
			printHailstone(number / 2);
		}
		else {
			cout << number << " ";
			printHailstone(number * 3 + 1);
		}
	}
}


int main() {
	printHailstone(12);
	return 0;
}