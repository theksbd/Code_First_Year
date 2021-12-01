//#include <iostream>
//#include <math.h>
//#include <fstream>
//using namespace std;
//
//ifstream ifs;
//
//struct POINT
//{
//	float x;
//	float y;
//};
//
//void display(POINT* p)
//{
//	if (p != NULL)
//	{
//		cout << p->x << endl;
//		cout << p->y << endl;
//		delete p;
//	}
//}
//
//POINT* readPoint()
//{
//	POINT* ptr = new POINT;
//	ifs >> ptr->x;
//	ifs >> ptr->y;
//	return ptr;
//}
//
//int main(int narg, char** argv)
//{
//	ifs.open(argv[1]);
//
//	POINT* p = readPoint();
//	display(p);
//	delete p;
//
//	ifs.close();
//	return 0;
//}


//#include <iostream>
//#include <fstream>
//using namespace std;
//
//ifstream ifs;
//
//void readArray(int** a)
//{
//
//}
//
//void printArray(int** a)
//{
//
//}
//
//int main(int narg, char** argv)
//{
//	ifs.open(argv[1]);
//
//	int** arr;
//	arr = new int* [10];
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = new int[10];
//	}
//
//	readArray(arr);
//	printArray(arr);
//
//	for (int i = 0; i < 10; i++)
//	{
//		delete[] arr[i];
//	}
//	delete[] arr;
//
//	ifs.close();
//	return 0;
//}