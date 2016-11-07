/*
 * war_and_peace.cpp
 *
 *  Created on: Sep 14, 2016
 *      Author: chennadi
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include "war_and_peace.h"

using namespace std;

// Names to search for.
const string MAKAR = "Makar Alexeevich";
const string JOSEPH = "Joseph Bazdeev";
const string BORIS = "Boris Drubetskoy";

const string INPUT_FILE_NAME = "src/WarAndPeace.txt";
void printHeaderForAuthors();
void loadBooks(vector<string> &lines, ifstream &input);
void getNamesPerLine(vector<string> &lines);
void printNameLine(int lineNo, int position, string name);
void loadNames(vector<string> &names, vector<string> &namesWithLineBreak);

int computeNamePositions() {
	ifstream input;
	input.open(INPUT_FILE_NAME.c_str());
	std::vector<string> lines;

	if (input.fail()) {
		cout << "Failed to open " << INPUT_FILE_NAME << endl;
		return -1;
	}

	loadBooks(lines, input);

	input.close();

	printHeaderForAuthors();

	getNamesPerLine(lines);

	/***** Complete this program. *****/

	return 0;
}

void loadBooks(vector<string> &lines, ifstream &input) {

	string line;

	while (getline(input, line)) {
		lines.push_back(line);
	}

}

void getNamesPerLine(vector<string> &lines) {

	std::vector<string> names;
	std::vector<string> namesWithLineBreak;

	loadNames(names, namesWithLineBreak);

	for (unsigned i = 0; i < lines.size(); i++) {
		string curLine = lines[i];
		string twoLines;
		if (i != (lines.size() - 1)) {
			twoLines = lines[i] + "\n" + lines[i + 1];
		}
		for (unsigned j = 0; j < names.size(); j++) {
			int pos = curLine.find(names[j]);
			while (pos >= 0) {
				printNameLine(i + 1, pos + 1, names[j]);
				pos = curLine.find(names[j], pos + 1);
			}

			if (i != (lines.size() - 1)) {

				int posEnd = twoLines.find(namesWithLineBreak[j]);

				if (posEnd > 0) {
					printNameLine(i + 1, posEnd + 1, names[j]);
				}
			}

		}
	}
}

void printHeaderForAuthors() {
	cout << " LINE  POSITION  NAME";
}

void printNameLine(int lineNo, int position, string name) {
	cout << endl << setw(5) << lineNo << setw(10) << position << "  " << name;
}

void loadNames(vector<string> &names, vector<string> &namesWithLineBreak) {

	names.push_back(MAKAR);
	names.push_back(JOSEPH);
	names.push_back(BORIS);

	namesWithLineBreak.push_back("Makar\nAlexeevich");
	namesWithLineBreak.push_back("Joseph\nBazdeev");
	namesWithLineBreak.push_back("Boris\nDrubetskoy");

}
