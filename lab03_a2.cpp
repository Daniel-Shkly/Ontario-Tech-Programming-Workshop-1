//============================================================================
// Name        : CSCI_ass3.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description : CSCI 1060U Lab 3 Part 2
//============================================================================

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;



void print_month_name(int month) {
	string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	cout << months[month-1] << " ";
}

bool is_leap_year(int year) {
	if (year % 4 == 0 && year % 400 == 0) {
		return true;
	}
	else if (year % 4 == 0 && year % 100 == 0) {
		return false;
	}
	else if (year % 4 == 0) {
		return true;
	}
	else {
		return false;
	}
}

int days_in_month (int month, int year) {
	if (is_leap_year(year) == true) {
		int days[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
		return days[month-1];
	}
	else {
		int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
		return days[month-1];
	}

}

int first_day_of_month (int month, int year) {
	int common_offset[12] = {0,3,3,6,1,4,6,2,5,0,3,5};
	int leap_offset[12] = {0,3,4,0,2,5,0,3,6,1,4,6};
	int week_day;
	if (is_leap_year(year) == false) {
		week_day = (1 + common_offset[month-1] + 5*((year-1)%4) + 4*((year-1)%100) + 6*((year-1)%400))%7;
	}
	else {
		week_day = (1 + leap_offset[month-1] + 5*((year-1)%4) + 4*((year-1)%100) + 6*((year-1)%400))%7;
	}
	return week_day;
}

void print_month(int month, int year) {
	int day_grid [42] = {};
	int day = 1;
	for (int i = first_day_of_month(month, year); i < days_in_month(month, year) + first_day_of_month(month, year); i++) {
		day_grid[i] = day;
		day++;
	}
	print_month_name(month);
	cout << year << endl;
	cout << setw(3) << "  S" << setw(3) <<  "  M" << setw(3) <<  " Tu" << setw(3) <<  "  W" << setw(3) <<  " Th" << setw(3) <<  "  F" << setw(3) <<  "  S" << endl;
	for (int i = 0; i < 42; i++) {
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
}

void print_year(int year) {
	for (int i=0; i <= 11; i++) {
		print_month(i+1, year);
	}
}

int main() {
	string MorY;
	int month;
	int year;
	cout << "Would you like a month or a whole year?" << endl;
	cin >> MorY;
	if (MorY == "M" || MorY == "m") {
		cout << " Enter the number of the month you would like to see: ";
		cin >> month;
		cout << endl << "Enter the year: ";
		cin >> year;
		print_month(month,year);
	}
	else if (MorY == "Y" || MorY == "y") {
			cout << "Enter the year: ";
			cin >> year;
			print_year(year);
		}
	else {
		cout << "I didn't get that";
	}


	return 0;
}
