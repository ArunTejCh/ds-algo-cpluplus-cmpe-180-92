/*
 * RomanNumeral.h
 *
 *  Created on: Oct 2, 2016
 *      Author: chennadi
 */

#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_
#include <string>
#include <iostream>
#include <stdio.h>      /* printf */
#include <math.h>
using namespace std;

class RomanNumeral {
public:
	RomanNumeral();
	RomanNumeral(string roman);
	RomanNumeral(int value);
	friend ostream& operator<<(ostream& outs, RomanNumeral num);
	friend istream& operator>>(istream& in, RomanNumeral &num);
	RomanNumeral operator+(RomanNumeral num);
	RomanNumeral operator/(RomanNumeral num);
	RomanNumeral operator*(RomanNumeral num);
	RomanNumeral operator-(RomanNumeral num);
	bool operator==(RomanNumeral num);
	bool operator!=(RomanNumeral num);
	//Getters
	int getDecimal();
	string getRoman();
	//Setters
	void setRoman(string roman);

	/***** Complete this class. *****/

private:
	string roman;      // Roman numeral as a string
	int decimal;    // decimal value of the Roman numeral

	void toRoman();    // calculate string from decimal value
	void toDecimal();  // calculate decimal value from string
};

#endif /* ROMANNUMERAL_H_ */
