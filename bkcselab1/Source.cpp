//#include <iostream>
//#include <fstream>
//using namespace std;
//int permutation(int n, int m) {
//	if (m == n || m == 0)
//		return 1;
//	else return permutation(n - 1, m) + permutation(n - 1, m - 1);
//}
//int main(int narg, char** argv)
//{
//	ifstream ifs;
//	ifs.open(argv[1]);
//	int N;
//	int M;
//	try
//	{
//		ifs >> N;
//		ifs >> M;
//		cout << permutation(N, M) << endl;
//	}
//	catch (char const* s)
//	{
//		printf("An exception occurred. Exception type: %s\n", s);
//	}
//
//	ifs.close();
//	return 0;
//}

//#include <iostream>
//#include <fstream>
//using namespace std;
//int gcd(int p, int q)
//{
//	static int t=p;
//	if (p == 1 || q == 1)
//		return 1;
//	/*if (p % q == 0)
//		return q;*/
//	if (q % p == 0 && t%p==0)
//		return p;
//	else return gcd(p - 1, q);
//}
//
//int main(int narg, char** argv)
//{
//	ifstream ifs;
//	ifs.open(argv[1]);
//	int p;
//	int q;
//	try
//	{
//		ifs >> p;
//		ifs >> q;
//		cout << gcd(p, q) << endl;
//	}
//	catch (char const* s)
//	{
//		printf("An exception occurred. Exception type: %s\n", s);
//	}
//
//	ifs.close();
//	return 0;
//}


//#include <iostream>
//#include <fstream>
//#include <string.h>
//using namespace std;
//bool palindrome(char strg[], int j)
//{
//	static int n = strlen(strg);
//	n--;
//	if (strlen(strg) == 1)
//		return 1;
//	else if (strg[j] == strg[n]) {
//		if (j == n || j == n-1)
//			return 1;
//		else return palindrome(strg, j + 1);
//	}
//	else return 0;
//}
//
//int main(int narg, char** argv)
//{
//	ifstream ifs;
//	ifs.open(argv[1]);
//	char strg[100];
//	try
//	{
//		while (ifs.getline(strg, 100, '\n')) {
//			cout << strg << " " << palindrome(strg, 0) << endl;
//			if (strg[0] == '*') break;
//		}
//	}
//	catch (char const* s)
//	{
//		printf("An exception occurred. Exception type: %s\n", s);
//	}
//
//	ifs.close();
//	return 0;
//}


//#include <iostream>
//#include <fstream>
//using namespace std;
//bool uniqueElement(int size, int* a, int i)
//{
//	if (size == 1)
//		return 1;
//	if (a[i] != a[size - 1]) {
//		if (i < size - 2) return uniqueElement(size, a, i + 1);
//		else return uniqueElement(size - 1, a, 0);
//	}
//	else return 0;
//}
//
//int main(int narg, char** argv)
//{
//
//	ifstream ifs;
//	ifs.open(argv[1]);
//
//	int size;
//	ifs >> size;
//	int i = 0;
//	int* a = new int[size];
//	try {
//
//		while (ifs >> a[i])
//		{
//			i++;
//		}
//		cout << uniqueElement(size, a, 0) << endl;
//	}
//	catch (char const* s)
//	{
//		printf("An exception occurred. Exception type: %s\n", s);
//	}
//
//	ifs.close();
//	return 0;
//}



#include <iostream>
#include <fstream>
using namespace std;
int linearSearch(int* a, int key, int sizeofArray)
{
	//TODO
	if (sizeofArray == -1) return -1;
	else if (key == a[sizeofArray-1]) {
		return sizeofArray-1;
	}
	else return linearSearch(a, key, sizeofArray - 1);
}

// you should remove element in array
// function return array
int* removeElement(int* a, int& n, int position) {
	//TODO
	if (position >  n || position < 0) return a;
	if (position == n) {
		n--;
		return a;
	}
	else {
		a[position] = a[position + 1];
		return removeElement(a, n, position + 1);
	}
}


int main(int narg, char** argv)
{
	ifstream ifs;
	ifs.open(argv[1]);

	int N, M, position;
	ifs >> N;
	ifs >> M;
	ifs >> position;
	int i = 0;
	int* a = new int[N];
	try {

		while (ifs >> a[i])
		{
			i++;
		}
		cout << linearSearch(a, M, N) << endl;
		int* newA = removeElement(a, N, position);
		for (int i = 0; i < N; i++) {
			cout << newA[i] << " ";
		}
		cout << endl;
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}

