//============================================================================
// Name        : CSCI1060U_ass8.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description : Lab 8 Activity 1
//============================================================================


//#2
//An int is 4 bytes as can be seen from the fact that the address goes up by 4 when you add 1 to ip. (73fddc -> 73fde0)

//#3
//A double is 8 bytes as can be seen from the fact that the address goes up by 8 when you add 1 to dp. (73fde0 -> 73fde8)

//#4
//If you add 2 to cp, the address would go up by 2 (2*1). (73fddb -> 73fddd)
//If you add 2 to ip, the address would go up by 8 (2*4). (73fddc -> 73fde4)
//If you add 2 to dp, the address goes up by 16 (2*8). (73fde0 -> 73fdf0)


#include <iostream>
using namespace std;


int main( ){

	//Part 3 code
	double d = 6.9;
	double *dp = &d;

	cout << "dp is " << hex << intptr_t(dp) << endl;
	cout << "The character at dp is " << *dp << endl;

	dp = dp+1;
	cout << "dp is " << hex << intptr_t(dp) << endl;

	//Part 2 code
	int i = 3;
	int *ip = &i;

	cout << "ip is " << hex << intptr_t(ip) << endl;
	cout << "The character at ip is " << *ip << endl;

	ip = ip+1;
	cout << "ip is " << hex << intptr_t(ip) << endl;

	//Initial Code
	char c = 'Z';
	char *cp = &c;

	cout << "cp is " << hex << intptr_t(cp) << endl;
	cout << "The character at cp is " << *cp << endl;

	/* Pointer arithmetic - see what cp+1 is */
	cp = cp+1;
	cout << "cp is " << hex << intptr_t(cp) << endl;

	/* Do not print *cp, because it points to
	memory space not allocated to your program */
	return 0;
}
