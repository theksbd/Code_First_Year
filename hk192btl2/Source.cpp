#ifndef _definition_h_
#include "defs.h"
#define _definition_h_
#endif

bool checkfriendlynumber(int x, int y) {
	if (x == 0 || y == 0) return 0;
	else {
		int sumX = 0, sumY = 0;
		for (int i = 1; i <= x; i++)
			if (x % i == 0) sumX += i;
		for (int j = 1; j <= y; j++)
			if (y % j == 0) sumY += j;
		float numX = (float)sumX / (float)x,
			numY = (float)sumY / (float)y;
		if (numX == numY) return 1;
		else return 0;
	}
}
bool checkprimenumber(int n) {
	int count = 0;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) count++;
	}
	if (count == 0) return 1;
	else return 0;
}
bool checkdragonnumber(int n) {
	if (n == 888) return 0;
	else {
		int count = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) {
				int k = n - i - j;
				if (i * i + j * j == k * k) {
					count++;
				}
			}
		}
		if (count == 0) return 0;
		else return 1;
	}
}
bool eternallove(bool athur, bool lan, bool gui, bool pala, bool exc, bool spear, bool hair) {
	if (spear == true && hair == true && exc == false) return 1;
	else if (athur == true && hair == true) return 1;
	else if (lan == true && hair == true) return 1;
	else if (gui == true && spear == true) return 1;
	else return 0;
}

report* walkthrough(knight& theKnight, castle arrCastle[], int nCastle, int mode, int nPetal)
{
	report* pReturn;
	int bFlag;
	//fighting for the existence of mankind here
	bFlag = nPetal;
	int nwin = 0, nlose = 0, level, b;
	int maxHP = theKnight.HP;
	bool special = false, exca = false, paladinshield = false, lancelotspear = false, guihair = false;
	float basedamage;
	int count6 = 100, countlion = 100, ninameet = 100, odinmeet = 100, countodin = 100;
	bool poisonedknight = false, friendlyknight = false, lionheartsword = false, odin = false, omegadie = false;
	bool odindie = false, myth = false, shakama = false, arthur = false, lancelot = false, guinevere = false;
	bool paladin = checkprimenumber(theKnight.HP), dragon = checkdragonnumber(theKnight.HP);
	int k = 0, min = hash(95), mid = hash(95), max = hash(95);
	int p = hash(95), l = hash(96), g = hash(97);

	if (theKnight.HP == 999) arthur = true;
	else if (theKnight.HP == 888) {
		lancelot = true;
		lancelotspear = true;
		k = 1;
		if (p < g) l = p - 1;
		else l = g - 1;
	}
	else if (theKnight.HP == 777) {
		guinevere = true;
		guihair = true;
		k = 1;
		if (p < l) g = p - 1;
		else g = l - 1;
	}
	else if (paladin == true) {
		paladinshield = true;
		k = 1;
		if (l < g) p = l - 1;
		else p = g - 1;
	}

	int arr[3] = { p, l, g };
	for (int i = 0; i < 3; i++) {
		if (min > arr[i]) min = arr[i];
	}
	for (int i = 0; i < 3; i++) {
		if (max < arr[i]) max = arr[i];
	}
	for (int i = 0; i < 3; i++) {
		mid = arr[i];
		if (mid == min || mid == max) continue;
		else break;
	}
	arr[0] = min;
	arr[1] = mid;
	arr[2] = max;

	for (int i = 0; i < nCastle; i++) {

		for (int j = 0; j < arrCastle[i].nEvent; j++) {
			if (mode == 1 && arrCastle[i].arrEvent[j] >= 95 && arrCastle[i].arrEvent[j] <= 97) {
				switch (arrCastle[i].arrEvent[j]) {
				case 95:
					if (arr[k] == hash(95)) {
						paladinshield = true;
						k++;
					}
					break;
				case 96:
					if (arr[k] == hash(96)) {
						lancelotspear = true;
						k++;
					}
					break;
				case 97:
					if (arr[k] == hash(97)) {
						guihair = true;
						k++;
					}
					break;
				}
			}
			else if (mode == 0 && arrCastle[i].arrEvent[j] >= 95 && arrCastle[i].arrEvent[j] <= 97) {
				switch (arrCastle[i].arrEvent[j]) {
				case 95:
					paladinshield = true;
					break;
				case 96:
					lancelotspear = true;
					break;
				case 97:
					guihair = true;
					break;
				}
			}
			bFlag--;
			count6++;
			countlion++;
			countodin++;
			ninameet++;
			odinmeet++;
			bool love = eternallove(arthur, lancelot, guinevere, paladin, exca, lancelotspear, guihair);
			b = (j + 1) % 10;
			level = (j + 1) > 6 ? (b > 5 ? b : 5) : b;
			switch (arrCastle[i].arrEvent[j]) {
			case 99:
				if (exca == true || lionheartsword == true) {
					nwin++;
					special = true;
					if (poisonedknight == true)
						theKnight.HP = theKnight.HP < 3 ? 1 : theKnight.HP / 3;
					goto labelend;
				}
				else {
					nlose++;
					if (myth == true || guinevere == true)
						theKnight.HP = (poisonedknight) ? theKnight.HP / 3 : theKnight.HP;
					else
						theKnight.HP = (poisonedknight) ? (theKnight.HP < 9 ? 1 : theKnight.HP / 9) : (theKnight.HP < 3 ? 1 : theKnight.HP / 3);
				}
					break;
			case 98:
				if (paladinshield == true && lancelotspear == true && guihair == true)
					exca = true;
				if (arthur == true) exca = true;
				break;
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
				switch (arrCastle[i].arrEvent[j]) {
				case 1:
					basedamage = 1;
					break;
				case 2:
					basedamage = 1.5;
					break;
				case 3:
					basedamage = 4.5;
					break;
				case 4:
					basedamage = 6.5;
					break;
				case 5:
					basedamage = 8.5;
					break;
				}
				if (theKnight.level < level && !lionheartsword && !odin && !arthur && !lancelot && !paladin) {
					nlose++;
					if (guinevere == true && arrCastle[i].arrEvent[j] == 2) {
						if (poisonedknight == true) theKnight.HP -= basedamage * level * 10;
					}
					else {
						if (myth == false)
							theKnight.HP = (poisonedknight) ? theKnight.HP - 2 * basedamage * level * 10 : theKnight.HP - basedamage * 10 * level;
						else
							theKnight.HP = (poisonedknight) ? theKnight.HP - basedamage * level * 10 : theKnight.HP;
					}
				}
				else {
					theKnight.gil += basedamage * 100;
					nwin++;
					if (poisonedknight == true)
						theKnight.HP -= basedamage * 10 * level;
				}
				break;
			case 6:
				//std::cout << poisonedknight << std::endl;
				if (poisonedknight == true) break;
				else {
					if (theKnight.level >= level || lionheartsword || odin || arthur || lancelot) {
						if (theKnight.level < 10) {
							theKnight.level++;
							maxHP += 100;
						}
						nwin++;
					}
					else {
						if (paladin == false && dragon == false) {
							count6 = 0;
							poisonedknight = true;
						}
						nlose++;
					}
				}
				break;
			case 7:
				if (theKnight.level >= level || lionheartsword || odin || arthur || lancelot) {
					theKnight.gil *= 2;
					nwin++;
				}
				else {
					nlose++;
					theKnight.gil = (shakama || guinevere) ? theKnight.gil : theKnight.gil / 2;
				}
				break;
			case 8:
				if (ninameet <= 5) break;
				else {
					friendlyknight = checkfriendlynumber(theKnight.HP, theKnight.gil);
					//std::cout << friendlyknight << std::endl;
					if (friendlyknight == false && shakama == false && guinevere == false && paladin == false) {
						ninameet = 0;
						if (theKnight.gil < 50) break;
						else {
							if (poisonedknight == true) {
								theKnight.gil -= 50;
								poisonedknight = false;
							}
							int gil = theKnight.gil;
							if (theKnight.HP < maxHP) {
								for (int gi = 1; gi <= gil; gi++) {
									theKnight.HP++;
									theKnight.gil--;
									if (theKnight.HP == maxHP) break;
								}
							}
						}
					}
					else {
						ninameet = 0;
						poisonedknight = false;
						theKnight.HP = maxHP;
						if (guinevere == true) theKnight.gil += 50;
						if (friendlyknight == true) {
							lionheartsword = true;
							countlion = (paladin) ? 100 : 0;
						}
					}
				}
				break;
			case 9:
				poisonedknight = false;
				theKnight.HP = maxHP;
				bFlag = (shakama) ? 98 : bFlag + 5;
				break;
			case 10:
				theKnight.antidote++;
				if (theKnight.antidote > 99) theKnight.antidote = 99;
				break;
			case 11:
				if (odindie == true) break;
				else {
					if (odinmeet <= 5) break;
					else {
						odin = true;
						countodin = 0;
						odinmeet = 0;
					}
				}
				break;
			case 12:
				poisonedknight = false;
				if (theKnight.level < 10) {
					theKnight.level++;
					maxHP += 100;
				}
				theKnight.HP = maxHP;
				break;
			case 13:
				if (omegadie == true) break;
				else {
					if (theKnight.level == 10 && exca) {
						theKnight.gil = 999;
						omegadie = true;
						nwin++;
					}
					else if (dragon == true && lionheartsword == true) {
						maxHP += (10 - theKnight.level) * 100;
						theKnight.level = 10;
						theKnight.gil = 999;
						omegadie = true;
						nwin++;
					}
					else {
						nlose++;
						theKnight.HP = (myth) ? theKnight.HP : 0;
					}
				}
				break;
			case 14:
				if (dragon == true && odin == true) {
					nwin++;
					myth = true;
				}
				else {
					if (love == true) {
						nwin++;
						myth = true;
						if (odin == true) {
							odindie = true;
							odin = false;
						}
					}
					else if (theKnight.level < level && !lionheartsword) {
						theKnight.HP = (myth) ? theKnight.HP : 0;
						nlose++;
						if (odin == true) {
							odindie = true;
							odin = false;
						}
					}
					else {
						nwin++;
						myth = true;
						if (odin == true) {
							odindie = true;
							odin = false;
						}
					}
				}
				break;
			case 15:
				shakama = true;
				break;
			case 16:
				if (theKnight.level > b || lancelot || dragon) break;
				else j = arrCastle[i].nEvent - 1;
				break;
				}
				if (bFlag == 0 && arthur == false) goto labelend;

				if (count6 == 5) poisonedknight = false;
				if (countlion == 5) lionheartsword = false;
				if (countodin == 5) odin = false;
				if (theKnight.antidote > 0 && poisonedknight == true) {
					theKnight.antidote--;
					poisonedknight = false;
				}
				if (theKnight.level > 10) theKnight.level = 10;
				if (maxHP > 999) maxHP = 999;
				if (theKnight.HP > maxHP) theKnight.HP = maxHP;
				if (theKnight.gil > 999) theKnight.gil = 999;
				if (bFlag > 99) bFlag = 99;
				if (theKnight.HP <= 0) {
					callPhoenix(theKnight, maxHP);
					poisonedknight = false;
				}
			}
			if (theKnight.level < 10) {
				theKnight.level++;
				maxHP += 100;
			}
			if (theKnight.level > 10) theKnight.level = 10;
			if (maxHP > 999) maxHP = 999;
			if (i == nCastle - 1) i = -1;
		}
	

labelend:
	if (bFlag == 0 && special == true) pReturn = new report;
	else pReturn = (bFlag) ? new report : NULL;
	if (pReturn) {
		if (bFlag <= 0 && arthur) bFlag = 0;
		pReturn->nPetal = bFlag;
		pReturn->nWin = nwin;
		pReturn->nLose = nlose;
	}
	return pReturn;
}