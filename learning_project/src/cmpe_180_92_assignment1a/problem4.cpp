//============================================================================
// Name        : learning_project.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int problem4()
{
	cout << "Enter values, -1 when done: " << endl;
	   int result = -1;
	   int minDistance;
	   int current;

	   do{
	       cin >> current;
	       if(result == -1){
	           result = current;
	           minDistance = abs(100 - current);
	       }else{
	            int currentDistance = abs (100 - current);
	            if(currentDistance < minDistance){
	                result = current;
	                minDistance = currentDistance;
	            }
	       }
	   }while(current != -1);

	   // Read in numbers from cin. Stop when a value of -1 is entered.
	   // Print the input that is closest to 100. If there are multiple
	   // inputs that have the same minimal distance 100,
	   // print the first one.
	   // If no input was provided (other than the -1 sentinel),
	   // print -1

	   cout << endl << "Result: " << result << endl;
	   return 0;
}
