//============================================================================
// Name        : CSCI1060U_ass2.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description : CSCI 1060U Lab 2 Part 1
//============================================================================


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int* create_key(int* array, int digit_range) {
	srand(time(NULL));
	int length = sizeof(array)/sizeof(*array);
	for (int i = 0; i <= length; i++) {
		array[i] = rand() % digit_range + 1;
	}
	return array;
}

int guess(int x) {
	int g;
	cout << "Guess a number between 1 and " << x << endl;
	cin >> g;
	return g;
}

bool search(int array[], int array_size, int to_find) {
	for (int i = 0; i <= array_size; i++) {
		if (array[i] == to_find) {
			return true;
		}
	}
	return false;
}

int main() {
	int range_digits = 5;
	int num_digits = 3;
	int tries = 0;
	int correct = 0;
	int attempt [num_digits] = {};
	string play_again = "";

	int key[num_digits];
	create_key(key, range_digits);

	while (tries < 5 && correct != num_digits) {
		int digit = 1;
		correct = 0;
		//get the guesses
		for (int i = 0; i < num_digits; i++) {
			attempt[i] = guess(range_digits);
			cout << "Guess " << digit << ": " << attempt[i] << endl;
			digit++;
		}
		cout << "Result:" << endl;
		//check each guess against the key
		for (int i = 0; i < num_digits; i++) {
			if (attempt[i] == key[i]) {
				cout << attempt[i] << " is in the right place!" << endl;
				correct++;
			}
			else if (search(key,num_digits,attempt[i]) == true) {
				cout << attempt[i] << " is there but not in that place!" << endl;
			}
			else {
				cout << attempt[i] << " is not part of the key!" << endl;
			}
		}
		tries++;
	}


	if (correct == num_digits) {
		cout << "That's right! You guessed the key in " << tries << " tries" << endl;
		cout << "Would you like to play again? Y/N";
		cin >> play_again;
		if (play_again == "Y" || play_again == "y") {
			main();
		}
	}
	else {
		cout << "Would you like to play again? Y/N";
		cin >> play_again;
		if (play_again == "Y" || play_again == "y") {
			main();
		}
	}

	return 0;
}

