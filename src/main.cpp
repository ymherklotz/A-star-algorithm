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
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	PriorityQueue<Node> pq;

	Node n, n2, n3, n4, n5, n6;
	pq.push(n);
	pq.push(n2);
	pq.push(n3);
	pq.push(n4);
	pq.push(n5);
	pq.push(n6);

	cout << "Node in first queue: " << pq.pop() << endl;

	return 0;
}
