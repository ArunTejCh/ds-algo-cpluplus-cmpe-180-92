/*
 * words_split.cpp
 *
 *  Created on: Sep 19, 2016
 *      Author: chennadi
 */
#include <cstring>

using namespace std;

/**
   Given a '\0'-terminated character array, split it by replacing
   each space in the character array with a '\0'. Return the number
   of strings into which you have split the input.
*/
int split(char* words)
{
   int noOfStrings = 1;

   int i = 0;

   while(words[i] != '\0'){
	   if(words[i] == ' '){
		   noOfStrings++;
		   words[i] = '\0';
	   }
	   i++;
   }
   return noOfStrings;
}




