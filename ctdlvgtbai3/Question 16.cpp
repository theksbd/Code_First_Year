#include <iostream>
using namespace std;

void printPattern(int n)
{
	/*
	 * STUDENT ANSWER
	 */
	//static int a = n;
	////cout << n;
	//if (n == a)
	//	cout << ", " << n;
	//else if (n <= 0) {
	//	cout << ", " << n;
	//}
	//else printPattern(n - 5);
	//
	//printPattern(n + 5);
	//static int a = 0;
	//static int t = n;
	//if (n <= 0) {
	//	cout << ", " << n;
	//	a++;
	//}
	//if (a == 0) {
	//	cout << n;
	//	a++;
	//	printPattern(n - 5);
	//}
	////printPattern(n - 5);
	//if (a > 0) {
	//	printPattern(n - 5);
	//	cout << ", " << n;
	//}
	static int a = 0;
	static int t = n;
	if (n > 0) {
		if (a == 0) {
		cout << n;
		a++;
		printPattern(n - 5);
	}
		else if (a == 1) {
			/*if (n == t)
				cout << ", " << n;*/
			//else {
				cout << " " << n;
				printPattern(n - 5);
			//}
		}
		else {
			if (n == t)
				cout << " " << n;
			else {
				cout << " " << n;
				printPattern(n + 5);
			}
		}
	}
	else {
		cout << " " << n;
		a++;
		printPattern(n + 5);	
	}
}

int main() {
	printPattern(14);
	return 0;
}