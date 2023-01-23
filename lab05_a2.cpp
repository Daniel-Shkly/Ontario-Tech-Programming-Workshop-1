//============================================================================
// Name        : CSCI1060U_ass5.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description : Lab 5 Assignment 2
//============================================================================

#include <iostream>
#include <string>

using namespace std;

int main() {
	string address;
	string street;
	string city;
	string province;
	string postal_code;
	string country;

	string temp; //just for storing a character in 'address' so that we can append it to one of the other strings

	cout << "Please enter your address in the form Street, City, Province, Postal Code, Country \n";
	getline(cin,address);

	//loops for appending parts of address to their respective string. loop appends to a string until it encounters a comma and then moves on to the next string
	int i = 0;
	cout << i << endl;
	while (int(address[i]) != 44 && i < address.length()) {
		temp = address[i];
		street.append(temp);
		i++;
	}

	i++;

	while (int(address[i]) != 44 && i < address.length()) {
		temp = address[i];
		city.append(temp);
		i++;
	}

	i++;

	while (int(address[i]) != 44 && i < address.length()) {
		temp = address[i];
		province.append(temp);
		i++;
	}

	i++;

	while (int(address[i]) != 44 && i < address.length()) {
		temp = address[i];
		postal_code.append(temp);
		i++;
	}

	i++;

	while (int(address[i]) != 44 && i < address.length()) {
		temp = address[i];
		country.append(temp);
		i++;
	}


	cout << "Address: " << address << "\n";
	cout << "*******************************\n";
	cout << "Street: " << street << "\n";
	cout << "City:" << city << "\n";
	cout << "Province:" << province << "\n";
	cout << "Postal Code:" << postal_code << "\n";
	cout << "Country:" << country << "\n";
}
