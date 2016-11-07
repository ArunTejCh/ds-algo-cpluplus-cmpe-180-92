/*
 * longest_word.cpp
 *
 *  Created on: Sep 19, 2016
 *      Author: chennadi
 */




#include <cstring>

using namespace std;

/**
   Given an array of strings of length n > 0, return the longest
   string. If there are multiple strings of the same maximum length,
   return the first one.
*/
char* longest(char** words, int n)
{
	int longestIndex = 0;
	int maxLength = 0;
    for(int i = 0; i < n; i++){
    	char *cur = words[i];
    	int curLength = 0;
    	while(cur[curLength] != '\0'){
    		curLength++;
    	}

    	if(curLength > maxLength){
    		maxLength = curLength;
    		longestIndex = i;
    	}
    }

    return words[longestIndex];
}
