#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include "positive_avg.h"
using namespace std;


/*
  Read numbers from standard input and print the average of
  all positive numbers, with two digits after the decimal point.

  The end of input is indicated by a number 0. For example,
  if the input is

  1 2 4 -3 5 -6 0

  then you print "Average: 3.00". If there are no positive elements,
  print "Average: 0.00".
*/

int compute_avg()
{
   int cur,total,count;
   total = 0;
   count = 0;

   while(cin >> cur){
	   if(cur > 0){
		   count++;
		   total = total + cur;
	   }else if(cur == 0){
		   double avg = 0;
		   if(total != 0){
			   avg = (1.0 * total)/count;
		   }
		   cout.setf(ios::fixed);
		   cout.setf(ios::showpoint);
		   cout.precision(2);

		   cout << "Average: " << setprecision(2) << avg << endl;
		   return 0;
	   }
   }
   return 0;
}
