//============================================================================
// Name        : CSCI_ass3.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description : CSCI 1060U Lab 3 Part 1
//============================================================================

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;


int main() {
	int day_grid [35] = {};
	int day = 1;
	for (int i = 0; i < 31; i++) {
		day_grid[i] = day;
		day++;
	}
	cout << "January 2022" << endl;
	cout << setw(3) << "  S" << setw(3) <<  "  M" << setw(3) <<  " Tu" << setw(3) <<  "  W" << setw(3) <<  " Th" << setw(3) <<  "  F" << setw(3) <<  "  S" << endl;
	for (int i = 0; i < 35; i++) {
		if (day_grid[i] == 0){
			cout << setw(3) << " ";
		}
		else {
			cout << setw(3) << day_grid[i];
		}

		if ((i+1)%7 == 0) {
			cout << endl;
		}
	}
	cout << endl;



	return 0;
}
