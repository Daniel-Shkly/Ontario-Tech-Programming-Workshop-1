//============================================================================
// Name        : CSCI1060U_ass5.cpp
// Author      : Daniel Shklyarman
// Version     :
// Copyright   : Your copyright notice
// Description : Lab 5 Assignment 1
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

const int kNumberOfPlants = 3;

//get the production data for each plant
void getPlantData(int& total_production) {

	cout << "Enter number of units produced by each department.\n" << "Enter a negative number once you're done entering the data.\n";

    total_production = 0; //initial production value
    int department_production;
	cin >> department_production; //get a department's data

    //get data and add new data points to total until user enters a negative number
    while (department_production >= 0) {
    	total_production = total_production + department_production;
    	cin >> department_production;
    }

    cout << "Total = " << total_production << endl;
}

//runs getPlantData for each plant to get all of their production data
void getEachPlantData(int &plant1, int &plant2, int &plant3, int num_plants) {

    for (int plant_number = 1; plant_number <= num_plants; plant_number++){
        cout << endl << "Enter production data for plant number " << plant_number << endl;
        	if (plant_number == 1){
        		getPlantData(plant1);
        	}
        	else if (plant_number == 2){
        		getPlantData(plant2);
        	}
        	else if (plant_number == 3){
        		getPlantData(plant3);
        	}
    }
}

//gets each plants production data in thousands (rounded down), so that the later bar graph is readable
void inThousands(int &var1, int &var2, int &var3) {
    var1 = static_cast<int>(floor(var1/1000.0 + 0.5));
	var2 = static_cast<int>(floor(var2/1000.0 + 0.5));
	var3 = static_cast<int>(floor(var3/1000.0 + 0.5));
}

//prints a number of '*' for each plant equal to the number of thousands of units each plant produced
void createBar(int n) {

    for (int count = 1; count <= n; count++) {
    	cout << "*";
    }

}

//prints out a bar graph by calling createBar on each plant
void createBarGraph(const int plant1, const int plant2, const int plant3, int num_plants) {

    cout << "\nUnits produced in thousands of units:\n";

    for (int plant_number = 1; plant_number <= num_plants; plant_number++) {

        cout << "Factory #" << plant_number << ": ";

        if (plant_number == 1){
        	createBar(plant1);
        }
        if (plant_number == 2){
        	createBar(plant2);
        }
        if (plant_number == 3){
        	createBar(plant3);
        }

        cout << endl;
    }
}

int main() {

    cout << "This program displays a graph showing production for each factory in the company.\n";

    //declare plants and their initial production values
    int plant1 = 0; 
    int plant2 = 0; 
    int plant3 = 0;

    getEachPlantData(plant1, plant2, plant3, kNumberOfPlants); //get the total production for each plant

    inThousands(plant1, plant2, plant3); //get the data for each plant in thousands

    createBarGraph(plant1, plant2, plant3, kNumberOfPlants); //create and print the bar graph


    return 0;
}

