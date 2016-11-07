/*
 * problem1.cpp
 *
 *  Created on: Aug 30, 2016
 *      Author: chennadi
 */
#include <iostream>
#include "problem1.h"
using namespace std;

int computeNormalizedTime()
{
   cout << "Hours: ";
   int hours;
   cin >> hours;
   cout << "Minutes: ";
   int minutes;
   cin >> minutes;
   cout << "Minutes to add: ";
   int minutesToAdd;
   cin >> minutesToAdd;

   // Add minutesToAdd minutes to the given hours/minutes
   // and normalize hours/minutes to military time (so that
   // hours is between 0 and 23 and minutes between 0 and 59)

   int hoursToAdd = (int) minutesToAdd/60;
   int minutesToAddNormalized = minutesToAdd % 60;

   cout << endl << "temp: " << hoursToAdd << ":" << minutesToAddNormalized << endl;

   hours = hours + hoursToAdd;

   if(hours >= 24){
        hours = hours - 24;
   }

   cout << endl << "Result: " << hours << ":" << minutes << endl;
   return 0;
}
