/*
 * problem5.cpp
 *
 *  Created on: Sep 4, 2016
 *      Author: chennadi
 */
/**
   We have three t-shirts in sizes small, medium, and large.
   Write a function that takes the weights of three people
   and sets them so that the first parameter becomes
   the weight of the person who should get the small shirt
   (i.e. the lightest one), the second one becomes the weight
   of the person who should get the medium one (i.e. the
   second-lightest one), and the third parameter becomes
   the weight of the person who should get the largest one.
*/
void smlShirts(int& first, int& second, int& third)
{
    int temp = 0;

    if(first > second){
        temp = second;
        second = first;
        first = temp;
    }

    if(second > third){
        temp = third;
        third = second;
        second = temp;
    }

    if(first > second){
        temp = second;
        second = first;
        first = temp;
    }

}



