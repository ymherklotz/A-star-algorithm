/*
 *
 * description:		Displays the A* Algorithm on a grid.
 *
 * author:          Yann Herklotz <ymherklotz@gmail.com>
 * date created:    DD-MM-YYYY
 *
 */

#include "priority_queue.hpp"

#include <iostream>

using namespace std;

int main() {
	PriorityQueue<int> pq;
	int i = 5;
	pq.push(i);
	int *i2 = &pq.pop();
	cout << "&i: " << &i << ", i2: " << i2 << endl;
	return 0;
}
