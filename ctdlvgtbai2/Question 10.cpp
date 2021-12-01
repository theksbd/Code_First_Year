#include <iostream>
#include <math.h> 

using namespace std;

void ascendingSort(int a[], int n) {
	/*
	 * STUDENT ANSWER
	 * TODO: sort array in ascending order.
	 */
	//int max = a[0];
	for (int i = 0; i < n; i++) {
		//int t = a[i];
		for (int j = i + 1; j < n; j++) {
			int k;
			if (a[i] > a[j]) {
				k = a[i];
				a[i] = a[j];
				a[j] = k;
			}
		}
	}
}

void descendingSort(int a[], int n) {
	/*
	 * STUDENT ANSWER
	 * TODO: sort array in descending order.
	 */
	for (int i = 0; i < n; i++) {
		//int t = a[i];
		for (int j = i + 1; j < n; j++) {
			int k;
			if (a[i] < a[j]) {
				k = a[i];
				a[i] = a[j];
				a[j] = k;
			}
		}
	}
}

void mySort(int a[], int n, void (*sort)(int[], int)) {
	/*
	 * STUDENT ANSWER
	 * TODO: sort array based on sort algorithm of function sort.
	 */
	sort= descendingSort;
	(*sort)(a, n);
}

int main() {
	//<TEST>
	int a[5] = { 1,11,15,7,3 }, n = 5;
	void (*sortAlgorithm)(int[], int) = NULL;
	mySort(a, n, sortAlgorithm);

	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}

	return 0;
}