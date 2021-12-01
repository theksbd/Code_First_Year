/*****Version 1.1***********/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
//read data from input file to corresponding variables
//return 1 if successfully done, otherwise return 0
int readFile(int& baseHP1, int& baseHP2, int& wp1, int& wp2, int& ground)
{
	const char* file_name = "input.txt";
	ifstream in;
	in.open(file_name);
	in >> baseHP1;
	in >> wp1;
	in >> baseHP2;
	in >> wp2;
	in >> ground;
	in.close();
	if (baseHP1 < 99 || baseHP1 > 999)
		return 0;
	if (wp1 < 0 || wp1 > 3)
		return 0;
	if (baseHP2 < 1 || baseHP2 > 888)
		return 0;
	if (wp2 < 0 || wp2 > 3)
		return 0;
	if (ground < 1 || ground > 999)
		return 0;
	in.close();
	return 1;

}
int checkwp(int wp, int base) { // kiểm tra loại wp
	float real = 0.0;
	switch (wp) {
	case 0:
		real = base / 10;
		break;
	case 1:
		real = base;
		break;
	default:
		real = base;
		break;
	}
	return real;
}
bool checksnto(int base) { // kiểm tra số nguyên tố
	int count = 0;
	for (int i = 2; i < base; i++) {
		if (base % i == 0)
			count++;
	}
	if (count == 0)
		return true;
	else
		return false;
}

void display(float fOut)
//display value of fOut in format of 0.XX
// no exception handled
{
	if (fOut == 1) {
		cout << fOut;
	}
	else {
		char s[10];
		sprintf_s(s, "%.2f", fOut);
		cout << s;
		
	}
}
int main(void)
{
	int baseHP1, baseHP2, wp1, wp2, ground;
	float fOut = 0.0;
	readFile(baseHP1, baseHP2, wp1, wp2, ground);
	//write your code here
	bool baseHP01, baseHP02;
	float realHP1, realHP2;
	realHP1 = checkwp(wp1, baseHP1);
	realHP2 = checkwp(wp2, baseHP2);
	if (ground == baseHP1)
		realHP1 *= 1.1;
	if (ground == baseHP2)
		realHP2 *= 1.1;
	if (baseHP1 == 999) {
		fOut = 1;
		goto labelend;
	}
	if (baseHP2 == 888) {
		fOut = 0.00;
		goto labelend;
	}
	baseHP01 = checksnto(baseHP1);
	baseHP02 = checksnto(baseHP2);
	if (baseHP01 == true && baseHP02 == false) {
		fOut = 0.99;
		goto labelend;
	}
	else if (baseHP01 == false && baseHP02 == true) {
		fOut = 0.01;
		goto labelend;
	}
	else if (baseHP01 == true && baseHP02 == true) {
		if (baseHP1 < baseHP2) {
			fOut = 0.01;
			goto labelend;
		}
		else if (baseHP1 > baseHP2) {
			fOut = 0.99;
			goto labelend;
		}
		else {
			fOut = 0.5;
			goto labelend;
		}
	}
	if (wp1 == 2 && wp2 == 2){
			goto label2;
	}
	else if (wp1 == 2 && wp2 != 2) {
		if (realHP1 >= realHP2)
			goto label1;
		else
			goto label2;
	}
	else if (wp2 == 2 && wp1!=3) {
		if (realHP2 >= realHP1)
			goto label1;
		else
			goto label2;
	}
	if (wp1 == 3) {
		realHP1 *= 2;
		goto label1;
	}
	if (wp2 == 3)
		goto label1;
label1: {
	if (realHP1 > 999)
		realHP1 = 999;
	if (realHP2 > 999) 
		realHP2 = 999;
	cout << realHP1 << "\t" << realHP2 << endl;
	fOut = (realHP1 - realHP2 + 999) / 2000;
	goto labelend; //labelend xuất kết quả
	}
label2: {
	fOut = 0.5;
	goto labelend;
	}
labelend:
	display(fOut);
	return 0;
}
