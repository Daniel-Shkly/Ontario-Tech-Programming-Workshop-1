//============================================================================
// Name        : CSCI1060U_ass10.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description : Lab 10
//============================================================================

#include <iostream>
using namespace std;

class Stack {
	private:
		string stack;

	public:
		//Constructor
		Stack() {
			stack = "";
		}

		//Getter
		string getStack() {
			return stack;
		}

		//Push into stack and Pop from stack
		void Push (char c) {
			stack = c + stack;
		}
		char Pop() {
			char popped = stack[0];

			string new_stack = "";
			for (int i = 1; i < stack.length(); i++) {
				new_stack += stack[i];
			}
			stack = new_stack;

			return popped;
		}
};

bool isPalindrome(string s) {
	string check = s; //preserve original string to check the reversed against
	string reversed = "";
	Stack stack;

	//push string into stack
	for (int i = 0; i < s.length(); i++) {
		stack.Push(s[i]);
	}

	//pop out and add each element to a new string to get the reverse of the original
	for (int i = 0; i < s.length(); i++) {
		reversed += stack.Pop();
	}

	//check if the reversed and orignal are the same and return True if they are
	if (reversed == check) {
		return true;
	}

	return false;
}

int main() {

	//get a string to be checked
	string input;
	cout << "Enter a potential palindrome: ";
	cin >> input;

	//check and display if the input is a palindrome
	bool is_palindrome = isPalindrome(input);
	if (is_palindrome == true){
		cout << "\nYou entered a palindrome!";
	}
	else {
		cout << "\nThat was not a palindrome.";
	}

	return 0;
}
