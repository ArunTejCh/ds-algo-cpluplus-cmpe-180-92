/*
 * problem1.cpp
 *
 *  Created on: Sep 1, 2016
 *      Author: chennadi
 */
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

const string INPUT_FILE_NAME = "GettysburgAddress.txt";

int problem1()
{
    string line;
    int line_count = 0;
    int character_count = 0;
    int word_count = 0;
    int lower_count = 0;
    int upper_count = 0;
    int space_count = 0;
    int punctuation_count = 0;

    ifstream input;
    char c;
    bool wasLastChar = false;
    input.open("GettysburgAddress.txt");
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    while (input >> noskipws >> c) {
		if (c == '\n') {
			line_count++;
			if (wasLastChar) {
				word_count++;
			}
			wasLastChar = false;
		} else {
	        character_count++;
			if (ispunct(c)) {
				punctuation_count++;
				if(c == '-' && wasLastChar){
					word_count++;
					wasLastChar = false;
				}else{
					wasLastChar = true;
				}
			} else if (c == ' ') {
				space_count++;
				if(wasLastChar){
					word_count++;
				}
				wasLastChar = false;
			} else if (isupper(c)){
				upper_count++;
				wasLastChar = true;
			} else if (islower(c)){
				lower_count++;
				wasLastChar = true;
			}
		}
    }

    cout << "Statistics for file " << INPUT_FILE_NAME << ":" << endl;
    cout << endl;

    /***** Complete this program. *****/

    cout << "Lines: " << line_count << endl;
    cout << "Characters: " << character_count << endl;
    cout << "Words: " << word_count << endl;
    cout << "Lower-case letters: " << lower_count << endl;
    cout << "Upper-case letters: " << upper_count << endl;
    cout << "Spaces: " << space_count << endl;
    cout << "Punctuation marks: " << punctuation_count << endl;
    return 0;
}



