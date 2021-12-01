#include <iostream>
using namespace std;

bool containsPattern(char* text, char* pattern)
{
	/*
	 * STUDENT ANSWER
	 */
	static char* s1 = pattern;
	if (text[0] == '\0' && pattern[0] != '\0')
		return false;
	else if (pattern[0] == '\0') {
		if (text[0] == ' ' || text[0] == '\0')
			return true;
		else 
			return false;
	}
	if (text[0] == pattern[0]) {
		containsPattern(text + 1, pattern + 1);
	}
	else {
		pattern = s1;
		containsPattern(text + 1, pattern);		
	}
}

int main() {
	cout << containsPattern((char*)"Dai hoc Bach Khoan", (char*)"Bach Khoa");
	return 0;
}