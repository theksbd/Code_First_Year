//============================================================================
// Name        : antiem.cpp
// Author      : 
// Version     : 
// Copyright   : Your copyright notice
// Description : assignment 2
// Created on  : 
//============================================================================

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

/******************************************************************************
 * Support Functions: these functions below are optional. If you want your code
					  to be clearer, you can implement them. However if you
					  dont know how to use funtion in programming, dont worry,
					  you dont have to implement them, and you just add a comment
					  in each of them.
*******************************************************************************/
/*bool isPrimeNumber(int n) {
	TODO: add your code here
	

}
//bool isFibonacci(int n) {
	TODO: add your code here


}*/
float TriangleNumber(int n) {
	//TODO: add your code here
	if (n == 0)
		return 0;
	return TriangleNumber(n - 1) + n;
}
int fibonacci(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fibonacci(n - 2) + fibonacci(n - 1);
}

/**********************************************************************
 * Input & output for program: these function below are neccessary. You
							   have to finish the function display()
**********************************************************************/
bool readFile(int& hp, int& d, int& s) {
	 const char* file_name = "input.txt";
	ifstream in;
	in.open(file_name);
	in >> hp;
	in >> d;
	in >> s;
	in.close();

	if (hp < 1 || hp > 999) return false;
	if (d < 1 || d > 1000) return false;
	if (s < 1 || s > 100) return false;

	return true;
}
void display(float pR) {
	//Set pR = 0 if pR < 0 and set pR = 1 if pR > 1
	//Remember to round 3 decimal places for pR
	/*TODO: add your code here*/
	if (pR < 0)
		pR = 0;
	else if (pR > 1)
		pR = 1;
	round((pR * 1000) / 1000);

	cout << pR;
}

/**********************************************************************
 * My program
**********************************************************************/
int main() {

	//Declare variables
	int hp = 0;
	int d = 0;
	int s = 0;
	float P1 = 0;	//store value of P1
	float P2 = 0;	//store value of P2
	float f = 0.0;	//store value of f(d,s)
	float pR = -1; //No valid

	//Input data
	if (readFile(hp, d, s)) {
		/*Calculate P1 & P2
		Rememeber to check if hp is a prime number*/
		/*TODO: add your code here*/
		int count = 0;
		for (int i = 2; i < hp; i++) {
			if ((hp % i) == 0)
				count++;
		}
		switch (count) {
		case 0:
			P1 = 1000;
			P2 = (hp + s) % 1000;
			break;
		default:
			P1 = hp;
			P2 = (hp + d) % 100;
			break;
		}
		/*---------------------------------
			Calculate f(d,s)
			Remember to check if d+s is a number of Fibonaci sequence
		*/
		/*TODO: add your code here*/
			for (int n = 0; n < 15; n++) {
				if (d < 200 && (d + s) != fibonacci(n))
					f = 0;
			}
			for (int n = 0; n < 15; n++) {
				if (((d + s) == fibonacci(n)) || (300 < d && d <= 800)){
					f = 40 - (abs(d - 500) / 20);
				int a;
				float g;
				a = s % 6;
				switch (a) {
				case 0:
					g = s / 2;
					break;
				case 1:
					g = 2 * s;
					break;
				case 2:
					g = -pow(s % 9, 3) / 5;
					break;
				case 3:
					g = -pow(s % 30, 2) + (3 * s);
					break;
				case 4:
					g = -s;
					break;
				default:
					int n;
					n = (s % 5) + 5;
					g = TriangleNumber(n);
					break;
				}
				f += g;
				}
			}
			if (d > 800)
				f = -d * s / 1000;
			
				/*---------------------------------
					Calculate p(R)
					Remember to check if the probability of being bitten by snakes > 0.8
				*/
				/*TODO: add your code here*/
			float p ;
				pR = (P1 + P2 * f) / (1000 + abs(P2 * f));
				p = (d + P1 + P2) / 1000;
			if (200 <= d && d <= 300 && p > 0.8)
				pR = 0;
	}
	//Output result
	display(pR);
}
