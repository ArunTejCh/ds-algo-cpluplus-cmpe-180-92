/*

 * reverse_array.cpp
 *
 *  Created on: Sep 19, 2016
 *      Author: chennadi


*
 Given pointers start and end that point to the
 first and past the last element of a segment inside
 an array, return a new array holding the reverse
 of the segment.

int* reverse(int* start, int* end) {
	int* cur, *front, *back;

	int segLength = 0;
	cur = start;
	while (cur != end) {
		segLength++;
		cur++;
	}

	int ret[] = new int(segLength);

	for (int i = 0; i < (segLength / 2); i++) {
		front = start + i;
		back = end - 1 - i;

		ret[i] = *front;
		ret[segLength - 1 - i] = *back;
	}

	return &ret;
}
*/
