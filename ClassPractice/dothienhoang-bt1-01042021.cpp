#include <iostream>
#include <string>

using namespace std;
//class University {
	class Faculty
	{
	protected:
		string name;
		static int numfa;
	public:
		Faculty() {
			cout << "Input details for Faculty " << numfa++ << ":\n";
			cout << "Input name: ";
			cin >> name;
		}
		~Faculty() {
			cout << "No Faculty" << endl;
		}
		void setNameFaculty(string n) {
			name = n;
		}
		string getNameFaculty() {
			return name;
		}
	};
	class Student
	{
	protected:
		int id;
		string name;
		string nameofsub;
		string fastu;
		static int numst;
	public:
		Student() {
			cout << "Input details for Student " << numst << ":\n";
			cout << "Input Name of Student " << numst << ": ";
			cin >> name;
			cout << "Input ID of Student " << numst << ": ";
			cin >> id;
			cout << "Input Faculty of Student " << numst << ": ";
			cin >> fastu;
			cout << "Input Subject Name of Student " << numst++ << ": ";
			cin >> nameofsub;
		}
		~Student() {
			cout << "No Student" << endl;
		}
		void setNameStudent(string n) { name = n; }
		void setSubjectNameStudent(string n) { nameofsub = n; }
		void setFacultyStudent(string n) { fastu = n; }
		void setIDStudent(int n) { id = n; }
		int getIDStudent() { return id; }
		string getNameStudent() { return name; }
		string getSubjectNameStudent() { return nameofsub; }
		string getFacultyStudent() { return fastu; }
	};
	class Lecturer
	{
	protected:
		string name;
		string falec;
		static int numle;
	public:
		Lecturer() {
			cout << "Input details for Lecturer " << numle << ":\n";
			cout << "Input Name of Lecturer " << numle << ": ";
			cin >> name;
			cout << "Input Faculty of Lecturer " << numle++ << ": ";
			cin >> falec;
		}
		~Lecturer() {
			cout << "No Lecturer" << endl;
		}
		void setNameLecturer(string n) {
			name = n;
		}
		void setFacultyLecturer(string fa) {
			falec = fa;
		}
		string getNameLecturer() { return name; }
		string getFacultyLecturer() { return falec; }
	};
	class Classroom
	{
	protected:
		string nameofclass;
		static int numcl;
	public:
		Classroom() {
			cout << "Input details for Classroom " << numcl++ << ":\n";
			cout << "Input name: ";
			cin >> nameofclass;
		}
		~Classroom() {
			cout << "No CLassroom" << endl;
		}
		void setNameClassroom(string n) {
			nameofclass = n;
		}
		string getNameClassroom() {
			return nameofclass;
		}
	};
	class Subject
	{
	protected:
		string name;
		int lec;
		string lecname;
		string classroom;
		static int numsu;
	public:
		Subject() {
			cout << "Input details for Subject " << numsu << ":\n";
			cout << "Input Name of Subject " << numsu << ": ";
			cin >> name;
			cout << "Input Lecturer Quantity of Subject " << numsu << ": ";
			cin >> lec;
			cout << "Input Lecturer's Name of Subject " << numsu << ": ";
			cin >> lecname;
			cout << "Input Class Hosted of Subject " << numsu++ << ": ";
			cin >> classroom;
		}
		~Subject() {
			cout << "No Subject" << endl;
		}
		void setNameSubject(string n) { name = n; }
		void setLecturerQuantitySubject(int n) { lec = n; }
		void setClassroomSubject(string n) { classroom = n; }
		string getNameSubject() { return name; }
		void setLecturerNameSubject(string n) { lecname = n; }
		string getLecturerNameSubject() { return lecname; }
		int getLecturerQuantitySubject() { return lec; }
		string getClassroomSubject() { return classroom; }
		//friend void printclass(string);
	};

//};
	/*void printclass(string n) {
		for (int i=1;i<=)
}*/

int /*University::*/Faculty::numfa = 1;
int /*University::*/Student::numst = 1;
int /*University::*/Lecturer::numle = 1;
int /*University::*/Classroom::numcl = 1;
int /*University::*/Subject::numsu = 1;

int main() {
	int numfaculty, numstudent, numlecturer, numsubject, numclassroom;
	Faculty* fa;
	Student* st;
	Lecturer* le;
	Classroom* cl;
	Subject* su;
	cout << "How many ";
	cout << "Faculties? ";
	cin >> numfaculty;
	fa = new Faculty[numfaculty];
	/*cout << fa[0].getNameFaculty() << endl;
			cout << fa[1].getNameFaculty() << endl;
			fa[1].setNameFaculty("KTHH");
			cout << fa[1].getNameFaculty() << endl;*/
	
	cout << "How many ";
	cout << "Lecturers? ";
	cin >> numlecturer;
	le = new Lecturer[numlecturer];
	/*cout << le[0].getNameLecturer() << endl;
			cout << le[1].getNameLecturer() << endl;
			le[1].setNameLecturer("DTH");
			cout << le[1].getNameLecturer() << endl;
			cout << le[0].getFacultyLecturer() << endl;
			cout << le[1].getFacultyLecturer() << endl;
			le[1].setFacultyLecturer("KTHH");
			cout << le[1].getFacultyLecturer() << endl;*/

	cout << "How many ";
	cout << "Students? ";
	cin >> numstudent;
	st = new Student[numstudent];
	/*cout << st[0].getNameStudent() << endl;
			st[0].setNameStudent("NVA");
			cout << st[0].getNameStudent() << endl;
			cout << st[0].getFacultyStudent() << endl;
			st[0].setFacultyStudent("KHMT");
			cout << st[0].getFacultyStudent() << endl;
			cout << st[0].getSubjectNameStudent() << endl;
			st[0].setSubjectNameStudent("CTDL");
			cout << st[0].getSubjectNameStudent() << endl;*/
	
	cout << "How many ";
	cout << "Classrooms? ";
	cin >> numclassroom;
	cl = new Classroom[numclassroom];
	/*cout << cl[0].getNameClassroom() << endl;
			cl[0].setNameClassroom("11b1");
			cout << cl[0].getNameClassroom() << endl;*/

	cout << "How many ";
	cout << "Subjects? ";
	cin >> numsubject;
	su = new Subject[numsubject];
	/*cout << su[0].getNameSubject() << endl;
			su[0].setNameSubject("NVA");
			cout << su[0].getNameSubject() << endl;
			cout << su[0].getLecturerQuantitySubject() << endl;
			su[0].setLecturerQuantitySubject(3);
			cout << su[0].getLecturerQuantitySubject() << endl;
			cout << su[0].getClassroomSubject() << endl;
			su[0].setClassroomSubject("12a1");
			cout << su[0].getClassroomSubject() << endl;*/
	int a;
	cout << "Please choose: ";
	cin >> a;
	if(a == 1) {
		string name;
		cout << "Enter classroom name? ";
		cin >> name;
		bool flag = 1;
		for (int i = 0; i < numsubject; i++) {
			if (su[i].getClassroomSubject() == name) {
				if (flag) flag = 0;
				else cout << " ";
				cout << su[i].getNameSubject();
			}
		}
	}
	else if (a == 2) {
		string name;
		cout << "Enter subject name? ";
		cin >> name;
		bool flag = 1;
		for (int i = 0; i < numstudent; i++) {
			if (st[i].getSubjectNameStudent() == name) {
				if (flag) 
					flag = 0;
				else 
					cout << " ";
				cout << st[i].getNameStudent();
			}
		}
	}
	else if (a == 3) {
		string name;
		cout << "Enter student name? ";
		cin >> name;
		bool flag = 1;
		for (int i = 0; i < numlecturer; i++) {
			if (st[i].getNameStudent() == name) {
				for (int j = 0; j < numlecturer; j++) {
					if (st[i].getSubjectNameStudent() == su[j].getNameSubject()) {
						if (flag)
							flag = 0;
						else
							cout << " ";
						cout << su[j].getLecturerNameSubject();
					}
				}
			}
		}
	}
	else if (a == 4) {
		string faname,suname;
		bool flag = 1;
		cout << "Enter faculty name? ";
		cin >> faname;
		cout << "Enter subject name? ";
		cin >> suname;
		for (int i = 0; i < numstudent; i++) {
			if (st[i].getFacultyStudent() == faname && st[i].getSubjectNameStudent() == suname) {
				if (flag)
					flag = 0;
				else
					cout << " ";
				cout << st[i].getNameStudent();
			}
		}
	}
	return 0;
}