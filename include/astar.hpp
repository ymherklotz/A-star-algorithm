#ifndef ASTAR_HPP
#define ASTAR_HPP

#include "priority_queue.hpp"
#include "node.hpp"

#include <ostream>
#include <vector>

// defines the number of nodes one can go to
// we don't need this as we will have the queues
//#define NEIGHBOUR_NUM 4

// TODO add constructors and functions to calculate heuristics etc..
class AStar {
public:
	AStar(int *curr_graph, const unsigned int& width, const unsigned int& height);
private:
	PriorityQueue<Node> open_set;
	std::vector<Node> closed_set;

	int *graph;
	int graph_width;
	int graph_height;

	Node current_node, start_node, end_node;

	void set_start_end();

	Node get_neighbour(const Node& n_in, const int& neighbour_num);

	void calc_heuristic(Node& n);
};

#endif // ASTAR_HPP
