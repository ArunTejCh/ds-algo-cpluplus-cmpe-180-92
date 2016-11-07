/*
 * problem5.cpp
 *
 *  Created on: Aug 31, 2016
 *      Author: chennadi
 */

#include <iostream>
#include <cstdlib>
using namespace std;

int problem5()
{
   cout << "Enter n: ";
   int n;
   cin >> n;


   // Draw the following "x in a box" pattern. There are n asterisks
   // on each side. In this example, n is 8.
   // ********
   // **    **
   // * *  * *
   // *  **  *
   // *  **  *
   // * *  * *
   // **    **
   // ********
   int i,j,k;
   k=0;
   for(i=0;i<n;i++){
	   for(j=0;j<n;j++){
		   if(i==0 || i==(n-1)){
			   cout << "*";
		   }else{
			   if(j == 0 || j == (n-1)){
				   cout << "*";
			   }else if(j == k || j == (n-1-k)){
				   cout << "*";
			   }else {
				   cout << " ";
			   }
		   }

	   }
	   k++;
	   cout << endl;
   }
   return 0;
}





