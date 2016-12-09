#ifndef ASTAR_HPP
#define ASTAR_HPP

#include <ostream>

// defines the number of nodes one can go to
// we don't need this as we will have the queues
//#define NEIGHBOUR_NUM 4

// TODO add constructors and functions to calculate heuristics etc..
class AStar {
public:
private:
};

class Node {
public:
	// TODO These constructors have to change
	Node();

	// overloading operators for ease of use.
	friend bool operator<(const Node& n1, const Node& n2);
	friend bool operator==(const Node& n1, const Node& n2);
	friend bool operator>(const Node& n1, const Node& n2);
	friend bool operator<=(const Node& n1, const Node& n2);
	friend bool operator>=(const Node& n1, const Node& n2);
	friend bool operator!=(const Node& n1, const Node& n2);
	friend std::ostream& operator<<(std::ostream& out, const Node& n);
private:
	// pointer to previous node so that I can backtrack without using recursion.
	Node *previous_node;
	// pointers to the next nodes of which there are 4 in a grid.
	// We do not need this as we are implementing a priority queue;
	//Node *next_nodes[NEIGHBOUR_NUM];

	// score that is used to compare to other nodes to see if the other path is
	// more efficient.
	int f_score;
	// path length to get to that node.
	int g_score;
	// heulistic length to destination.
	int h_score;

	// see if node has been visited.
	// We don't need this as we will have an open and a closed set
	//bool visited;

	// updates the f_score accordingly.
	void update_f_score();
};

#endif
