//============================================================================
// Name        : CSCI1060U_ass1.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

//converts and integer into a string
string to_string_int(int x) {
	stringstream ss;
	ss << x;
	return ss.str();
}

//converts a float into a strong
string to_string_float(float x) {
	stringstream ss;
	ss << x;
	return ss.str();
}

int main() {
	//The applicant part of the code
	string name;
	int byear;
	int year = 2022;
	signed int age;
	float wage;
	string output;
	cout << "Please type the applicant's name ";     	//ask for the applicant's name
	cin >> name; 										//get the applicant's name and store it in 'name'
	cout << "Please type the applicant's birth year ";  //ask for the applicant's birth year
	cin >> byear; 									    //get the applicant's birth year and store it in 'byear'
	age = year - byear; 							    //calculate age by subtracting birth year from current year and storing the result in 'age'
	cout << "Please type the applicant's hourly wage "; //ask for the hourly wage
	cin >> wage; 										//get hourly wage and store it in 'wage'
	output = name + " is " + to_string_int(age) + " years old and requests an hourly wage of $" + to_string_float(wage); //create string with summary of collected information
	cout << output << endl; 							//display a summary of the collected information

	//CSCI 1060U as an Integer
	string course = "CSCI 1060U";

	// get each individual characters ASCII representations
	int ASCII;
	for (unsigned int i = 0; i < course.size(); i++) { //convert each character in the string to its ASCII value and print that value
		ASCII = course[i];
		cout << ASCII << endl;
	}

	return 0;
}
