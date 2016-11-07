/*
 * problem2.cpp
 *
 *  Created on: Aug 30, 2016
 *      Author: chennadi
 */

#include <iostream>
using namespace std;

int problem2()
{
   cout << "Hours of first time: ";
   int hours1;
   cin >> hours1;
   cout << "Minutes of first time: ";
   int minutes1;
   cin >> minutes1;
   cout << "Hours of second time: ";
   int hours2;
   cin >> hours2;
   cout << "Minutes of second time: ";
   int minutes2;
   cin >> minutes2;
   cout << endl;

   // If the first time comes before the second time, print BEFORE
   // If the first time comes after the second time, print AFTER
   // If they are the same time, print SAME;

   int totalMinsOne = hours1 * 60 + minutes1;

   int totalMinsTwo = hours2 * 60 + minutes2;

   if(totalMinsOne < totalMinsTwo){
       cout  << "BEFORE"<< endl;
   }else if(totalMinsOne > totalMinsTwo){
       cout  << "AFTER"<< endl;
   }else {
       cout  << "SAME"<< endl;
   }

   return 0;
}



