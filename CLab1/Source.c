#include <stdio.h>

void FindMaxMinArray(int a[], int n) {
	int max = a[0], min = a[0];
	for (int i = 1; i < n; i++) {
		if (max < a[i])
			max = a[i];
		if (min > a[i])
			min = a[i];
	}
	printf("Max value of array: %d\n", max);
	printf("Min value of array: %d\n", min);
}

void MathematicalArray(int a[], int n) {
	//note: round the average values to .5
	int sum = 0, sumnega = 0, sumposi = 0, nposi = 0, nnega = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (a[i] >= 0) {
			sumposi += a[i];
			if(a[i])
				nposi++;
		}
		else {
			sumnega += a[i];
			nnega++;
		}
	}
	printf("Average value of array: %.5lf\n", (double)sum / n);
	printf("Total negative value of array: %.5lf\n", (double)sumnega/ nnega);
	printf("Total positive value of array: %.5lf\n", (double)sumposi / nposi);
}

void FindIndexArray(int a[], int n, int x) {
	//note: Print -1 if x does not exist
	int first = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			if(!first)
				printf(" %d", i);
			else {
				printf("%d", i);
				first = 0;
			}
		}
	}
	if (first)
		printf("-1\n");
	else
		printf("\n");
}

int ReplaceElementArray(int a[], int n, int x, int index) {
	// note: if index >= n or index < 0, print "Out of range"
	if (index >= n || index < 0)
		return 0;
	else
		a[index] = x;
	return 1;
}

void CountElementArray(int a[], int n, int x) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == x)
			count++;
	}
	printf("Time to appear: %d\n", count);
}

int AddElementArray(int a[], int n, int x, int index) {
	// note: if index > n or index < 0, print "Out of range"
	if (index > n || index < 0)
		return 0;
	else {
		int a1[100];
		if (index == n) {
			for (int i = 0; i < n; i++)
				a1[i] = a[i];
			a1[n] = x;
		}
		else if (index == 0) {
			a1[0] = x;
			for (int i = 1; i <= n; i++)
				a1[i] = a[i - 1];
		}
		else {
			int flag = 0;
			for (int i = 0; i < n + 1; i++) {
				if (i != index) {
					if (!flag)
						a1[i] = a[i];
					else
						a1[i] = a[i - 1];
				}
				else {
					a1[i] = x;
					flag = 1;
				}
			}
		}
		for (int i = 0; i < n + 1; i++)
			a[i] = a1[i];
	}
	return 1;
}

int SortArray(int a[], int n, int option) {
	// note: if option is 0: sort descending, if 1: sort ascending, neither 0 nor 1: print "Error input"
	if (option != 0 && option != 1)
		return 0;
	else {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i] > a[j] == option) {
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
	}
	return 1;
}

int main() {
	int a[100], n;
	printf("Input your array's size: ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("Value of element a[%d]: ", i);
		scanf_s("%d", &a[i]);
	}
	// Choice
	int choice;
	int start = 1;
	while (1) {
		if (!start) {
		int renew;
		printf("Do you want to renew your array? (Press 0 to skip, otherwise to renew): ");
		scanf_s("%d", &renew);
			if (renew) {
				printf("Input your array's size: ");
				scanf_s("%d", &n);
				for (int i = 0; i < n; i++) {
					printf("Value of element a[%d]: ", i);
					scanf_s("%d", &a[i]);
				}
			}
		}
		printf("\n\n");
		printf("================================================\n");
		printf("1. Print out max and min value of array.\n");
		printf("2. Print out the average value of array, the average of negative and positive values of array.\n");
		printf("3. Find all index of an given element in array.\n");
		printf("4. Replace an element in array with given element at the given index.\n");
		printf("5. Count how many times the given element appears in the array.\n");
		printf("6. Add an element to array at the given index.\n");
		printf("7. Sort the array\n");
		printf("\n\nMake your choice: ");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1: 
		{
			FindMaxMinArray(a, n);
			break;
		}
		case 2:
		{
			MathematicalArray(a, n);
			break;
		}
		case 3:
		{
			int x;
			printf("Input the element you want to find index: ");
			scanf_s("%d", &x);
			FindIndexArray(a, n, x);
			break;
		}
		case 4:
		{
			int x, index;
			printf("Input the element you want to replace: ");
			scanf_s("%d", &x);
			printf("Input the index you want to replace at: ");
			scanf_s("%d", &index);
			int success = ReplaceElementArray(a, n, x, index);
			if (!success)
				printf("Out of range\n");
			else {
			int first = 1;
			for (int i = 0; i < n; i++) {
				if (first) {
					printf("%d", a[i]);
					first = 0;
				}
				else
					printf(" %d", a[i]);
			}
			printf("\n");
			}
			break;
		}
		case 5:
		{
			int x;
			printf("Input the element you want to count: ");
			scanf_s("%d", &x);
			CountElementArray(a, n, x);
			break;
		}
		case 6:
		{
			int x, index;
			printf("Input the element you want to add: ");
			scanf_s("%d", &x);
			printf("Input the index you want to add at: ");
			scanf_s("%d", &index);
			int success = AddElementArray(a, n, x, index);
			if (!success)
				printf("Out of range\n");
			else {
				n++;
				int first = 1;
				for (int i = 0; i < n; i++) {
					if (first) {
						printf("%d", a[i]);
						first = 0;
					}
					else
						printf(" %d", a[i]);
				}
				printf("\n");
			}
			break;
		}
		case 7:
		{
			int option;
			printf("Input the option: ");
			scanf_s("%d", &option);
			int success = SortArray(a, n, option);
			if (!success)
				printf("Error input\n");
			else {
			int first = 1;
			for (int i = 0; i < n; i++) {
				if (first) {
					printf("%d", a[i]);
					first = 0;
				}
				else
					printf(" %d", a[i]);
			}
			printf("\n");
			}
			break;
		}
		}
		start = 0;
		int con;
		printf("\nContinue? (Press 0 to stop, otherwise to continue) ");
		scanf_s("%d", &con);
		if (!con)
			break;
	}
	return 0;
}