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
	n.set_f(65);
	n2.set_f(2);
	n3.set_f(6);
	n4.set_f(34);
	n5.set_f(75);
	n6.set_f(2);

	pq.push(n);
	pq.push(n2);
	pq.push(n3);
	pq.push(n4);
	pq.push(n5);
	pq.push(n6);

	cout << "First node in queue: " << pq.pop() << endl;
	cout << "Second node in queue: " << pq.pop() << endl;
	cout << "Third node in queue: " << pq.pop() << endl;
	cout << "Fourth node in queue: " << pq.pop() << endl;
	cout << "Fifth node in queue: " << pq.pop() << endl;
	cout << "Sixth node in queue: " << pq.pop() << endl;

	return 0;
}
