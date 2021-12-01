#include <iostream>
using namespace std;

class Customer {
private:
	int ID;
	char Name[40];
	static int n;
	int numofgrade;
	char namecourse[40];
	int ma = 0;
	class Ticket {
	private:
		char NameOfCourse[40];
		int mark;
	public:
		/*Grades() {
			cout << "Name of grade " << num << ': ';
			cin >> this->NameOfCourse;
			cout << "Mark of grade " << num++ << ': ';
			cin >> this->mark;
		}*/
		void setname(char name[40]) {
			for (int i = 0; i < strlen(name); i++) {
				NameOfCourse[i] = name[i];
			}
		}
		void setmark(int m) {
			this->mark = m;
		}
		int getmark() {
			return this->mark;
		}
	};
	//Grades gr;
	Ticket* gr;

public:
	//Grades gr;
	Customer() {
		cout << "--------\n";
		cout << "Input details for Customer " << n++ << ':';
		cout << "\nName? ";
		cin >> this->Name;
		cout << "ID? ";
		cin >> this->ID;
		cout << "How many tickets? ";
		cin >> numofgrade;
		gr = new Ticket[numofgrade];
		for (int i = 1; i <= numofgrade; i++) {
			cout << "Input Flightname of Ticket " << i << ": ";
			cin >> namecourse;
			gr[i - 1].setname(namecourse);
			cout << "Value of Ticket " << i << ": ";
			cin >> ma;
			gr[i - 1].setmark(ma);
		}
	}
	int getsum() {
		int sum = 0;
		for (int i = 0; i < numofgrade; i++) {
			sum += gr[i].getmark();
		}
		return sum;
	}
};

int Customer::n = 1;

int main() {
	int n, avg;
	cout << "Enter number of Customers: ";
	cin >> n;
	Customer* cs = new Customer[n];
	cout << "-------\n";
	cout << "Which customer with sum value? ";
	cin >> avg;
	if (avg >= 1 && avg <= n) {
		cout << "Sum Value of Customer: " << cs[avg - 1].getsum() << endl;
	}
	return 0;
}