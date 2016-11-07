/*
 * problem2.cpp
 *
 *  Created on: Sep 4, 2016
 *      Author: chennadi
 */
/*
   Implement a function called surfaceArea that computes the surface
   area of a box. Choose appropriate types for the parameters and
   the return value.
   @param a, b, c the side lengths
   @return the surface area
*/
double surfaceArea(double a, double b, double c)
{
	return 2 * (a*b + b*c + a*c);
}



