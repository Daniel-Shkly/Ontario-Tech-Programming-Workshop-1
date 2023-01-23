//============================================================================
// Name        : lab06.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description : Lab 6
//============================================================================

#include <iostream>

using namespace std;

const int kNumberOfStudents = 10;

//function to print the marks of the students
void displayMarks(int array[kNumberOfStudents]) {
	cout << "\nMarks for all the students:";
	cout << "\n***************************\n";

	for (int i = 0; i < kNumberOfStudents; i++) {
		cout << "Mark for student " << i << ": " << array[i] <<  "\n";
	}
}

//literally the same as displayMarks just initial text changed to show
//that the inputarray is presumably sorted in decreasing order
void displaySortedMarks(int array[kNumberOfStudents]) {
	cout << "\nMarks for all the students, sorted in decreasing order:";
	cout << "\n***************************\n";

	for (int i = 0; i < kNumberOfStudents; i++) {
		cout << "Mark for student " << i << ": " << array[i] <<  "\n";
	}
}

//function to sort and array of size equal to the number of students
int bubbleSort(int array[kNumberOfStudents]) {

	//bubble sort loop, will keep going until nested
	//for loop doesn't have to perform any swaps
	bool sorted;
	for (int i = 0; i < kNumberOfStudents - 1; i++) {
		sorted = true;
		for (int j = 0; j < kNumberOfStudents - i - 1; j++) {
			if (array[j] < array[j+1]) {
				swap(array[j], array[j + 1]);
				sorted = false;
			}

		}
		if (sorted == true) {
			break;
		}
	}

	return array[kNumberOfStudents];
}

int main() {

	int marks[kNumberOfStudents] = {}; //array to store student marks

	//loop to get the marks of the students and store them in an array
	for (int i = 0; i < kNumberOfStudents; i++) {
		cout << "Input the mark of student " << i << " \n";
		cin >> marks[i];
	}

	displayMarks(marks); //print all marks as originally entered

	bubbleSort(marks); //sort the list of marks

	displaySortedMarks(marks); //display the sorted list of marks

	cout << "\nMarks for students who passed, in decreasing order:";
	cout << "\n***************************\n";

	//loop that takes the sorted array and prints all marks >=50 and
	//gets the number of those marks to get the number of students that passed
	int i = 0;
	int pass = 0;
	while (marks[i] >= 50 && i < kNumberOfStudents) {
		cout << "Mark for student " << i << ": " << marks[i] <<  "\n";
		i++;
		pass++;
	}

	int fail = kNumberOfStudents - pass;

	cout << "\nClass Stats: \n***************************\n";
	cout << "Number of students who passed the course: " << pass << "\n";
	cout << "Number of students who failed the course: " << fail;

	return 0;
}
