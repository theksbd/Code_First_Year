#include <iostream> 
using namespace std;

int strLen(char* str)
{
	/*
	 * STUDENT ANSWER
	 */
	/*static int n = 0;
	if (strlen(str) == 1)
		return ++n;
	else {
		strLen(str + 1);
		return ++n;
	}*/
	//return(str[0] == '\0') ? 0 : 1 + strLen(str + 1);
	if (str[0] == '\0')
		return 0;
	else
		return 1 + strLen(str + 1);
}


int main() {
	char str[] = "dh bktphcm";
	cout << strLen(str);
	return 0;
}