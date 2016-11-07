/*
 * Pair.cpp
 *
 *  Created on: Oct 12, 2016
 *      Author: chennadi
 */
#include <iostream>
using namespace std;

/**
 Implement the constructor to initialize two Box values,
 and do the right thing in the "big 3".

 Note that the Box::show method prints a count of ALL Box
 objects that have been created and not yet destroyed.
 */

#include "Pair.h"

Pair::Pair(int v1, int v2) {
	first = new Box(v1);
	second = new Box(v2);
	//this->show();
}

// copy constructor
Pair::Pair(const Pair& other) {
	Box b1 = *other.first;
	Box b2 = *other.second;
	this->first = new Box(b1.value());
	this->second = new Box(b2.value());
}
// operator=
Pair& Pair::operator=(const Pair& other) {
	//this->~Pair();

	*this->first=*other.first;
	this->second=other.second;

	return *this;
}
// destructor
Pair::~Pair() {
	this->first->~Box();
	this->second->~Box();
}

