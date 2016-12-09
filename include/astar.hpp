#ifndef ASTAR_HPP
#define ASTAR_HPP

#include <ostream>

#define NEIGHBOUR_NUM 4

class AStar {
public:
private:
};

class Node {
public:
	Node();
	Node(Node *prev_node);
	Node(Node *prev_node, int g);
	~Node();

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
	Node *next_nodes[NEIGHBOUR_NUM];

	// score that is used to compare to other nodes to see if the other path is
	// more efficient.
	int f_score;
	// path length to get to that node.
	int g_score;
	// heulistic length to destination.
	int h_score;

	// see if node has been visited.
	bool visited;

	// updates the f_score accordingly.
	void update_f_score();
};

#endif
