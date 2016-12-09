/*
 *
 * description:		Displays the A* Algorithm on a grid.
 *
 * author:          Yann Herklotz <ymherklotz@gmail.com>
 * date created:    DD-MM-YYYY
 *
 */

#include "tilemap.hpp"
#include "astar.hpp"
#include "priority_queue.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	PriorityQueue<int> pq;

	pq.push(5);
	pq.push(2);
	pq.push(3);
	pq.push(8);
	pq.push(19);
	pq.push(1);

	cout << pq.pop() << " " << pq.pop() << " " << pq.pop() << endl;
	return 0;
}
