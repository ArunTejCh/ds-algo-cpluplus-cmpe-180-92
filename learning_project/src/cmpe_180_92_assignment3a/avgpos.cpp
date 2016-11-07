/*
 * avgpos.cpp
 *
 *  Created on: Sep 13, 2016
 *      Author: chennadi
 */




/**
   Computes the average of all positive elements in the given array.
   @param a an array of integers
   @param alen the number of elements in a
   @return the average of all positive elements in a, or 0 if there are none.
*/
double avgpos(int a[], int alen)
{
   int total,count;
   total = 0;
   count = 0;

   for(int i = 0; i < alen; i++){
       if(a[i] > 0){
           total = total + a[i];
           count++;
       }
   }

   if(total == 0){
       return 0;
   }else{
       return (1.0 * total)/count;
   }
}

