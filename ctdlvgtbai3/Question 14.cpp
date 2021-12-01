#include <iostream>
using namespace std;

int findLCM(int, int);

int main() {
	cout << findLCM(1075, 192);
	return 0;
}

int findLCM(int a, int b) {
	static int t = a;
	if (a % t == 0 && a % b == 0)
		return a;
	else
		return findLCM(a + 1, b);
}