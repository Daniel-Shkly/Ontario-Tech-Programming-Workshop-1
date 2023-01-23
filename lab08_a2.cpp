//============================================================================
// Name        : CSCI1060U_ass8.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description : Lab 8 Activity 2
//============================================================================

#include <iostream>
using namespace std;

void swap_nums(int *x, int *y) {

	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void swap_pointers(char *&x, char *&y) {

	char *tmp;
	tmp = x;
	x = y;
	y = tmp;
}

int main() {

	int a,b;
	char *s1,*s2;

	a = 3;
	b = 4;

	swap_nums(&a,&b);

	cout << "a is " << a << endl;
	cout << "b is " << b << endl;

	s1 = "I should print second";
	s2 = "I should print first";

	swap_pointers(s1,s2);

	cout << "s1 is " << s1 << endl;
	cout << "s2 is " << s2 << endl;

	return 0;
}
