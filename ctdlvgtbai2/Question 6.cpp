#include <iostream>
#include <math.h>
#include <string>
#include <string.h>

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

	friend bool checkAuthor(Book book, const char* author)
	{
		/*
		 * STUDENT ANSWER
		 * TODO: returns true if the author is on the book's authors list, otherwise it returns false
		 */
		char* str = (char*)strstr(book.authors, author);
		if (str == NULL)
			return 0;
		else {
			int a = strlen(author);
			if (str[a] == '\0' || str[a] == ',' || str[a+1]=='\0' || str[a+2]=='\0')
				return 1;
			else return 0;
		}
	}

	void printBook() {
		printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
	}
};

int main() {
	Book book1("Giai tich 1", "Nguyen Dinh Huy, Nguyen Thi Xuan Anh", 2000);
	cout << checkAuthor(book1, "Nguyen Dinh Huy");
	return 0;
}