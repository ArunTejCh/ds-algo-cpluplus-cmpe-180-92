/*
 * problem1.cpp
 *
 *  Created on: Sep 4, 2016
 *      Author: chennadi
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
typedef int Door;

const int SIMULATION_COUNT = 100;

/**
 * Suggested problem decomposition.
 * You do not have to use these function declarations.
 */

void simulate(int sequence, int& win1, int& win2);
Door hideCar();
Door openDoor(Door firstChoiceDoor, Door carBehindDoor);
Door makeFirstChoice();
Door makeSecondChoice(Door firstDoor, Door openedDoor);

Door randomDoor();
Door randomDoorNot(Door aDoor, Door anotherDoor);
Door chooseRemainingDoor(Door firstDoor, Door openedDoor);
void printHeader();

/**
 * Main
 */
int computeChances() {
	int win1 = 0, win2 = 0;

	srand(time(0));  // seed the random number generator
	printHeader();

	// Run the simulations.
	for (int i = 1; i <= SIMULATION_COUNT; i++) {
		simulate(i, win1, win2);
	}
	cout << endl;
	cout << setw(4) << win1 << " wins if stay with the first choice" << endl;
	cout << setw(4) << win2 << " wins if switch to the second choice" << endl;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(1);

	cout << endl;
	cout << "Win ratio of switch over stay: ";
	cout << static_cast<double>(win2) / win1 << endl;
}

void simulate(int sequence, int& win1, int& win2) {

	int carDoor = hideCar();
	int firstChoice = makeFirstChoice();
	string winOne = "   ";
	string winTwo = "   ";

	int openedDoor = openDoor(firstChoice, carDoor);

	int secondDoor = makeSecondChoice(firstChoice, openedDoor);

	if (carDoor == firstChoice) {
		win1++;
		winOne = "yes";
	} else {
		win2++;
		winTwo = "yes";
	}
	cout << setw(4) << sequence << setw(8) << carDoor << setw(8) << firstChoice
			<< setw(8) << openedDoor << setw(8) << secondDoor << setw(7)
			<< winOne << setw(7) << winTwo << endl;

}

Door hideCar() {
	return randomDoor();
}

Door randomDoor() {
	return (rand() % 3 + 1);
}

Door makeFirstChoice(){
	return randomDoor();
}

Door openDoor(Door firstChoiceDoor, Door carBehindDoor) {

	if (firstChoiceDoor != carBehindDoor) {

		chooseRemainingDoor(firstChoiceDoor, carBehindDoor);

	} else {
		switch (firstChoiceDoor) {
		case 1:
			return randomDoorNot(2, 3);
		case 2:
			return randomDoorNot(1, 3);
		case 3:
			return randomDoorNot(1, 2);
		}
	}
}

Door randomDoorNot(Door aDoor, Door anotherDoor) {
	int choice = rand() % 2;
	if (choice == 0) {
		return aDoor;
	} else {
		return anotherDoor;
	}
}

Door makeSecondChoice(Door firstDoor, Door openedDoor) {
	return chooseRemainingDoor(firstDoor, openedDoor);
}

Door chooseRemainingDoor(Door doorOne, Door doorTwo) {

	int doorTotal = doorOne + doorTwo;

	switch (doorTotal) {
	case 3:
		return 3;
	case 4:
		return 2;
	case 5:
		return 1;
	}
}

void printHeader() {
	cout << "   #     Car   First  Opened  Second    Win    Win" << endl;
	cout << "        here  choice    door  choice  first second" << endl;
	cout << endl;
}
/***** Complete this program. ****/

