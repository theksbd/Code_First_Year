#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const double PI = 3.14159;

void exitInvalid() {
	printf("-1");
	exit(0);
}

int factorial(int n) {
	if (n == 1)
		return 1;
	return n * factorial(n - 1);
}

double power(double n, int m) {
	double temp = n;
	for (int i = 1; i < m; i++)
		temp *= n;
	return temp;
}

double CalculateSin(double x) {
	double sin = x;
	bool flag = false;
	for (int i = 1; i <= 5; i++) {
		if (flag) {
			sin += power(x, 2 * i + 1) / factorial(2 * i + 1);
			flag = false;
		}
		else {
			sin -= power(x, 2 * i + 1) / factorial(2 * i + 1);
			flag = true;
		}
	}
	return sin;
}

double CalculateCos(double x) {
	double cos = 1;
	bool flag = false;
	for (int i = 1; i <= 5; i++) {
		if (flag) {
			cos += power(x, 2 * i) / factorial(2 * i);
			flag = false;
		}
		else {
			cos -= power(x, 2 * i) / factorial(2 * i);
			flag = true;
		}
	}
	return cos;
}

double CalculateTan(double x) {
	return CalculateSin(x) / CalculateCos(x);
}
double ConvertToRadian(double x) {
	x *= PI / 180;
	return x;
}

int main()
{
	int menu_code;
	scanf_s("%d", &menu_code);
	if (menu_code == 1) {
		//TODO
		int n, m, p;
		scanf_s("%d", &n);
		scanf_s("%d", &m);
		scanf_s("%d", &p);
		if (n < 1 || n > 3 || (m != 0 && m != 1) || (p != 2 && p != 4 && p != 7)) { // check if n,m,p are unaccepted
			exitInvalid();
		}
		else {
			double x;
			scanf_s("%lf", &x);
			if (!m) {
				if (x < 0 || x > 180 || (x == 90 && n == 3)) // check if x is out of range and if x, n are unaccepted
					exitInvalid();
				else {
					x = ConvertToRadian(x);
					x = (n == 1) ? CalculateSin(x) : ((n == 2) ? CalculateCos(x) : CalculateTan(x));
					switch (p) {
					case 2:
						printf("%.2lf", x);
						break;
					case 4:
						printf("%.4lf", x);
						break;
					default:
						printf("%.7lf", x);
						break;
					}
				}
			}
			else {
				if (x < 0 || x > PI || (x == PI / 2 && n == 3)) // check if x is out of range and if x, n are unaccepted
					exitInvalid();
				else {
					x = (n == 1) ? CalculateSin(x) : ((n == 2) ? CalculateCos(x) : CalculateTan(x));
					switch (p) {
					case 2:
						printf("%.2lf", x);
						break;
					case 4:
						printf("%.4lf", x);
						break;
					default:
						printf("%.7lf", x);
						break;
					}
				}
			}
		}
	}
	else if (menu_code == 2) {
		//TODO
		int m;
		scanf_s("%d", &m);
		if (m != 1 && m != 2) // check if m is unaccepted
			exitInvalid();
		else {
			int x;
			scanf_s("%d", &x);
			if (x <= 1) 
				exitInvalid();
			else {
				if (m == 1) {
					for (int i = 1; i <= x; i++) {
						if (x % i == 0) {
							printf("%d", i);
							if (i < x)
								printf(" ");
						}
					}
				}
				else {
					int count = 0;
					for (int i = 2; i <= x; i++) {
						while (x % i == 0) {
							count++;
							x /= i;
						}
						if (count) {
							printf("%d^%d", i, count);
							count = 0;
							if (i < x)
								printf("*");
						}
					}
				}
			}
		}
	}
	else {
		exitInvalid();
	}
}
