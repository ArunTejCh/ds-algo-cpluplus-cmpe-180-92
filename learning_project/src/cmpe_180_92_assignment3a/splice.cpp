/*
 * splice.cpp
 *
 *  Created on: Sep 13, 2016
 *      Author: chennadi
 */
#include <iostream>
#include <string>
using namespace std;

/**
 Return a string that interleaves the characters in strings a and b.
 If one string is longer than the other, append the suffix.
 For example, splicing "Hello" and "Goodbye" yields "HGeololdobye".
 */
string splice(string a, string b) {
	int aLength = a.length();
	int bLength = b.length();

	int spliceLength = 0;
	string endPart;
	if (aLength > bLength) {
		spliceLength = bLength;
		endPart = a.substr(bLength, aLength - 1);
	} else if (aLength < bLength) {
		spliceLength = aLength;
		endPart = b.substr(aLength, bLength - 1);
	} else {
		spliceLength = bLength;
	}
	char combi[2 * spliceLength];


	for (int i = 0; i < spliceLength; i++) {
		combi[2 * i] = a.at(i);
		combi[(2 * i) + 1] = b.at(i);
	}


	string final;
	if (aLength != bLength) {
		string ret(combi, 2*spliceLength);
		//cout << "spliced: " << ret << endl;
		//cout << "end: " << endPart << endl;
		final = ret + endPart;
	}else{
	    string ret(combi, 2*spliceLength);
	    //cout << "spliced: " << ret << endl;
		final = ret;
	}

	return final;
}

