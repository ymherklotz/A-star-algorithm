#ifndef ASTAR_HPP
#define ASTAR_HPP

#include "priority_queue.hpp"
#include "node.hpp"

#include <ostream>

// defines the number of nodes one can go to
// we don't need this as we will have the queues
//#define NEIGHBOUR_NUM 4

// TODO add constructors and functions to calculate heuristics etc..
class AStar {
public:
	AStar();
private:
	PriorityQueue<Node> open_set;
	Node current;
};

#endif // ASTAR_HPP
