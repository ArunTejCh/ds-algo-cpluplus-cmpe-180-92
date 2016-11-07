/*
 * widget.cpp
 *
 *  Created on: Sep 24, 2016
 *      Author: chennadi
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>
#include <sstream>
#include "widget.h"

using namespace std;
void splitData(const string &s, char delim, vector<string> &elems);

struct EmployeeData {
	int state;
	int plant;
	int dept;
	int empId;
	int count;
	string name;
};

void printEmployeeData(EmployeeData &emp);

class WidgetReport {
	/***** Complete this class. *****/

public:
	WidgetReport(ifstream& in);  // constructor
	void print();

private:
	ifstream& input;  // reference to the input stream
	void printWidgetHeader();
	void printLine();
	void printSummation();
	void printVariation(int &state, int &plant, int &dept, EmployeeData &last,
			EmployeeData &cur);
	void printStateTotal(int count, int id);
	void printPlantTotal(int count, int id);
	void printDeptTotal(int count, int id);
	void printGrandTotal(int);
};

const string INPUT_FILE_NAME = "src/widgets.txt";

int computeWidget() {
	ifstream input;
	input.open(INPUT_FILE_NAME.c_str());
	if (input.fail()) {
		cout << "Failed to open " << INPUT_FILE_NAME << endl;
		return -1;
	}

	// Generate and print the Widget Report.
	/***** Complete this main. *****/
	WidgetReport widget(input);
	widget.print();
	input.close();
	return 0;
}

/***** Put member function definitions after the main. *****/

WidgetReport::WidgetReport(ifstream& in) :
		input(in) {}

void WidgetReport::print() {
	string line;
	EmployeeData lastEmp;
	lastEmp.state = -1;
	lastEmp.plant = -1;
	lastEmp.dept = -1;

	EmployeeData curEmp;
	int stateCount, plantCount, deptCount, total;
	stateCount = 0;
	plantCount = 0;
	deptCount = 0;
	total = 0;

	this->printWidgetHeader();
	int i = 0;
	while (getline(input, line, '\r')) {
		if (i > 0) {
			//cout << line << endl;
			std::vector<string> curElem;
			splitData(line, ' ', curElem);

			//load line into struct
			curEmp.state = atoi(curElem[0].c_str());
			curEmp.plant = atoi(curElem[1].c_str());
			curEmp.dept = atoi(curElem[2].c_str());
			curEmp.empId = atoi(curElem[3].c_str());
			curEmp.name = curElem[4] + ' ' + curElem[5];
			curEmp.count = atoi(curElem[6].c_str());
			total = total + curEmp.count;

			printVariation(stateCount, plantCount, deptCount, lastEmp, curEmp);
			printEmployeeData(curEmp);
			lastEmp = curEmp;
		}
		i++;
	}

	cout << endl;
	printDeptTotal(deptCount, lastEmp.dept);
	printPlantTotal(plantCount, lastEmp.plant);
	printStateTotal(stateCount, lastEmp.state);
	cout << endl;
	printGrandTotal(total);

}

void WidgetReport::printWidgetHeader() {
	cout << "STATE PLANT DEPT EMPID COUNT NAME " << endl << endl;
}

void splitData(const string &s, char delim, vector<string> &elems) {
	stringstream ss;
	ss.str(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
}

void printEmployeeData(EmployeeData &emp) {
	cout << setw(5) << emp.state << setw(6) << emp.plant << setw(5) << emp.dept
			<< setw(6) << emp.empId << setw(6) << emp.count << ' ' << emp.name
			<< endl;
}

void WidgetReport::printVariation(int &state, int &plant, int &dept,
		EmployeeData &last, EmployeeData &cur) {

	if (last.state != cur.state && last.state != -1) {
		cout << endl;
		printDeptTotal(dept, last.dept);
		printPlantTotal(plant, last.plant);
		printStateTotal(state, last.state);
		cout << endl;

		state = cur.count;
		plant = cur.count;
		dept = cur.count;

	} else if (last.plant != cur.plant && last.plant != -1) {
		cout << endl;
		printDeptTotal(dept, last.dept);
		printPlantTotal(plant, last.plant);
		cout << endl;

		state = state + cur.count;
		plant = cur.count;
		dept = cur.count;
	} else if (last.dept != cur.dept && last.dept != -1) {
		cout << endl;
		printDeptTotal(dept, last.dept);
		cout << endl;

		state = state + cur.count;
		plant = plant + cur.count;
		dept = cur.count;
	} else {

		state = state + cur.count;
		plant = plant + cur.count;
		dept = dept + cur.count;

	}
}

void WidgetReport::printStateTotal(int count, int id) {
	cout << setw(28) << count << " TOTAL FOR STATE" << setw(3) << id << " ***"
			<< endl;
}
void WidgetReport::printPlantTotal(int count, int id) {
	cout << setw(28) << count << " TOTAL FOR PLANT" << setw(3) << id << " **"
			<< endl;
}
void WidgetReport::printDeptTotal(int count, int id) {
	cout << setw(28) << count << " TOTAL FOR DEPT " << setw(3) << id << " *"
			<< endl;
}

void WidgetReport::printGrandTotal(int count) {
	cout << setw(28) << count << " GRAND TOTAL        " << "****" << endl;
}
