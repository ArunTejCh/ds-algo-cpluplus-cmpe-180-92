/*
 * 9a_4.cpp
 *
 *  Created on: Oct 22, 2016
 *      Author: chennadi
 */

#include <vector>
#include <map>
using namespace std;

/**
   Makes a map associating letters with the number of words
   starting with that letter.
   @param words a vector of strings
   @return the map

*/
/*map<string, int> startingLetterFrequency(vector<string> words)
{
	   std::map<string, int> m;
	   vector<string>::iterator it;
	   for(it = words.begin(); it < words.end(); it++){
		   string cur = *it;
		  // m.insert ( std::pair<string,int>(cur.at(0), 1) );
		  string key = cur.substr(0,1);
		  m[key] = m[key] + 1;
	   }

	   return m;
}*/



