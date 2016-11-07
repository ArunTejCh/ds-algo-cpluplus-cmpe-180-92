/*
 * Person.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: chennadi
 */
#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
using namespace std;

/***** Write the constructors. *****/

/**
 * Destructor
 */
Person::~Person() {
	/***** Complete this destructor: Recursively delete all the nodes. *****/

	for(Person* p: children){
		delete p;
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

/**
 * Have a child.
 * @param child pointer to the new child.
 */
void Person::have_child(Person *child) {
	/***** Complete this member function. *****/
	child->parent = this;
	this->children.push_back(child);
}

/**
 * Print a person.
 */
void Person::print() const {
	/***** Complete this member function: Recursively print the nodes. *****/
	if(parent != nullptr){
		//calling parent bar because this level's bar is already known
		this->parent->print_bar();
		cout << "|   " << endl;
		this->parent->print_bar();
		cout << "+---";
	}


	if (this->spouse_name == "") {
			cout << this->name << endl;
		} else {
			cout << this->name + " (" + this->spouse_name + ")" << endl;
		}

	for (Person* per : this->children) {
			per->print();
	}
}

/**
 * Print the vertical bar.
 */
void Person::print_bar() const {
	/***** Complete this member function: Recursively print vertical bars. *****/

	//Base case for recursion to return
	if(this->parent == nullptr){
		return;
	}

	this->parent->print_bar();

	if(this != this->parent->children.back()){
		cout << "|  ";
	}else{
		cout << "   ";
	}
}
