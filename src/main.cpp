/*
 *
 * description:		Displays the A* Algorithm on a grid.
 *
 * author:          Yann Herklotz <ymherklotz@gmail.com>
 * date created:    DD-MM-YYYY
 *
 */

#include "astar.hpp"
#include "priority_queue.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int graph[9] = {
		3, 0, 0,
		0, 1, 1,
		0, 0, 2
	};
	AStar a(graph, 3, 3);

	return 0;
}
