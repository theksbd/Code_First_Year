#include <iostream>
using namespace std;

int decimalToBinary(int decimal_number)
{
	/*
	 * STUDENT ANSWER
	 */
	/*static int i = 0;
	i++;
	int a = decimal_number % 2;
	int b = decimal_number / 2;
	if (b == 0) {
		return 0;
	}
	return a * pow(10, i) + decimalToBinary(b);*/
	/*int a = decimal_number % 2;
	static int n = 0;
	static int tong = 0;
	if (decimal_number == 0)
		return tong;
	else {
		n++;
		decimalToBinary(decimal_number / 2);
		tong += a * pow(10, n);
	}*/
	static int tong;
	static int i = -1;
	if (decimal_number > 0) {
		//cout << tong << endl;
		
		i++; 
		//cout << i << endl;
		//tong = (decimal_number % 2) * pow(10, i) + decimalToBinary(decimal_number / 2);
		return (decimal_number % 2) * pow(10, i) + decimalToBinary(decimal_number / 2);
	}
	else {
		//cout << tong << endl;
		return 0;
	}
}

int main() {
	cout << decimalToBinary(257);
	return 0;
}