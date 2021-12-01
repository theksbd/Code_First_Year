#include <iostream> 
using namespace std;

void printArray(int n)
{
	/*
	 * STUDENT ANSWER
	 */
	//static int a = n;
	if (n == 0)
		cout << 0;
	else {
		printArray(n - 1);
		cout << ", " << n;
	}
}

int main() {
	printArray(11);
	return 0;
}