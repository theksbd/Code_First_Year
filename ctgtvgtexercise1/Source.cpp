#include <iostream>

#include <fstream>

#include <string>

#include <cmath>

using namespace std;

struct Node {
	int data;
	struct Node* next;
};

class PhoneList 
{
private:
	char* first;
	char* last;
	char* phone;
public:
	PhoneList() {
		first = last = phone = nullptr;
	}
	PhoneList(char* first, char* last, char* phone) {
		this->first = first;
		this->last = last;
		this->phone = phone;
	}
	~PhoneList(){
	
	}
	friend struct Node;

};

int main() {

	/*PhoneList list;
	list.append("Johnny", "Depp", "012345678");
	list.append("alexander", "rybak", "123456790");
	list.reOrder();
	list.display();*/

	return 0;
}