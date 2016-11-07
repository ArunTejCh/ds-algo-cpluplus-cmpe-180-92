/*
 * SortedVector.cpp
 *
 *  Created on: Oct 24, 2016
 *      Author: chennadi
 */
#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector() {
}

SortedVector::~SortedVector() {
}

/***** Complete this file. *****/

bool SortedVector::check() {
	if (data.size() == 0)
		return true;

	vector<int>::iterator it = data.begin();
	int prev = *it;
	while ((++it != data.end()) && (prev <= *it))
		;
	return it == data.end();
}

void SortedVector::prepend(int value) {
	vector<int>::iterator it = data.begin();

	data.insert(it, value);

}

void SortedVector::append(int value) {
	data.push_back(value);
}

bool SortedVector::find(int value) const {

	int mid = data[data.size() / 2];
	if (value <= mid) {
		vector<int>::const_iterator it;
		for (it = data.begin(); it != data.end(); it++) {
			if (*it == value) {
				return true;
			}
		}
	} else {
		vector<int>::const_reverse_iterator it;
		for (it = data.rbegin(); it != data.rend(); it++) {
			if (*it == value) {
				return true;
			}
		}
	}
	return false;
}

int SortedVector::get_value(int i) const {
	return data[i];
}

void SortedVector::clear() {
	vector<int>::iterator it;

	for (it = data.begin(); it != data.end();) {
		it = data.erase(it);
	}
}
