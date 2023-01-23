//============================================================================
// Name        : CSCI1060U_ass9.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description : Lab 9 Part 1
//============================================================================

#include <iostream>
using namespace std;

class Square {
	private:
		double side;

	public:
		double getSide() {
			return side;
		}
		void setSide(double s) {
			side = s;
		}
		Square () {
			side = 1;
		}

	double calculateArea(double side) {
		return (side * side);
	}
};

class Circle {
	private:
		double radius;

	public:
		double getRadius() {
			return radius;
		}
		void setRadius(double r) {
			radius = r;
		}
		Circle () {
			radius = 1;
		}

	double calculateArea(double radius) {
		return (radius * radius * 3.14);
	}
};

void changeShapes(Circle circle, Square square) {
	char y_or_n;
	double side;
	double area;

	//The part that asks if you want to change the circle
	cout << "Do you want to change the size of the Circle? Y/N ";
	cin >> y_or_n;

	if (y_or_n == 'Y' || y_or_n == 'y') {
		area = circle.calculateArea(circle.getRadius());

		//get and set the radius of the new circle
		cout << "\nEnter the radius of the new circle: ";
		cin >> side;

		circle.setRadius(side);

		//Figure out and output if the new circle is bigger or smaller
		if (circle.calculateArea(circle.getRadius()) > area) {
			cout << "You've made the circle bigger! " << area << " -> " << circle.calculateArea(circle.getRadius()) << endl;
		}

		else {
			cout << "You've made the circle smaller! " << area << " -> " << circle.calculateArea(circle.getRadius()) << endl;
		}
	}


	//The part that asks if you want to change the square
	cout << "Do you want to change the size of the Square? Y/N ";
	cin >> y_or_n;

	if (y_or_n == 'Y' || y_or_n == 'y') {
		area = square.calculateArea(square.getSide());

		//get and set the side length of the new square
		cout << "\nEnter the side length of the new square: ";
		cin >> side;

		square.setSide(side);

		//Figure out and output if the new square is bigger or smaller
		if (square.calculateArea(square.getSide()) > area) {
			cout << "\nYou've made the square bigger! " << area << " -> " << square.calculateArea(square.getSide()) << endl;
		}

		else {
			cout << "\nYou've made the square smaller! " << area << " -> " << square.calculateArea(square.getSide()) << endl;
		}
	}

	//Figure out and output which of the square and circle is bigger or if they are both equal sized
	if (square.calculateArea(square.getSide()) > circle.calculateArea(circle.getRadius())) {
		cout << "The square is larger than the circle!" << endl;
	}
	else if (circle.calculateArea(circle.getRadius()) > square.calculateArea(square.getSide())) {
		cout << "The circle is larger than the square!" << endl;
	}
	else {
		cout << "The square and the the circle have the same area!" << endl;
	}
}

int main() {

	Square square;
	Circle circle;

	changeShapes(circle, square);
}
