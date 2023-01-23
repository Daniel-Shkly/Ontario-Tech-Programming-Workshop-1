//============================================================================
// Name        : CSCI1060U_ass4.cpp
// Author      : Daniel Shklyarman
// Description : Lab 4 Part 1
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream labRead;
	char ch;

	labRead.open("lab4.txt");

	while (labRead >> noskipws  >> ch) {
		cout << ch;
	}

	labRead.close();

	return 0;
}
