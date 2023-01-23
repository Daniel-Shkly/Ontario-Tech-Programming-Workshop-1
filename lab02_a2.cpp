//============================================================================
// Name        : CSCI1060U_ass2.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description : CSCI 1060U Lab 2 Part 2
//============================================================================


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//function for the computer to generate a random key given an array and a range for each member of the array to be in
int* create_key(int* array, int digit_range) {
	srand(time(NULL));
	int length = sizeof(array)/sizeof(*array);
	for (int i = 0; i <= length; i++) {
		array[i] = rand() % digit_range + 1;
	}
	return array;
}

//function to get user's guess
int guess(int x) {
	int g;
	cout << "Guess a number between 1 and " << x << endl;
	cin >> g;
	return g;
}

//function to search through an array of integers and determine if a given integer is part of it
bool search(int array[], int array_size, int to_find) {
	for (int i = 0; i <= array_size; i++) {
		if (array[i] == to_find) {
			return true;
		}
	}
	return false;
}

int main() {
	int range_digits = 5; //determines what each digit of the key can be
	int num_digits = 3; //determines how long the key is
	int tries = 0; //try counter, set to 0 at start so that it starts at 0 at the beginning of every round
	int pcorrect;
	int ccorrect;
	int pguess [num_digits]; //initialize an array to hold the player's guess
	string play_again = "";
	int cguess [num_digits]; //initialize an array to hold the computer's guess

	//generate the computer's key
	int ckey[num_digits];
	create_key(ckey, range_digits);

	//generate the player's key
	int pkey[num_digits];
	for (int i = 0; i < num_digits; i++) {
		int input;
		cout << "enter the a digit from 1-" << range_digits << endl;
		cin >> input;
		pkey[i] = input;
	}

	while (tries < 5 && pcorrect != num_digits && ccorrect != num_digits) {

		//set correctness counters to 0 at the beginning of each try
		pcorrect = 0;
		ccorrect = 0;

		//get the  player guess
		for (int i = 0; i < num_digits; i++) {
			pguess[i] = guess(range_digits);
			cout << "Guess " << i+1 << ": " << pguess[i] << endl;
		}

		//get the computer guess
		create_key(cguess, range_digits);

		cout << "Result:" << endl;

		//iterate across the length of the computer's key for each of the player's guesses and print out if the guess was right, wrong, or right but in the wrong place
		for (int i = 0; i < num_digits; i++) {
			if (pguess[i] == ckey[i]) {
				cout << pguess[i] << " is in the right place!" << endl;
				pcorrect++; //update player correctness counter track how many digits the player got right
			}
			else if (search(ckey,num_digits,pguess[i]) == true) {
				cout << pguess[i] << " is there but not in that place!" << endl;
			}
			else {
				cout << pguess[i] << " is not part of the key!" << endl;
			}
		}

		//iterate across the length of the player's key
		for (int i = 0; i < num_digits; i++) {
			if (cguess[i] == pkey[i]) {
				ccorrect++; //update computer correctness counter track how many digits the computer got right
			}
		}

		//print out the computer's guess
		cout << "The computer guessed ";
		for (int i = 0; i < num_digits; i++) {
			cout << cguess[i] << " ";
		}
		cout << endl;

		tries++; //increase the try counter so that loop knows when to end
	}

	//if statements that declare the winner depending on the results and ask if user wants to play again
	if (ccorrect == num_digits && pcorrect == num_digits) {
		cout << "You guessed each other's keys at the same time!";
		cout << "Would you like to play again? Y/N";
		cin >> play_again;
		if (play_again == "Y" || play_again == "y") {
			main();
		}
	}
	else if (ccorrect == num_digits) {
		cout << "The computer wins after " << tries << " tries!" << endl;
		cout << "Would you like to play again? Y/N";
		cin >> play_again;
		if (play_again == "Y" || play_again == "y") {
			main();
		}
	}
	else if (pcorrect == num_digits) {
		cout << "You win after " << tries << " tries!" << endl;
		cout << "Would you like to play again? Y/N";
		cin >> play_again;
		if (play_again == "Y" || play_again == "y") {
			main();
		}
	}
	else {
		cout << "Neither of you guessed correctly!" << endl;
		cout << "Would you like to play again? Y/N";
		cin >> play_again;
		if (play_again == "Y" || play_again == "y") {
			main();
		}

	}

	return 0;
}


