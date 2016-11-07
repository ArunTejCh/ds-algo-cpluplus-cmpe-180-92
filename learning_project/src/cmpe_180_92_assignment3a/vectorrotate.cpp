/*

 * vectorrotate.cpp
 *
 *  Created on: Sep 13, 2016
 *      Author: chennadi

#include <vector>
#include <stdlib.h>
using namespace std;

*
   Rotates a vector one position to the left.
   Returns the rotated vector without modifying the
   original.
   @param a a vector of integers
   @return the rotated vector. For example, if a is {3, 1, 4, 1, 5, 9}
   then a vector {1, 4, 1, 5, 9, 3} is returned.

vector<int> rot(const vector<int>& a)
{
   vector<int> copy = a;

   for(int i = 0; i < a.size() - 1; i++ ){
       copy[i] = a [i+1];
   }
   copy[a.size() - 1] = a[0];

    return copy;
}




*/
