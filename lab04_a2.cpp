//============================================================================
// Name        : CSCI1060U_ass4.cpp
// Author      : Daniel Shklyarman
// Description : Lab 4 Part 1
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

bool isNumber(char c) {
	int ascii = int(c);
	if (ascii >= 48 && ascii <= 57) {
		return true;
	}
	return false;
}

bool isUpper(char c) {
	int ascii = int(c);
	if (ascii >= 65 && ascii <= 90) {
		return true;
	}
	return false;
}

bool isLower(char c) {
	int ascii = int(c);
	if (ascii >= 97 && ascii <= 122) {
		return true;
	}
	return false;
}

void fileProcessing() {
	ifstream labRead;

	labRead.open("lab4.txt");

	char ch;
	int upper = 0;
	int lower = 0;
	int number = 0;
	int special = 0;

	while (labRead >> ch) {
		if (isNumber(ch) == true) {
			number++;
		}
		else if (isUpper(ch) == true) {
			upper ++;
		}
		else if (isLower(ch) == true) {
			lower++;
		}
		else {
			special++;
		}
	}

	labRead.close();

	cout << "Number of digits: " << number << endl;
	cout << "Number of upper case letters: " << upper << endl;
	cout << "Number of lower case letters: " << lower << endl;

}

int main() {

	fileProcessing();

	return 0;
}
