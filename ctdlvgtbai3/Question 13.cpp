#include <iostream> 
using namespace std;

int findGCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return findGCD(b, a % b);
}

int main() {
	cout << findGCD(24,15);
	return 0;
}