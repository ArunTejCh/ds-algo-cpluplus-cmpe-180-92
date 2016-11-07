/*
 * mutli_words_split.cpp
 *
 *  Created on: Sep 19, 2016
 *      Author: chennadi
 */
#include <cstring>
#include <iostream>

using namespace std;

/**
 Given a '\0'-terminated character array, split it by replacing
 each space in the character array with a '\0' and return a
 newly allocated array of char* pointers to the resulting strings.
 */
char** split3(char* words) {
	int noOfStrings = 1;
	//printf("words: %s",words);
	int i = 0;

	while (words[i] != '\0') {
		if (words[i] == ' ') {
			noOfStrings++;
			words[i] = '\0';
		}
		i++;
	}

	cout << "length of strings: " << noOfStrings << endl;

	char** result = new char*[noOfStrings];
	int* lengths = new int(noOfStrings + 1);
	i = 0;
	int k = 0;
	for (int j = 0; j < noOfStrings; j++) {
		while (words[i] != '\0') {
			k++;
			i++;
		}
		lengths[j] = k;
		k = 0;
		i++;
	}
	lengths[noOfStrings] = '\0';

	for (int l = 0; l < noOfStrings; l++) {
		//printf("%d ", lengths[l]);
	}
	i =0;
	k = 0;
	for (int j = 0; j < noOfStrings; j++) {
		result[j] = new char(lengths[j]);
		while (words[i] != '\0') {
			result[j][k] = words[i];
			k++;
			i++;
		}
		result[j][k] = '\0';
		k = 0;
		i++;
	}

	return result;
}

