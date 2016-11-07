/*
 * SortedList.cpp
 *
 *  Created on: Oct 24, 2016
 *      Author: chennadi
 */
#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

SortedList::SortedList() {
}

SortedList::~SortedList() {
}

/***** Complete this file. *****/

bool SortedList::check() {
	if (data.size() == 0)
		return true;

	list<int>::iterator it = data.begin();
	int prev = *it;
	while ((++it != data.end()) && (prev <= *it))
		;
	return it == data.end();
}

void SortedList::prepend(int value) {
	list<int>::iterator it = data.begin();

	data.insert(it, value);
}

void SortedList::append(int value) {
	data.push_back(value);
}

bool SortedList::find(int value) const {

	list<int>::const_iterator  it;


	for (it = data.begin(); it != data.end(); it++) {
			if (*it == value) {
				return true;
		}
	}
	return false;
}

int SortedList::get_value(int i) const {
	int size = data.size();
	if (i < size / 2) {
		list<int>::const_iterator it = data.begin();

		//std::advance(it, i);

		for(int j = 0; j < i; j++){
			it++;
		}

		return *it;
	} else {
		list<int>::const_reverse_iterator rev_it = data.rbegin();

		//std::advance(rev_it, (size -1- i));

		for(int j = size; j > i+1; j--){
					rev_it++;
		}

		return *rev_it;

		/*list<int>::iterator it;

				std::advance(it, i);

				return *it;*/
	}
}

void SortedList::clear() {
	list<int>::iterator it;

	for (it = data.begin(); it != data.end();) {
		it = data.erase(it);
	}
}
