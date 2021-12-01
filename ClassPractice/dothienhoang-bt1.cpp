#include <iostream>
using namespace std;

class SinhVien {
private:
	int StudentID;
	char Name[40];
	static int n;
	int numofgrade;
	char namecourse[40];
	int ma=0;
	class Grades {
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
	Grades* gr;

public:
	//Grades gr;
	SinhVien() {
		cout << "--------\n";
		cout << "Input details for Student " << n++ << ':';
		cout << "\nStudent ID? ";
		cin >> this->StudentID;
		cout << "Name? ";
		cin >> this->Name;
		cout << "How many grades? ";
		cin >> numofgrade;
		gr = new Grades[numofgrade];
		for (int i = 1; i <= numofgrade; i++) {
			cout << "Name of grade " << i << ": ";
			cin >> namecourse;
			gr[i - 1].setname(namecourse);
			cout << "Mark of grade " << i << ": ";
			cin >> ma;
			gr[i - 1].setmark(ma);
		}
	}
	float getaverage() {
		int sum = 0;
		for (int i = 0; i < numofgrade; i++) {
			sum += gr[i].getmark();
		}
		return (float)sum / float(numofgrade);
	}
};

int SinhVien::n = 1;

int main() {
	int n,avg;
	cout << "Enter number of Students: ";
	cin >> n;
	SinhVien* sv = new SinhVien[n];
	cout << "-------\n";
	cout << "Which student average grade? ";
	cin >> avg;
	if (avg >= 1 && avg <= n) {
		cout << sv[avg - 1].getaverage() << endl;
	}
	return 0;
}