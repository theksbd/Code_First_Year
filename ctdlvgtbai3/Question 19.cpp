#include <iostream>
#include <string.h>
using namespace std;

int myArrayToInt(char* str, int n)
{
	/*
	 * STUDENT ANSWER
	 */
	
	//Method 1:
	/*static int tong = 0;
	int a;
	if (str[0] == '\0') {
		
		return tong;

	}
	switch (str[0]) {
	case '0':
		a = 0 * pow(10, n - 1);
		tong += a;
		myArrayToInt(str + 1, n - 1);
		break;
	case '1':
		a = 1 * pow(10, n - 1);
		tong += a;
		myArrayToInt(str + 1, n - 1);
		break;
	case '2':
		a = 2 * pow(10, n - 1);
		tong += a;
		myArrayToInt(str + 1, n - 1);
		break;
	case '3':
		a = 3 * pow(10, n - 1);
		tong += a;
		myArrayToInt(str + 1, n - 1);
		break;
	case '4':
		a = 4 * pow(10, n - 1);
		tong += a;
		myArrayToInt(str + 1, n - 1);
		break;
	case '5':
		a = 5 * pow(10, n - 1);
		tong += a;
		myArrayToInt(str + 1, n - 1);
		break;
	case '6':
		a = 6 * pow(10, n - 1);
		tong += a;
		myArrayToInt(str + 1, n - 1);
		break;
	case '7':
		a = 7 * pow(10, n - 1);
		tong += a;
		myArrayToInt(str + 1, n - 1);
		break;
	case '8':
		a = 8 * pow(10, n - 1);
		tong += a;
		myArrayToInt(str + 1, n - 1);
		break;
	case '9':
		a = 9 * pow(10, n - 1);
		tong += a;
		myArrayToInt(str + 1, n - 1);
		break;
	}*/

	//Medthod 2:
	/*if (str[0] == '\0')
		return 0;
	switch (str[0]) {
	case '0':
		return 0 * pow(10, n - 1) + myArrayToInt(str + 1, n - 1);
		break;
	case '1':
		return 1 * pow(10, n - 1) + myArrayToInt(str + 1, n - 1);
		break;
	case '2':
		return 2 * pow(10, n - 1) + myArrayToInt(str + 1, n - 1);
		break;
	case '3':
		return 3 * pow(10, n - 1) + myArrayToInt(str + 1, n - 1);
		break;
	case '4':
		return 4 * pow(10, n - 1) + myArrayToInt(str + 1, n - 1);
		break;
	case '5':
		return 5 * pow(10, n - 1) + myArrayToInt(str + 1, n - 1);
		break;
	case '6':
		return 6 * pow(10, n - 1) + myArrayToInt(str + 1, n - 1);
		break;
	case '7':
		return 7 * pow(10, n - 1) + myArrayToInt(str + 1, n - 1);
		break;
	case '8':
		return 8 * pow(10, n - 1) + myArrayToInt(str + 1, n - 1);
		break;
	case '9':
		return 9 * pow(10, n - 1) + myArrayToInt(str + 1, n - 1);
		break;
	}*/
	if (str[0] == '\0')
		return 0;
	switch (str[0]) {
	case '0':
		myArrayToInt(str + 1, n - 1);
		return 0;
		break;
	case '1':
		myArrayToInt(str + 1, n - 1);
		return 1;
		break;
	case '2':
		myArrayToInt(str + 1, n - 1);
		return 2;
		break;
	case '3':
		myArrayToInt(str + 1, n - 1);
		return 3;
		break;
	case '4':
		myArrayToInt(str + 1, n - 1);
		return 4;
		break;
	case '5':
		myArrayToInt(str + 1, n - 1);
		return 5;
		break;
	case '6':
		myArrayToInt(str + 1, n - 1);
		return 6;
		break;
	case '7':
		myArrayToInt(str + 1, n - 1);
		return 7;
		break;
	case '8':
		myArrayToInt(str + 1, n - 1);
		return 8;
		break;
	case '9':
		myArrayToInt(str + 1, n - 1);
		return 9;
		break;
	}
}


int main() {
	char str[] = "21";
	printf("%d", myArrayToInt(str, 1));
	//cout << str[0];
	/*for (int i = 0; i < 4; i++) {
		switch (str[i]) {
		case '0':
			cout << 0;
			break;
		case '1':
			cout << 1;
			break;
		case '2':
			cout << 2;
			break;
		}
	}*/
	/*int a = 2 * pow(10, 4 - 1);
	int tong = 0;
	tong += a;
	cout << tong;*/
	return 0;
}