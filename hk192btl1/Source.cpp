#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <math.h>

using namespace std;

//const int MADBEAR = 1;
//const int BANDIT = 2;
const int EVENT_SIZE = 100;
const int MAX_CHARACTER_EACH_LINE = 250;

struct knight
{
	int HP;
	int level;
	int remedy;
	int maidenkiss;
	int phoenixdown;
};

// read data from input file to corresponding variables
// return 1 if successfully done, otherwise return 0
int readFile(const char* filename, knight& theKnight, int& nEvent, int* arrEvent)
{
	const char* file_name = filename;
	FILE* f = 0;
	char* str = new char[MAX_CHARACTER_EACH_LINE];
	int num;

	f = fopen(file_name, "r");
	if (f == NULL)	//file not found || cannot read
		return 0;

	fgets(str, MAX_CHARACTER_EACH_LINE, f);
	if (feof(f))
		return 0;

	int start = 0;
	int len = strlen(str);
	// read HP
	while (start < len && str[start] == ' ')
		start++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0') {
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.HP = num;
	if (theKnight.HP < 1 || theKnight.HP > 999)
		return 0;

	// read level
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0') {
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.level = num;
	if (theKnight.level < 1 || theKnight.level > 10)
		return 0;

	// read remedy
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0') {
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.remedy = num;
	if (theKnight.remedy < 0 || theKnight.remedy > 99)
		return 0;

	// read maidenkiss
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0') {
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.maidenkiss = num;
	if (theKnight.maidenkiss < 0 || theKnight.maidenkiss > 99)
		return 0;

	// read phoenixdown
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0') {
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.phoenixdown = num;
	if (theKnight.phoenixdown < 0 || theKnight.phoenixdown > 99)
		return 0;

	// read events
	nEvent = 0;
	while (1) {
		if (feof(f))
			break;
		fgets(str, MAX_CHARACTER_EACH_LINE, f);
		if (str == NULL)
			break;
		start = 0;
		len = strlen(str);
		// cout << "\'" << str << "\'" << "\t" << len << endl;
		while (start < len) {
			while (start < len && (str[start] > '9' || str[start] < '0'))
				start++;
			if (start >= len)
				break;
			arrEvent[nEvent] = 0;
			while (start < len && str[start] <= '9' && str[start] >= '0') {
				arrEvent[nEvent] = arrEvent[nEvent] * 10 + str[start] - '0';
				start++;
			}
			nEvent++;
		}
		delete[] str;
	}
	fclose(f);
	return 1;
}

int fibo(int n) {
	int a = 1, b = 1, c = 0;
	while (c < n) {
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

bool checkprimenumber(int n) {
	int count = 0;
	for (int i = 2; i < n; i++) {
		if (n % i == 0)
			count++;
	}
	if (count == 0)
		return true;
	else
		return false;
}

bool checkoddeven(int n) {
	if (n % 2 == 0)
		return false;
	else
		return true;
}

void display(int* nOut)
{
	if (nOut)
		cout << *nOut;
	else
		cout << "Error!";
}


int main(int argc, char** argv)
{
	if (argc < 2) return 1;
	const char* filename = argv[1];;

	struct knight theKnight;
	int nEvent; //number of events
	int* arrEvent = new int[EVENT_SIZE]; // array of events
	int* nOut;                           // final result
	int i;
	readFile(filename, theKnight, nEvent, arrEvent);
	//cout << theKnight.HP << ' ' << theKnight.level << ' ' << theKnight.remedy << ' ' << theKnight.maidenkiss << ' ' << theKnight.phoenixdown << endl;
	
	int result, level, b, maxHP, HPfibo;
	float damage;
	bool exca=false, myth=false, excafake=false, miniknight=false, frogknight=false, odin=false, odinsecond=false,arthur=false;
	bool checkpaladin, paladin = false;
	bool checklancelot, lancelot = false, lancelotodd = false, lanceloteven = false;
	int count6=100, count7=100, countodin=100;
	int oldlevel = theKnight.level;
	int levelknight;
	maxHP = theKnight.HP;
	checkpaladin = checkprimenumber(theKnight.HP);
	if (theKnight.HP == 999)
		arthur = true;
	else if (checkpaladin == true)
		paladin = true;
	else if (theKnight.HP == 888)
		lancelot = true;
	for (i = 0; i < nEvent; i++)
	{
		if (lancelot == true) {
			checklancelot = checkoddeven(theKnight.level);
			if (checklancelot == true) {
				lanceloteven = false;
				lancelotodd = true;
			}
			else {
				lancelotodd = false;
				lanceloteven = true;
			}
		}
		count6++;
		count7++;
		countodin++;
		b = (i+1) % 10;
		level = (i+1) > 6 ? (b > 5 ? b : 5) : b;
		int theEvent = arrEvent[i];
		//cout << theEvent << " ";
		switch (theEvent) {
		case 0:
		{
			result = theKnight.HP + theKnight.level + theKnight.maidenkiss + theKnight.phoenixdown + theKnight.remedy;
			goto labelend;
			break;
		}
		case 1:
		{
			damage = 1 * level * 10;
			if (theKnight.level < level && myth == false && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
				theKnight.HP -= damage;
			else if (excafake == true && myth == false && odin == false && lancelotodd == false)
				theKnight.HP -= damage;
			else if (excafake == true && myth == true && odin == false && lancelotodd == false)
				theKnight.HP = theKnight.HP;
			else if (theKnight.level < level && myth == true && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
				theKnight.HP = theKnight.HP;
			else if (theKnight.level == level && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
				theKnight.HP == theKnight.HP;
			else if (theKnight.level > level || exca == true || odin == true || arthur == true || paladin == true || lancelotodd == true)
				theKnight.level++;
			if (count6 == 3) {
				miniknight = false;
				theKnight.HP *= 5;
			}
			if (count7 == 3) {
				frogknight = false;
				theKnight.level = oldlevel;
			}
			if (countodin == 3) {
				odinsecond = true;
				odin = false;
			}
			break;
			
		}
		case 2:
		{
			damage = 1.5 * level * 10;
			if (theKnight.level < level && myth == false && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
				theKnight.HP -= damage;
			else if (excafake == true && myth == false && odin == false && lancelotodd == false)
				theKnight.HP -= damage;
			else if (excafake == true && myth == true && odin == false && lancelotodd == false)
				theKnight.HP = theKnight.HP;
			else if (theKnight.level < level && myth == true && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
				theKnight.HP = theKnight.HP;
			else if (theKnight.level == level && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
				theKnight.HP == theKnight.HP;
			else if (theKnight.level > level || exca == true || odin == true || arthur == true || paladin == true || lancelotodd == true)
				theKnight.level++;
			if (count6 == 3) {
				miniknight = false;
				theKnight.HP *= 5;
			}
			if (count7 == 3) {
				frogknight = false;
				theKnight.level = oldlevel;
			}
			if (countodin == 3) {
				odinsecond = true;
				odin = false;
			}
			break;
		}
		case 3:
		{
			damage = 4.5 * level * 10;
			if (theKnight.level < level && myth == false && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
				theKnight.HP -= damage;
			else if (excafake == true && myth == false && odin == false && lancelotodd == false)
				theKnight.HP -= damage;
			else if (excafake == true && myth == true && odin == false && lancelotodd == false)
				theKnight.HP = theKnight.HP;
			else if (theKnight.level < level && myth == true && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
				theKnight.HP = theKnight.HP;
			else if (theKnight.level == level && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
				theKnight.HP == theKnight.HP;
			else if (theKnight.level > level || exca == true || odin == true || arthur == true || paladin == true || lancelotodd == true)
				theKnight.level++;
			if (count6 == 3) {
				miniknight = false;
				theKnight.HP *= 5;
			}
			if (count7 == 3) {
				frogknight = false;
				theKnight.level = oldlevel;
			}
			if (countodin == 3) {
				odinsecond = true;
				odin = false;
			}
			break;
		}
		case 4:
		{
			damage = 6.5 * level * 10;
			if (theKnight.level < level && myth == false && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
				theKnight.HP -= damage;
			else if (excafake == true && myth == false && odin == false && lancelotodd == false)
				theKnight.HP -= damage;
			else if (excafake == true && myth == true && odin == false && lancelotodd == false)
				theKnight.HP = theKnight.HP;
			else if (theKnight.level < level && myth == true && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
				theKnight.HP = theKnight.HP;
			else if (theKnight.level == level && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
				theKnight.HP == theKnight.HP;
			else if (theKnight.level > level || exca == true || odin == true || arthur == true || paladin == true || lancelotodd == true)
				theKnight.level++;
			if (count6 == 3) {
				miniknight = false;
				theKnight.HP *= 5;
			}
			if (count7 == 3) {
				frogknight = false;
				theKnight.level = oldlevel;
			}
			if (countodin == 3) {
				odinsecond = true;
				odin = false;
			}
			break;
		}
		case 5:
		{
			damage = 8.5 * level * 10;
			if (theKnight.level < level && myth == false && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
				theKnight.HP -= damage;
			else if (excafake == true && myth == false && odin == false && lancelotodd == false)
				theKnight.HP -= damage;
			else if (excafake == true && myth == true && odin == false && lancelotodd == false)
				theKnight.HP = theKnight.HP;
			else if (theKnight.level < level && myth == true && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
				theKnight.HP = theKnight.HP;
			else if (theKnight.level == level && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
				theKnight.HP == theKnight.HP;
			else if (theKnight.level > level || exca == true || odin == true || arthur == true || paladin == true || lancelotodd == true)
				theKnight.level++;
			if (count6 == 3) {
				miniknight = false;
				theKnight.HP *= 5;
			}
			if (count7 == 3) {
				frogknight = false;
				theKnight.level = oldlevel;
			}
			if (countodin == 3) {
				odinsecond = true;
				odin = false;
			}
			break;
		}
		case 8:
		{
				exca = true;
				excafake = false;
				if (count6 == 3) {
					miniknight = false;
					theKnight.HP *= 5;
				}
				if (count7 == 3) {
					frogknight = false;
					theKnight.level = oldlevel;
				}
				if (countodin == 3) {
					odinsecond = true;
					odin = false;
				}
			break;
		}
		case 9:
		{
			
				myth = true;
				if (count6 == 3) {
					miniknight = false;
					theKnight.HP *= 5;
				}
				if (count7 == 3) {
					frogknight = false;
					theKnight.level = oldlevel;
				}
				if (countodin == 3) {
					odinsecond = true;
					odin = false;
				}
			break;
		}
		case 10:
		{
			
				if (theKnight.level >= 5 || odin == true || arthur == true || paladin == true || lancelotodd == true)
					theKnight.HP = theKnight.HP;
				else {
					exca = false;
					excafake = true;
				}
				if (count6 == 3) {
					miniknight = false;
					theKnight.HP *= 5;
				}
				if (count7 == 3) {
					frogknight = false;
					theKnight.level = oldlevel;
				}
				if (countodin == 3) {
					odinsecond = true;
					odin = false;
				}
			
			break;
		}
		case 6:
		{
			if (miniknight == true || frogknight == true)
				theKnight.HP = theKnight.HP;
			else if (theKnight.level == level && excafake == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
				theKnight.HP = theKnight.HP;
			else if (theKnight.level > level && excafake == false)
				theKnight.level += 2;
			else if (odin == true)
				theKnight.level += 2;
			else if (arthur == true)
				theKnight.level += 2;
			else if (paladin == true)
				theKnight.level += 2;
			else if (lancelotodd == true)
				theKnight.level += 2;
			else if (theKnight.level < level && miniknight == false && frogknight == false) {
				count6 = 0;
				miniknight = true;
				if (myth == false) {
					if (theKnight.HP < 5)
						theKnight.HP = 1;
					else
						theKnight.HP /= 5;
				}
				else if (myth == true)
					theKnight.HP = theKnight.HP;
			}
			else if (excafake == true && miniknight == false && frogknight == false) {
				count6 = 0;
				miniknight = true;
				if (myth == false) {
					if (theKnight.HP < 5)
						theKnight.HP = 1;
					else 
						theKnight.HP /= 5;
				}
				else if (myth == true) 
					theKnight.HP = theKnight.HP;
			}
			if (count6 == 3) {
				theKnight.HP *= 5;
				miniknight = false;
			}
			if (count7 == 3) {
				frogknight = false;
				theKnight.level = oldlevel;
			}
			if (countodin == 3) {
				odinsecond = true;
				odin = false;
			}
			break;
		}
		case 7:
		{
			if (miniknight == true || frogknight == true)
				theKnight.HP = theKnight.HP;
			else if (theKnight.level == level && excafake == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
				theKnight.HP = theKnight.HP;
			else if (theKnight.level > level && excafake == false)
				theKnight.level += 2;
			else if (odin == true)
				theKnight.level += 2;
			else if (arthur == true)
				theKnight.level += 2;
			else if (paladin == true)
				theKnight.level += 2;
			else if (lancelotodd == true)
				theKnight.level += 2;
			else if (theKnight.level < level && frogknight == false && miniknight == false) {
				frogknight = true;
				count7 = 0;
				oldlevel = theKnight.level;
				theKnight.level = 1;
			}
			else if (excafake == true && frogknight == false && miniknight == false) {
				frogknight = true;
				count7 = 0;
				oldlevel = theKnight.level;
				theKnight.level = 1;
			}
			if (count6 == 3) {
				theKnight.HP *= 5;
				miniknight = false;
			}
			if (count7 == 3) {
				frogknight = false;
				theKnight.level = oldlevel;
			}
			if (countodin == 3) {
				odinsecond = true;
				odin = false;
			}
			break;
		}
		case 11: 
		{
			theKnight.HP += 50;
			if (count6 == 3) {
				miniknight = false;
				theKnight.HP *= 5;
			}
			if (count7 == 3) {
				frogknight = false;
				theKnight.level = oldlevel;
			}
			if (countodin == 3) {
				odinsecond = true;
				odin = false;
			}
			break;
		}
		case 12:
		{
			theKnight.HP = fibo(theKnight.HP);
			if (count6 == 3) {
				miniknight = false;
				theKnight.HP *= 5;
			}
			if (count7 == 3) {
				frogknight = false;
				theKnight.level = oldlevel;
			}
			if (countodin == 3) {
				odinsecond = true;
				odin = false;
			}
			break;
		}
		case 13:
		{
			if (odin == true || myth == true || paladin == true)
				theKnight.HP = theKnight.HP;
			else if (theKnight.HP < 51)
				theKnight.HP = 1;
			else if (theKnight.HP >= 51)
				theKnight.HP -= 50;
			if (count6 == 3) {
				miniknight = false;
				theKnight.HP *= 5;
			}
			if (count7 == 3) {
				frogknight = false;
				theKnight.level = oldlevel;
			}
			if (countodin == 3) {
				odinsecond = true;
				odin = false;
			}
			break;
		}
		case 14:
		{
			maxHP += 50;
			if (maxHP > 999)
				maxHP = 999;
			theKnight.HP = maxHP;
			if (count6 == 3) {
				miniknight = false;
				theKnight.HP *= 5;
			}
			if (count7 == 3) {
				frogknight = false;
				theKnight.level = oldlevel;
			}
			if (countodin == 3) {
				odinsecond = true;
				odin = false;
			}
			break;
		}
		case 15:
		{
			theKnight.remedy++;
			if (count6 == 3) {
				miniknight = false;
				theKnight.HP *= 5;
			}
			if (count7 == 3) {
				frogknight = false;
				theKnight.level = oldlevel;
			}
			if (countodin == 3) {
				odinsecond = true;
				odin = false;
			}
			break;
		}
		case 16:
		{
			theKnight.maidenkiss++;
			if (count6 == 3) {
				miniknight = false;
				theKnight.HP *= 5;
			}
			if (count7 == 3) {
				frogknight = false;
				theKnight.level = oldlevel;
			}
			if (countodin == 3) {
				odinsecond = true;
				odin = false;
			}
			break;
		}
		case 17:
		{
			theKnight.phoenixdown++;
			if (count6 == 3) {
				miniknight = false;
				theKnight.HP *= 5;
			}
			if (count7 == 3) {
				frogknight = false;
				theKnight.level = oldlevel;
			}
			if (countodin == 3) {
				odinsecond = true;
				odin = false;
			}
			break;
		}
		case 18:
		{
			miniknight = false;
			theKnight.level++;
			if (frogknight == true) {
				frogknight = false;
				theKnight.level = oldlevel;
				theKnight.level++;
			}
			theKnight.HP = maxHP;
			if (countodin == 3) {
				odinsecond = true;
				odin = false;
			}
			break;
		}
		case 19:
		{
			if (theKnight.level >= 7 || odin == true) {
				theKnight.HP = theKnight.HP;
				if (count6 == 3) {
					miniknight = false;
					theKnight.HP *= 5;
				}
				if (countodin == 3) {
					odinsecond = true;
					odin = false;
				}
			}
			else {
				result = -1;
				goto labelend;
			}
			break;
		}
		case 20:
		{
			if (i == 0) {
				result = theKnight.HP + theKnight.level + theKnight.maidenkiss + theKnight.phoenixdown + theKnight.remedy;
				goto labelend;
			}
			if (count6 == 3) {
				miniknight = false;
				theKnight.HP *= 5;
			}
			if (count7 == 3) {
				frogknight = false;
				theKnight.level = oldlevel;
			}
			if (countodin == 3) {
				odinsecond = true;
				odin = false;
			}
			for (int j = i - 1; j >= 0; j--) {
				if (lancelot == true) {
					checklancelot = checkoddeven(theKnight.level);
					if (checklancelot == true) {
						lanceloteven = false;
						lancelotodd = true;
					}
					else {
						lancelotodd = false;
						lanceloteven = true;
					}
				}
				count6++;
				count7++;
				countodin++;
				i++;
				b = (i + 1) % 10;
				level = (i + 1) > 6 ? (b > 5 ? b : 5) : b;
				int theEvent = arrEvent[j];
				//cout << theEvent << " ";
				switch (theEvent) {
				case 0:
				{
					result = theKnight.HP + theKnight.level + theKnight.maidenkiss + theKnight.phoenixdown + theKnight.remedy;
					goto labelend;
					break;
				}
				case 1:
				{
					damage = 1 * level * 10;
					if (theKnight.level < level && myth == false && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
						theKnight.HP -= damage;
					else if (excafake == true && myth == false && odin == false && lancelotodd == false)
						theKnight.HP -= damage;
					else if (excafake == true && myth == true && odin == false && lancelotodd == false)
						theKnight.HP = theKnight.HP;
					else if (theKnight.level < level && myth == true && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
						theKnight.HP = theKnight.HP;
					else if (theKnight.level == level && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
						theKnight.HP == theKnight.HP;
					else if (theKnight.level > level || exca == true || odin == true || arthur == true || paladin == true || lancelotodd == true)
						theKnight.level++;
					if (count6 == 3) {
						miniknight = false;
						theKnight.HP *= 5;
					}
					if (count7 == 3) {
						frogknight = false;
						theKnight.level = oldlevel;
					}
					if (countodin == 3) {
						odinsecond = true;
						odin = false;
					}
					break;
				}
				case 2:
				{
					damage = 1.5 * level * 10;
					if (theKnight.level < level && myth == false && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
						theKnight.HP -= damage;
					else if (excafake == true && myth == false && odin == false && lancelotodd == false)
						theKnight.HP -= damage;
					else if (excafake == true && myth == true && odin == false && lancelotodd == false)
						theKnight.HP = theKnight.HP;
					else if (theKnight.level < level && myth == true && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
						theKnight.HP = theKnight.HP;
					else if (theKnight.level == level && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
						theKnight.HP == theKnight.HP;
					else if (theKnight.level > level || exca == true || odin == true || arthur == true || paladin == true || lancelotodd == true)
						theKnight.level++;
					if (count6 == 3) {
						miniknight = false;
						theKnight.HP *= 5;
					}
					if (count7 == 3) {
						frogknight = false;
						theKnight.level = oldlevel;
					}
					if (countodin == 3) {
						odinsecond = true;
						odin = false;
					}
					break;
				}
				case 3:
				{
					damage = 4.5 * level * 10;
					if (theKnight.level < level && myth == false && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
						theKnight.HP -= damage;
					else if (excafake == true && myth == false && odin == false && lancelotodd == false)
						theKnight.HP -= damage;
					else if (excafake == true && myth == true && odin == false && lancelotodd == false)
						theKnight.HP = theKnight.HP;
					else if (theKnight.level < level && myth == true && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
						theKnight.HP = theKnight.HP;
					else if (theKnight.level == level && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
						theKnight.HP == theKnight.HP;
					else if (theKnight.level > level || exca == true || odin == true || arthur == true || paladin == true || lancelotodd == true)
						theKnight.level++;
					if (count6 == 3) {
						miniknight = false;
						theKnight.HP *= 5;
					}
					if (count7 == 3) {
						frogknight = false;
						theKnight.level = oldlevel;
					}
					if (countodin == 3) {
						odinsecond = true;
						odin = false;
					}
					break;
				}
				case 4:
				{
					damage = 6.5 * level * 10;
					if (theKnight.level < level && myth == false && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
						theKnight.HP -= damage;
					else if (excafake == true && myth == false && odin == false && lancelotodd == false)
						theKnight.HP -= damage;
					else if (excafake == true && myth == true && odin == false && lancelotodd == false)
						theKnight.HP = theKnight.HP;
					else if (theKnight.level < level && myth == true && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
						theKnight.HP = theKnight.HP;
					else if (theKnight.level == level && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
						theKnight.HP == theKnight.HP;
					else if (theKnight.level > level || exca == true || odin == true || arthur == true || paladin == true || lancelotodd == true)
						theKnight.level++;
					if (count6 == 3) {
						miniknight = false;
						theKnight.HP *= 5;
					}
					if (count7 == 3) {
						frogknight = false;
						theKnight.level = oldlevel;
					}
					if (countodin == 3) {
						odinsecond = true;
						odin = false;
					}
					break;
				}
				case 5:
				{
					damage = 8.5 * level * 10;
					if (theKnight.level < level && myth == false && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
						theKnight.HP -= damage;
					else if (excafake == true && myth == false && odin == false && lancelotodd == false)
						theKnight.HP -= damage;
					else if (excafake == true && myth == true && odin == false && lancelotodd == false)
						theKnight.HP = theKnight.HP;
					else if (theKnight.level < level && myth == true && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
						theKnight.HP = theKnight.HP;
					else if (theKnight.level == level && exca == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
						theKnight.HP == theKnight.HP;
					else if (theKnight.level > level || exca == true || odin == true || arthur == true || paladin == true || lancelotodd == true)
						theKnight.level++;
					if (count6 == 3) {
						miniknight = false;
						theKnight.HP *= 5;
					}
					if (count7 == 3) {
						frogknight = false;
						theKnight.level = oldlevel;
					}
					if (countodin == 3) {
						odinsecond = true;
						odin = false;
					}
					break;
				}
				case 8:
				{
					exca = true;
					excafake = false;
					if (count6 == 3) {
						miniknight = false;
						theKnight.HP *= 5;
						count6 = 10;
					}
					if (count7 == 3) {
						frogknight = false;
						theKnight.level = oldlevel;
						count7 = 10;
					}
					if (countodin == 3) {
						odinsecond = true;
						odin = false;
					}
					break;
				}
				case 9:
				{
					myth = true;
					if (count6 == 3) {
						miniknight = false;
						theKnight.HP *= 5;
						count6 = 10;
					}
					if (count7 == 3) {
						frogknight = false;
						theKnight.level = oldlevel;
						count7 = 10;
					}
					if (countodin == 3) {
						odinsecond = true;
						odin = false;
					}
					break;
				}
				case 10:
				{
					if (theKnight.level >= 5 || odin == true || arthur == true || paladin == true || lancelotodd == true)
						theKnight.HP = theKnight.HP;
					else {
						exca = false;
						excafake = true;
					}
					if (count6 == 3) {
						miniknight = false;
						theKnight.HP *= 5;
						count6 = 10;
					}
					if (count7 == 3) {
						frogknight = false;
						theKnight.level = oldlevel;
						count7 = 10;
					}
					if (countodin == 3) {
						odinsecond = true;
						odin = false;
					}
					break;
				}
				case 6:
				{
						if (miniknight == true || frogknight == true)
							theKnight.HP = theKnight.HP;
						else if (theKnight.level == level && excafake == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
							theKnight.HP = theKnight.HP;
						else if (theKnight.level > level && excafake == false)
							theKnight.level += 2;
						else if (odin == true)
							theKnight.level += 2;
						else if (arthur == true)
							theKnight.level += 2;
						else if (paladin == true)
							theKnight.level += 2;
						else if (lancelotodd == true)
							theKnight.level += 2;
						else if (theKnight.level < level && miniknight == false && frogknight == false) {
							count6 = 0;
							miniknight = true;
							if (myth == false) {
								if (theKnight.HP < 5)
									theKnight.HP = 1;
								else
									theKnight.HP /= 5;
							}
							else if (myth == true)
								theKnight.HP = theKnight.HP;
						}
						else if (excafake == true && miniknight == false && frogknight == false) {
							count6 = 0;
							miniknight = true;
							if (myth == false) {
								if (theKnight.HP < 5)
									theKnight.HP = 1;
								else
									theKnight.HP /= 5;
							}
							else if (myth == true)
								theKnight.HP = theKnight.HP;
						}
						if (count6 == 3) {
							theKnight.HP *= 5;
							miniknight = false;
						}
						if (count7 == 3) {
							frogknight = false;
							theKnight.level = oldlevel;
						}
						if (countodin == 3) {
							odinsecond = true;
							odin = false;
						}
						break;
				}
				case 7:
				{
					if (miniknight == true || frogknight == true)
						theKnight.HP = theKnight.HP;
					else if (theKnight.level == level && excafake == false && odin == false && arthur == false && paladin == false && lancelotodd == false)
						theKnight.HP = theKnight.HP;
					else if (theKnight.level > level && excafake == false)
						theKnight.level += 2;
					else if (odin == true)
						theKnight.level += 2;
					else if (arthur == true)
						theKnight.level += 2;
					else if (paladin == true)
						theKnight.level += 2;
					else if (lancelotodd == true)
						theKnight.level += 2;
					else if (theKnight.level < level && frogknight == false && miniknight == false) {
						frogknight = true;
						count7 = 0;
						oldlevel = theKnight.level;
						theKnight.level = 1;
					}
					else if (excafake == true && frogknight == false && miniknight == false) {
						frogknight = true;
						count7 = 0;
						oldlevel = theKnight.level;
						theKnight.level = 1;
					}
					if (count6 == 3) {
						theKnight.HP *= 5;
						miniknight = false;
					}
					if (count7 == 3) {
						frogknight = false;
						theKnight.level = oldlevel;
					}
					if (countodin == 3) {
						odinsecond = true;
						odin = false;
					}
					break;
				}
				case 11:
				{
					theKnight.HP += 50;
					if (count6 == 3) {
						miniknight = false;
						theKnight.HP *= 5;
						count6 = 10;
					}
					if (count7 == 3) {
						frogknight = false;
						theKnight.level = oldlevel;
						count7 = 10;
					}
					if (countodin == 3) {
						odinsecond = true;
						odin = false;
					}
					break;
				}
				case 12:
				{
					theKnight.HP = fibo(theKnight.HP);
					if (count6 == 3) {
						miniknight = false;
						theKnight.HP *= 5;
						count6 = 10;
					}
					if (count7 == 3) {
						frogknight = false;
						theKnight.level = oldlevel;
						count7 = 10;
					}
					if (countodin == 3) {
						odinsecond = true;
						odin = false;
					}
					break;
				}
				case 13:
				{
					if (odin == true || myth == true || paladin == true)
						theKnight.HP = theKnight.HP;
					else if (theKnight.HP < 51)
						theKnight.HP = 1;
					else if (theKnight.HP >= 51)
						theKnight.HP -= 50;
					if (count6 == 3) {
						miniknight = false;
						theKnight.HP *= 5;
					}
					if (count7 == 3) {
						frogknight = false;
						theKnight.level = oldlevel;
					}
					if (countodin == 3) {
						odinsecond = true;
						odin = false;
					}
					break;
				}
				case 14:
				{
					maxHP += 50;
					if (maxHP > 999)
						maxHP = 999;
					theKnight.HP = maxHP;
					if (count6 == 3) {
						miniknight = false;
						theKnight.HP *= 5;
						count6 = 10;
					}
					if (count7 == 3) {
						frogknight = false;
						theKnight.level = oldlevel;
						count7 = 10;
					}
					if (countodin == 3) {
						odinsecond = true;
						odin = false;
					}
					break;
				}
				case 15:
				{
					theKnight.remedy++;
					if (count6 == 3) {
						miniknight = false;
						theKnight.HP *= 5;
						count6 = 10;
					}
					if (count7 == 3) {
						frogknight = false;
						theKnight.level = oldlevel;
						count7 = 10;
					}
					if (countodin == 3) {
						odinsecond = true;
						odin = false;
					}
					break;
				}
				case 16:
				{
					theKnight.maidenkiss++;
					if (count6 == 3) {
						miniknight = false;
						theKnight.HP *= 5;
						count6 = 10;
					}
					if (count7 == 3) {
						frogknight = false;
						theKnight.level = oldlevel;
						count7 = 10;
					}
					if (countodin == 3) {
						odinsecond = true;
						odin = false;
					}
					break;
				}
				case 17:
				{
					theKnight.phoenixdown++;
					if (count6 == 3) {
						miniknight = false;
						theKnight.HP *= 5;
						count6 = 10;
					}
					if (count7 == 3) {
						frogknight = false;
						theKnight.level = oldlevel;
						count7 = 10;
					}
					if (countodin == 3) {
						odinsecond = true;
						odin = false;
					}
					break;
				}
				case 18:
				{
					miniknight = false;
					theKnight.level++;
					if (frogknight == true) {
						frogknight = false;
						theKnight.level = oldlevel;
						theKnight.level++;
					}
					theKnight.HP = maxHP;
					if (countodin == 3) {
						odinsecond = true;
						odin = false;
					}
					break;
				}
				case 19:
				{
					if (theKnight.level >= 7 || odin == true) {
						theKnight.HP = theKnight.HP;
						if (count6 == 3) {
							miniknight = false;
							theKnight.HP *= 5;
						}
						if (countodin == 3) {
							odinsecond = true;
							odin = false;
						}
					}
					else {
						result = -1;
						goto labelend;
					}
					break;
				}
				case 21:
				{
					result = theKnight.HP + theKnight.level + theKnight.maidenkiss + theKnight.phoenixdown + theKnight.remedy;
					goto labelend;
					break;
				}
				case 22:
				{
					if (odin == true) {
						theKnight.HP = theKnight.HP;
					}
					else {
						countodin = 0;
						odin = true;
						if (odinsecond == true)
							odin = false;
					}
					if (count6 == 3) {
						miniknight = false;
						theKnight.HP *= 5;
						count6 = 10;
					}
					if (count7 == 3) {
						frogknight = false;
						theKnight.level = oldlevel;
						count7 = 10;
					}
					if (countodin == 3) {
						odinsecond = true;
						odin = false;
					}
					break;
				}
				case 99:
				{
					if (theKnight.level == 10 && excafake == false)
						theKnight.level = 10;
					else if (arthur == true || odin == true || lancelot == true)
						theKnight.level = 10;
					else if (paladin == true && theKnight.level >= 8)
						theKnight.level = 10;
					else {
						result = -1;
						goto labelend;
					}
					break;
				}
				}
				if (theKnight.phoenixdown >= 1 && theKnight.HP <= 0) {
					theKnight.HP = maxHP;
					theKnight.phoenixdown--;
					miniknight = false;
					frogknight = false;
					count6 = 5;
					count7 = 5;
					theKnight.level = oldlevel;
				}
				if (theKnight.maidenkiss >= 1 && frogknight == true) {
					theKnight.maidenkiss--;
					frogknight = false;
					count7 = 5;
					theKnight.level = oldlevel;
				}
				if (theKnight.remedy >= 1 && miniknight == true) {
					theKnight.remedy--;
					miniknight = false;
					count6 = 5;
					theKnight.HP *= 5;
				}
				if (theKnight.level > 10)
					theKnight.level = 10;
				if (theKnight.HP > maxHP)
					theKnight.HP = maxHP;
				if (theKnight.maidenkiss > 99)
					theKnight.maidenkiss = 99;
				if (theKnight.remedy > 99)
					theKnight.remedy = 99;
				if (theKnight.phoenixdown > 99)
					theKnight.phoenixdown = 99;
				if (theKnight.HP <= 0) {
					result = -1;
					goto labelend;
				}
				if (j == 0) {
					result = theKnight.HP + theKnight.level + theKnight.maidenkiss + theKnight.phoenixdown + theKnight.remedy;
					goto labelend;
				}
				result = theKnight.HP + theKnight.level + theKnight.maidenkiss + theKnight.phoenixdown + theKnight.remedy;
			}
			break;
		}
		case 21:
		{
			if (odin == true) {
				odin = false;
				odinsecond = true;
			}
			for (int k = i + 1; k < (i + 4); k++) {
				//cout << arrEvent[k] << " ";
				if (arrEvent[k] == 20 || arrEvent[k] == 0) {
					result = theKnight.HP + theKnight.level + theKnight.maidenkiss + theKnight.phoenixdown + theKnight.remedy;
					goto labelend;
				}
			}
			i += 3;
			break;
		}
		case 22:
		{
			if (odin == true) {
				theKnight.HP = theKnight.HP;
			}
			else {
				countodin = 0;
				odin = true;
				if (odinsecond == true)
					odin = false;
			}
			if (count6 == 3) {
				miniknight = false;
				theKnight.HP *= 5;
				count6 = 10;
			}
			if (count7 == 3) {
				frogknight = false;
				theKnight.level = oldlevel;
				count7 = 10;
			}
			if (countodin == 3) {
				odinsecond = true;
				odin = false;
			}
			break;
		}
		case 99:
		{
			if (theKnight.level == 10 && excafake == false)
				theKnight.level = 10;
			else if (arthur == true || odin == true || lancelot == true)
				theKnight.level = 10;
			else if (paladin == true && theKnight.level >= 8)
				theKnight.level = 10;
			else {
				result = -1;
				goto labelend;
			}
				break;
		}
		}
		levelknight = theKnight.level;
		if (theKnight.phoenixdown >= 1 && theKnight.HP <= 0) {
			theKnight.HP = maxHP;
			theKnight.phoenixdown--;
			miniknight = false;
			count6 = 5;
			count7 = 5;
			if (frogknight == true) {
				theKnight.level = oldlevel;
				frogknight = false;
			}
			else
				theKnight.level = levelknight;
		}
		if (theKnight.maidenkiss >= 1 && frogknight == true) {
			theKnight.maidenkiss--;
			frogknight = false;
			count7 = 5;
			theKnight.level = oldlevel;
		}
		if (theKnight.remedy >= 1 && miniknight == true) {
			theKnight.remedy--;
			miniknight = false;
			count6 = 5;
			theKnight.HP *= 5;
		}
		if (theKnight.level > 10)
			theKnight.level = 10;
		if (theKnight.HP > maxHP)
			theKnight.HP = maxHP;
		if (theKnight.maidenkiss > 99)
			theKnight.maidenkiss = 99;
		if (theKnight.remedy > 99)
			theKnight.remedy = 99;
		if (theKnight.phoenixdown > 99)
			theKnight.phoenixdown = 99;
		if (theKnight.HP <= 0) {
			result = -1;
			goto labelend;
		}
		result = theKnight.HP + theKnight.level + theKnight.maidenkiss + theKnight.phoenixdown + theKnight.remedy;
	}
	
labelend: 
	//cout << "\n" << "\n";
	//cout << theKnight.HP << ' ' << theKnight.level << ' ' << theKnight.remedy << ' ' << theKnight.maidenkiss << ' ' << theKnight.phoenixdown << endl;
	//cout << "Ket qua: ";
	nOut = &result;
	display(nOut);
	return 0;
}

