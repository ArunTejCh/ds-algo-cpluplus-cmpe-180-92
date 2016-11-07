/*
 * pointer_basics.cpp
 *
 *  Created on: Sep 19, 2016
 *      Author: chennadi
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include "pointer_basics.h"
using namespace std;

void pointerPass(int* &ptr);

typedef int    *IntPtr;

void typeDefPass(IntPtr ptr);

void point(){

	int num = 5;
	int *ptr = &num;;

	cout << "Number is:" << num << endl;
	cout << "Address of: " << &num << endl;
	cout << "Pointer to num: " << ptr << endl;
	cout << "Pointer value:" << *ptr << endl;
	/*delete ptr;
	cout << "Pointer to num: " << ptr << endl;
	cout << "Pointer value:" << *ptr << endl;
	cout << "Pointer + 1:" << ptr + 1 << endl;
	cout << "Pointer + 1 value:" << *(ptr + 1) << endl;
	cout << "Pointer + 2:" << ptr + 2 << endl;
	cout << "Pointer + 2 value:" << *(ptr + 2) << endl;
	cout << "Pointer + 3:" << ptr + 3 << endl;
	cout << "Pointer + 3 value:" << *(ptr + 3) << endl;
	cout << "Address of pointer:" << &*ptr << endl;
	cout << "Pointer of Address:" << *&num << endl;*/

	pointerPass(ptr);
	typeDefPass(ptr);
}

void pointerPass(int* &ptr){
	cout << "Pointer passed to fn: " << ptr << endl;
}

void typeDefPass(IntPtr ptr){
	cout << "Pointer passed to typedef fn: " << ptr << endl;
}
