/*
 * goldenbach_theorem.cpp
 *
 *  Created on: Sep 13, 2016
 *      Author: chennadi
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "goldenbach_theorem.h"
using namespace std;

void initializeArray(int nos[][10]);
void computePrimes(int nos[][10]);
void printPrimes(int nos[][10]);
void loadPrimesIntoVector(vector<int> &primes, int nos[][10]);
bool containsNumber(vector<int> primes, int number);
void loopForPrimeAdditives(vector<int> &primes);

int computePrimeAdditives() {

	int nosTo100[10][10];
	std::vector<int> primes;
	initializeArray(nosTo100);
	computePrimes(nosTo100);
	printPrimes(nosTo100);
	loadPrimesIntoVector(primes, nosTo100);
	loopForPrimeAdditives(primes);
	return 0;
}

void initializeArray(int nos[][10]) {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			nos[i][j] = (i * 10) + j + 1;
		}
	}

	nos[0][0] = -1;
}

void printPrimes(int nos[][10]) {

	cout << "Primes:" << endl << endl;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (nos[i][j] != -1) {
				cout << setw(3) << nos[i][j];
			} else {
				cout << setw(3) << ".";
			}
		}
		cout << endl;
	}

	cout << endl;

}

void computePrimes(int nos[][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int cur = nos[i][j];

			if (cur != -1) {
				for (int k = i; k < 10; k++) {
					for (int l = 0; l < 10; l++) {
						int nextNo = nos[k][l];
						if (nextNo != -1 && nextNo > cur) {
							if (nextNo % cur == 0) {
								nos[k][l] = -1;
							}
						}
					}
				}
			}
		}
	}
}

void loadPrimesIntoVector(vector<int> &primes, int nos[][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (nos[i][j] != -1) {
				primes.push_back(nos[i][j]);
			}
		}
	}
}
void loopForPrimeAdditives(vector<int> &primes) {
	cout << "Test of Goldbach's Conjecture:" << endl << endl;

	for (int i = 2; i <= 50; i++) {
		int currentNo = i * 2;
		bool first = true;
		for (unsigned j = 0; j < primes.size(); j++) {
			int prime = primes[j];
			if (prime <= i) {
				int diff = currentNo - prime;
				/*cout << "diff: " << diff << " containsno: "
				 << containsNumber(primes, diff) << endl;*/
				if (containsNumber(primes, diff)) {
					if (first) {
						cout << setw(3) << currentNo << ":" << setw(3) << prime
								<< setw(3) << diff << endl;
						first = false;
					} else {
						cout << setw(7) << prime << setw(3) << diff << endl;
					}
				}
			}
		}

		if (i != 50) {
			cout << endl;
		}
	}
}

bool containsNumber(vector<int> primes, int number) {

	if (std::find(primes.begin(), primes.end(), number) != primes.end()) {
		return true;
	} else {
		return false;
	}
}
