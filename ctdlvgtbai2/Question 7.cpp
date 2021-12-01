#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

using namespace std;

class Book
{
private:
	char* title;
	char* authors;
	int publishingYear;

public:
	Book()
	{
		/*
		 * STUDENT ANSWER
		 * TODO: set zero publishingYear and null pointer
		 */
		title = NULL;
		authors = NULL;
		publishingYear = 0;
	}

	Book(const char* title, const char* authors, int publishingYear)
	{
		/*
		 * STUDENT ANSWER
		 */
		this->title = (char*)title;
		this->authors = (char*)authors;
		this->publishingYear = publishingYear;
	}

	~Book()
	{
		/*
		 * STUDENT ANSWER
		 */
	}
	friend class Printer;
};

class Printer
{
public:
	static void printBook(const Book book)
	{
		/*
		 * STUDENT ANSWER
		 */
		cout << book.title << endl;
		char s1[100];
		strcpy(s1, book.authors);
		char* s2;
		s2 = strtok(s1, ",");
		while (s2 != NULL) {
			if (s2[0] == ' ')
				cout << s2 + 1 << endl;
			else cout << s2 << endl;
			s2 = strtok(NULL, ",");
		}
		cout << book.publishingYear << endl;
	}
};

int main() {
	Book book1("Introduction to Algorithms", "Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein", 1990);
	Printer::printBook(book1);
	return 0;
}