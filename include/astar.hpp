#ifndef ASTAR_HPP
#define ASTAR_HPP

#include "priority_queue.hpp"
#include "node.hpp"

#include <ostream>
#include <vector>

// defines the number of nodes one can go to
// we don't need this as we will have the queues
#define NEIGHBOUR_NUM 4

// TODO add constructors and functions to calculate heuristics etc..
class AStar {
public:
	AStar();
	AStar(int *curr_graph, const unsigned int& width, const unsigned int& height);
private:
	PriorityQueue<Node> open_set;
	std::vector<Node> closed_set;

	int *graph;
	int graph_width;
	int graph_height;
	int path_length;

	Node start_node, end_node;

	bool start_algorithm();

	Node get_neighbour(Node& n_in, const int& neighbour_num);

	void calc_heuristic(Node& n);
	void calc_f(Node& n);

	bool check_item_vec(const Node& n);
	int get_index_vec(const Node& n);
	void remove_from_vec(const Node& n);
};

#endif // ASTAR_HPP
