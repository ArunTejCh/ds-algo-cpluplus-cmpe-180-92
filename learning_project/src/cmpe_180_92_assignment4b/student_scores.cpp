/*
 * student_scores.cpp
 *
 *  Created on: Sep 19, 2016
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

using namespace std;

const string INPUT_FILE_NAME = "src/students.txt";

void loadDetailsIntoArrays(string* names, int** marks, ifstream &input);
void printStudentScores(string* names, int** marks, int noOfStudents);
void printHeader(string subject);
void split(const string &s, char delim, vector<string> &elems);

/**
 * Main.
 */
int computeStudentScores() {
	ifstream input;
	input.open(INPUT_FILE_NAME.c_str());
	if (input.fail()) {
		cout << "Failed to open " << INPUT_FILE_NAME << endl;
		return -1;
	}

	string line;
	getline(input, line);
	std::vector<string> headers;
	split(line, ' ', headers);

	printHeader(headers[0].c_str());
	int length = atoi(headers[1].c_str());

	//cout << "No of students: " << length << endl;
	string* names = new string[length];
	int** marks = new int*[length];

	loadDetailsIntoArrays(names, marks, input);

	printStudentScores(names, marks, length);
	return 0;

	/***** Complete this program. *****/
}

void printHeader(string subject) {
	cout << "STUDENT SCORES for " << subject << endl << endl;
}

void loadDetailsIntoArrays(string* names, int** marks, ifstream &input) {
	string line;
	int i = 0;
	while (getline(input, line)) {
		std::vector<string> details;
		split(line, ' ', details);
		int noOfMarks = atoi(details[2].c_str());
		names[i] = details[0] + " " + details[1];

		if (noOfMarks > 0) {
			int* curMarks = new int(noOfMarks + 1);

			for (int j = 0; j < noOfMarks; j++) {
				curMarks[j] = atoi(details[j + 3].c_str());
			}
			curMarks[noOfMarks] = -1;
			marks[i] = curMarks;
		} else {
			marks[i] = '\0';
		}

		i++;
	}

}

void printStudentScores(string* names, int** marks, int noOfStudents) {
	for (int i = 0; i < noOfStudents; i++) {
		cout << names[i] << endl;

		if (marks[i] != '\0') {
			int j = 0;
			while (marks[i][j] != -1) {
				cout << setw(4) << marks[i][j];
				j++;
			}
			cout << endl << endl;
		} else {
			cout << "  (none)" << endl << endl;
		}
		delete[] marks[i];
	}
	delete[] names;
	delete[] marks;
}

void split(const string &s, char delim, vector<string> &elems) {
	stringstream ss;
	ss.str(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
}
