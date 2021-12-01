/* Note:
	* You change anything in this answer
	* such that your implementation must have BusSystem class with method query.
	* This query method should return the output of each instruction
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class BusSystem {
public:
	class Node {
	private:
		string CODE, LP, CASE;
		int TIMEA, TIMEB;
	};
public:
	~BusSystem() {};

	void DivideString(string instr, string& str1, string& str2, string& str3, string& str4, string& str5, string& str6) {
		int count = 1;
		int j = 0;
		for (int i = 0; i < instr.length(); i++) {
			if (instr[i + 1] == ' ') {
				j = i + 2;
				str1 = instr.substr(0, i + 1);
				count++;
				break;
			}
		}
		for (int i = j; i < instr.length(); i++) {
			if (instr[i + 1] == ' ' || i == (instr.length() - 1)) {
				switch (count) {
				case 2:
					str2 = instr.substr(j, i - j + 1);
					j = i + 2;
					i++;
					count++;
					break;
				case 3:
					str3 = instr.substr(j, i - j + 1);
					j = i + 2;
					i++;
					count++;
					break;
				case 4:
					str4 = instr.substr(j, i - j + 1);
					j = i + 2;
					i++;
					count++;
					break;
				case 5:
					str5 = instr.substr(j, i - j + 1);
					j = i + 2;
					i++;
					count++;
					break;
				case 6:
					str6 = instr.substr(j, i - j + 1);
					j = i + 2;
					i++;
					count++;;
					break;
				}
			}
		}
	}

	string query(string instruction) {
		// TODO: Your implementation
		string str1 = "", str2 = "", str3 = "", str4 = "", str5 = "", str6 = "";
		this->DivideString(instruction, str1, str2, str3, str4, str5, str6);
		/*cout << str1 << endl;
		cout << str2 << endl;
		cout << str3 << endl;
		cout << str4 << endl;
		cout << str5 << endl;*/
		
		if (str1 == "SQ") {
			
		}
		else if (str1 == "INS") {
			
		}
		return "-1";
	}
};

int main() {
	BusSystem* bs = new BusSystem();
	cout << bs->query("SQ 500") << endl;
	//cout << bs->query("INS 50 50D1-23342 1234 5678") << endl;
	//cout << bs->query("CS 50 2134") << endl;
	return 0;
}


		//int count = 0;
		//string str[6] = { "NULL", "NULL", "NULL", "NULL", "NULL", "NULL" };
		//int j = 0;
		//for (int i = 0; i < instruction.length(); i++) {
		//	string substr = instruction.substr(i);
		//	//cout << substr << endl;
		//	if (substr.at(0) == ' ') {
		//		if (j == 0) {
		//			str[count] = instruction.substr(j, i);
		//			count++;
		//			j = i + 1;
		//			i = 0;
		//			//cout << str[0] << endl;
		//			/*cout << j << endl;
		//			cout << i << endl;
		//			cout << instruction.length() << endl;*/
		//		}
		//		//cout << i << '\t'<< j << endl;
		//		else {
		//			str[count] = instruction.substr(j, i - 1);
		//			count++;
		//			j += i;
		//			i = 0;
		//		}
		//	}
		//	else if (substr.length() == 1) {
		//		str[count] = instruction.substr(j, i);
		//		break;
		//	}
		//}
		//for (int i = 0; i < 6; i++) {
		//	cout << str[i] << endl;
		//}