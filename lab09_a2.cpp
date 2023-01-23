//============================================================================
// Name        : CSCI1060U_ass9.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description : Lab 9 Part 2
//============================================================================

#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;

class RegularPolygon {
	private:
		int num_sides;
		double side_length;

	public:
		//Constructor
		RegularPolygon(int s, double l) {
			num_sides = s;
			side_length = l;
		}

		//Getters
		int getNumSides(){
			return num_sides;
		}
		double getSideLength(){
			return side_length;
		}

		//Setters
		void setNumSides(int n){
			num_sides = n;
		}
		void setSideLength(double l){
			side_length = l;
		}

		//Area and Perimeter
		double calculateArea() {
			double area;
			area = num_sides * pow(side_length,2) * 0.25 * (cos(M_PI/num_sides)/sin(M_PI/num_sides));
			return area;
		}
		double calculatePerimeter(){
			return num_sides * side_length;
		}

		//Return all info about the RegularPolygon as a string
		string toString() {
			string contents;

			stringstream sides;
			sides << num_sides;

			stringstream length;
			length << side_length;

			stringstream area;
			area << calculateArea();

			stringstream perimeter;
			perimeter << calculatePerimeter();

			contents = "The polygon has " + sides.str() + " sides, of length " + length.str() +
					". \nThe polygon has an area of " + area.str() + " and a perimeter of "
					+ perimeter.str() + "\n";

			return contents;
		}

		//checks if 2 RegularPolygons have the same number of sides
		bool operator== (RegularPolygon pol2) {
			if (num_sides == pol2.getNumSides()) {
				return true;
			}
			else {
				return false;
			}
		}

		//Destructor
		~RegularPolygon(){
			cout << "Polygon consigned to the void.\n";
		}
};

int main() {

	RegularPolygon pentagon(5,3.6);
	RegularPolygon hexagon(6,26);


	bool same_shape = pentagon == hexagon;

	cout << pentagon.toString() << endl;
	cout << hexagon.toString() << endl;
	if (same_shape == false) {
		cout << "The polygons have a different number of sides" << endl;
	}
	else {
		cout << "The polygons have the same number of sides" << endl;
	}

	return 0;
}
