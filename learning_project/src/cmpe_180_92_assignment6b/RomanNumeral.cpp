/*
 * RomanNumeral.cpp
 *
 *  Created on: Oct 2, 2016
 *      Author: chennadi
 */
#include <string>
#include <iostream>
#include <stdio.h>      /* printf */
#include <math.h>
#include "RomanNumeral.h"
using namespace std;

/**
 * Default constructor.
 */
RomanNumeral::RomanNumeral() :
		roman(""), decimal(0) {
}

/**
 * Integer constructor.
 */
RomanNumeral::RomanNumeral(int num) {
	this->decimal = num;
	this->toRoman();
}

/**
 * Roman constructor.
 */
RomanNumeral::RomanNumeral(string rom) {
	this->roman = rom;
	this->decimal = 0;
	this->toDecimal();
}

/**
 * Getter for decimal.
 */
int RomanNumeral::getDecimal() {
	return this->decimal;
}

/**
 * Getter for roman.
 */
string RomanNumeral::getRoman() {
	return this->roman;
}

/**
 * Operators overloading for Roman Numerals.
 */
RomanNumeral RomanNumeral::operator/(RomanNumeral num) {
	int div = this->decimal / num.getDecimal();
	return RomanNumeral(div);
}

RomanNumeral RomanNumeral::operator+(RomanNumeral num) {
	int res = this->decimal + num.getDecimal();
	return RomanNumeral(res);
}

RomanNumeral RomanNumeral::operator-(RomanNumeral num) {
	int res = this->decimal - num.getDecimal();
	return RomanNumeral(res);
}

RomanNumeral RomanNumeral::operator*(RomanNumeral num) {
	int res = this->decimal * num.getDecimal();
	return RomanNumeral(res);
}

ostream& operator<<(ostream& outs, RomanNumeral num) {
	outs << "[" << num.getDecimal() << ":" << num.getRoman() << "]";
	return outs;
}

istream& operator>>(istream& in, RomanNumeral &num) {
	string val = "";
	in >> num.roman;
	num.toDecimal();
	//num.setRoman(val);
	return in;
}

/*
 * Setter for RomanNumeral
 */
void RomanNumeral::setRoman(string roman) {
	this->roman = roman;
	this->toDecimal();
}

bool RomanNumeral::operator==(RomanNumeral num) {
	if (this->decimal == num.getDecimal()) {
		return true;
	} else {
		return false;
	}
}

bool RomanNumeral::operator!=(RomanNumeral num) {
	if (this->decimal == num.getDecimal()) {
		return false;
	} else {
		return true;
	}
}

/**
 * Member function which converts roman numeral to decimal
 */
void RomanNumeral::toDecimal() {

	char curChar;
	int cur = 0;
	int total = 0;
	int length = this->roman.length();
	string rom = this->roman;

	for (int i = 0; i < length; i++) {
		curChar = rom.at(i);
		switch (curChar) {
		case 'I':
			cur = 1;
			if ((i + 1) < length && rom.at(i + 1) == 'V') {
				cur = 4;
				i++;
			} else if ((i + 1) < length && rom.at(i + 1) == 'X') {
				cur = 9;
				i++;
			}
			break;
		case 'V':
			cur = 5;
			break;
		case 'X':
			cur = 10;
			if ((i + 1) < length && rom.at(i + 1) == 'L') {
				cur = 40;
				i++;
			} else if ((i + 1) < length && rom.at(i + 1) == 'C') {
				cur = 90;
				i++;
			}
			break;
		case 'L':
			cur = 50;
			break;
		case 'C':
			cur = 100;
			if ((i + 1) < length && rom.at(i + 1) == 'D') {
				cur = 400;
				i++;
			} else if ((i + 1) < length && rom.at(i + 1) == 'M') {
				cur = 900;
				i++;
			}
			break;
		case 'D':
			cur = 500;
			break;
		case 'M':
			cur = 1000;
			break;
		}

		total = total + cur;
	}

	this->decimal = total;
}

/**
 * Member function which converts decimal to roman numeral
 */
void RomanNumeral::toRoman() {

	std::string rom = "";
	int base = 0, rem = 0, num = this->decimal;

	for (int i = 1; i < 5; i++) {
		base = pow(10, i) + 0.5;
		rem = num % base;
		num = num - rem;
		if (rem == 0) {
			continue;
		}

		if (0 < rem && rem < 10) {
			switch (rem) {
			case 1:
				rom.insert(0, "I");
				break;
			case 2:
				rom.insert(0, "II");
				break;
			case 3:
				rom.insert(0, "III");
				break;
			case 4:
				rom.insert(0, "IV");
				break;
			case 5:
				rom.insert(0, "V");
				break;
			case 6:
				rom.insert(0, "VI");
				break;
			case 7:
				rom.insert(0, "VII");
				break;
			case 8:
				rom.insert(0, "VIII");
				break;
			case 9:
				rom.insert(0, "IX");
				break;
			}
		} else if (10 <= rem && rem < 100) {
			switch (rem) {
			case 10:
				rom.insert(0, "X");
				break;
			case 20:
				rom.insert(0, "XX");
				break;
			case 30:
				rom.insert(0, "XXX");
				break;
			case 40:
				rom.insert(0, "XL");
				break;
			case 50:
				rom.insert(0, "L");
				break;
			case 60:
				rom.insert(0, "LX");
				break;
			case 70:
				rom.insert(0, "LXX");
				break;
			case 80:
				rom.insert(0, "LXXX");
				break;
			case 90:
				rom.insert(0, "XC");
				break;
			}
		} else if (100 <= rem && rem < 1000) {
			switch (rem) {
			case 100:
				rom.insert(0, "C");
				break;
			case 200:
				rom.insert(0, "CC");
				break;
			case 300:
				rom.insert(0, "CCC");
				break;
			case 400:
				rom.insert(0, "CD");
				break;
			case 500:
				rom.insert(0, "D");
				break;
			case 600:
				rom.insert(0, "DC");
				break;
			case 700:
				rom.insert(0, "DCC");
				break;
			case 800:
				rom.insert(0, "DCCC");
				break;
			case 900:
				rom.insert(0, "CM");
				break;
			}
		} else {
			switch (rem) {
			case 1000:
				rom.insert(0, "M");
				break;
			case 2000:
				rom.insert(0, "MM");
				break;
			case 3000:
				rom.insert(0, "MM");
				break;
			case 4000:
				rom.insert(0, "MMMM");
				break;
			}
		}
	}

	this->roman = rom;

}

/***** Complete this file. *****/

