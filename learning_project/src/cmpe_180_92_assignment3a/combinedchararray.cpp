/*
 * combinedchararray.cpp
 *
 *  Created on: Sep 14, 2016
 *      Author: chennadi
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <string>

using namespace std;
string spliceStr(string a, string b) {
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

/**
   Compuute a string that interleaves the characters in strings s and t.
   If one string is longer than the other, append the suffix.
   For example, splicing "Hello" and "Goodbye" yields "HGeololdobye".
   Place the result into the character array r of size rlen.
   If the result does not fit, truncate it to rlen - 1 characters
   and a '\0' terminator.
*/
void splice(const char s[], const char t[], char r[], int rlen)
{
    std::string a(s);
    std::string b(t);
    int combinedLength = a.size()+b.size();
    string combined = spliceStr(a,b);

    if( combinedLength <= rlen ){
        for(int i = 0; i < combinedLength; i++){
            r[i] = combined.at(i);
        }
    }else{
        for(int i = 0; i < rlen - 1; i++){
            r[i] = combined.at(i);
        }

        r[rlen - 1] = '\0';
    }
}



