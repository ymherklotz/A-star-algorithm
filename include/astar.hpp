#ifndef ASTAR_HPP
#define ASTAR_HPP

#include "priority_queue.hpp"
#include "node.hpp"

#include <ostream>
#include <vector>

// defines the number of nodes one can go to
// we don't need this as we will have the queues
#define NEIGHBOUR_NUM 8

#define PATHLENGTH 10
#define DIAGLENGTH 14

// TODO add constructors and functions to calculate heuristics etc..
class AStar {
public:
	AStar(int *graph_in, const unsigned int& width, const unsigned int height);
	AStar(const AStar& other);
	~AStar();

	AStar& operator=(const AStar& other);

	bool start_algorithm(int *curr_graph, const unsigned int& width, const unsigned int& height);
	bool start_algorithm();

	void recreate_path(Node n);
private:
	PriorityQueue open_set;
	Node *closed_set;

	int *graph;
	unsigned int graph_width;
	unsigned int graph_height;
	unsigned int graph_size;
	int path_length;

	Node start_node, end_node;

	bool find_start_end();

	Node get_neighbour(Node& n_in, const int& neighbour_num);

	void reset_closed_set();

	void calc_heuristic(Node& n);
};

#endif // ASTAR_HPP
