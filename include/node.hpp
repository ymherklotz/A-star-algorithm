#ifndef NODE_HPP
#define NODE_HPP

#include <ostream>

class AStar;

class Node {
	friend AStar;
public:
	Node();

	void set_x(int x_in);
	void set_y(int y_in);
	void set_h_score(int h);
	void set_g_score(int g);

	void compute_f();

	// overloading operators for ease of use.
	friend bool operator<(const Node& n1, const Node& n2);
	friend bool operator==(const Node& n1, const Node& n2);
	friend bool operator>(const Node & n1, const Node & n2);
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
// heuristic length to destination.
	int h_score;

// the x and y coordinates of the node in the grid
	int x, y;

// see if node has been visited.
// We don't need this as we will have an open and a closed set
//bool visited;
};

#endif // NODE_HPP
