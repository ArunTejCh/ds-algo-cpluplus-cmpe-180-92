/*

 * Person.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: chennadi

#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
using namespace std;

**** Write the constructors. ****

*
 * Destructor

Person::~Person() {
	**** Complete this destructor: Recursively delete all the nodes. ****

	this->children.clear();

	if(this->level != 0){
		delete parent;
	}
}

Person::Person(int level, string name, string spouse) {
	this->level = level;
	this->name = name;
	this->spouse_name = spouse;
	this->parent = nullptr;
}

Person::Person(int level, string name) {
	this->level = level;
	this->name = name;
	this->spouse_name = "";
	this->parent = nullptr;
}

*
 * Have a child.
 * @param child pointer to the new child.

void Person::have_child(Person *child) {
	**** Complete this member function. ****
	child->parent = this;
	this->children.push_back(child);
}

*
 * Print a person.

void Person::print() const {
	**** Complete this member function: Recursively print the nodes. ****

	for (int i = 0; i < this->level; i++) {
		if (i == (this->level - 1)) {
			cout << "+---";
		} else {

			Person* a1 = this->parent;
			Person* a2 = a1->parent;
			for (int j = i; j < this->level - 2; j++) {
				a1 = a2;
				a2 = a2->parent;
			}

			if (a1 == a2->children.back()) {
				cout << "    ";
			} else {
				cout << "|   ";
			}
		}
	}
	if (this->spouse_name == "") {
		cout << this->name << endl;
	} else {
		cout << this->name + " (" + this->spouse_name + ")" << endl;
	}

	for (Person* per : this->children) {

		this->print_bar();
		per->print();
	}

}

*
 * Print the vertical bar.

void Person::print_bar() const {
	**** Complete this member function: Recursively print vertical bars. ****
	for (int i = 0; i <= this->level; i++) {
		if (i == (this->level)) {
			cout << "|   ";
		} else {
			if (this->level == 1) {
				if (this == this->parent->children.back())
					cout << "    ";
				else
					cout << "|   ";
			} else {
				if (i == this->level - 1) {
					if (this == this->parent->children.back()) {
						cout << "    ";
					} else {
						cout << "|   ";
					}
				} else {
					Person* a1 = this->parent;
					Person* a2 = a1->parent;
					for (int j = i; j < this->level - 2; j++) {
						a1 = a2;
						a2 = a2->parent;
					}

					if (a1 == a2->children.back()) {
						cout << "    ";
					} else {
						cout << "|   ";
					}
				}
			}
		}
	}

	cout << endl;

}
*/
