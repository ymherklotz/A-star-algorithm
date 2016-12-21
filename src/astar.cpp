#include "astar.hpp"

#include <cmath>
#include <iostream>

AStar::AStar(int *graph_in, const unsigned int& width, const unsigned int height) : graph(graph_in), graph_width(width), graph_height(height), graph_size(width * height), path_length(PATHLENGTH) {
	closed_set = new Node[graph_size];
	Node tmp;

	for(unsigned int i = 0; i < graph_size; ++i)
		closed_set[i] = tmp;

	find_start_end();
	open_set.clear();
}

AStar::AStar(const AStar& other) : open_set(other.open_set), closed_set(other.closed_set), graph(other.graph), graph_width(other.graph_width), graph_height(other.graph_height), graph_size(other.graph_size), path_length(PATHLENGTH), start_node(other.start_node), end_node(other.end_node) {
}

AStar::~AStar() {
	delete[] closed_set;
}

AStar& AStar::operator=(const AStar& other) {
	open_set = other.open_set;
	closed_set = other.closed_set;
	graph = other.graph;
	graph_width = other.graph_width;
	graph_height = other.graph_height;
	graph_size = other.graph_size;
	path_length = PATHLENGTH;
	start_node = other.start_node;
	end_node = other.end_node;
	return *this;
}

bool AStar::start_algorithm(int *curr_graph, const unsigned int& width, const unsigned int& height) {
	graph_width = width;
	graph_height = height;
	graph_size = width * height;

	graph = curr_graph;

	if(find_start_end())
		return start_algorithm();

	return false;
}

bool AStar::start_algorithm() {
	open_set.clear();
	find_start_end();
	open_set.push(start_node);
	while(open_set.first() != end_node) {
		Node current = open_set.pop();
		closed_set[current.index] = current;
		for(unsigned int i = 0; i < NEIGHBOUR_NUM; ++i) {
			Node n = get_neighbour(current, i);
			if(n.index != -1 && graph[n.index] != 1) {
				graph[n.index] = 9;
				int cost = current.g_score + path_length;
				if(open_set.check_item(n))
					if(cost < open_set[open_set.get_index(n)].g_score)
						open_set.remove_item(n);
				if(closed_set[n.index] == n) {
					if(cost < closed_set[n.index].g_score) {
						Node tmp;
						closed_set[n.index] = tmp;
					}
				}
				if(!open_set.check_item(n) && (closed_set[n.index] != n)) {
					n.g_score = cost;
					calc_heuristic(n);
					n.f_score = n.g_score + n.h_score;
					n.prev_index = current.index;
					open_set.push(n);
				}
			}
		}
	}
	recreate_path(open_set.first());
	return true;
}

void AStar::recreate_path(Node n) {
	while(n != start_node) {
		graph[n.index] = 8;
		n = closed_set[n.prev_index];
	}
}

bool AStar::find_start_end() {
	for(unsigned int i = 0; i < graph_size; ++i)
		if(graph[i] == 3) {
			start_node.index = i;
			start_node.g_score = 0;
			calc_heuristic(start_node);
			start_node.f_score = start_node.g_score + start_node.h_score;
			start_node.prev_index = -1;
		} else if(graph[i] == 2) {
			end_node.index = i;
		}
	open_set.push(start_node);
	Node n;
	return !(start_node == n || end_node == n);
}

Node AStar::get_neighbour(Node& n_in, const int& neighbour_num) {
	Node n;

	if(neighbour_num == 0 && n_in.index / graph_width > 0) {
		n.index -= graph_width;
		path_length = PATHLENGTH;
	} else if(neighbour_num == 1 && n_in.index % graph_width < graph_width - 1) {
		n.index += 1;
		path_length = PATHLENGTH;
	} else if(neighbour_num == 2 && n_in.index / graph_width < graph_height - 1) {
		n.index += graph_width;
		path_length = PATHLENGTH;
	} else if(neighbour_num == 3 && n_in.index % graph_width > 0) {
		n.index -= 1;
		path_length = PATHLENGTH;
	} else if(neighbour_num == 4 && n_in.index / graph_width > 0 && n_in.index % graph_width < graph_height - 1) {
		n.index -= graph_width + 1;
		path_length = DIAGLENGTH;
	} else if(neighbour_num == 5 && n_in.index / graph_width < graph_height - 1 && n_in.index % graph_width < graph_width - 1) {
		n.index += graph_width + 1;
		path_length = DIAGLENGTH;
	} else if(neighbour_num == 6 && n_in.index / graph_width < graph_height - 1 && n_in.index % graph_width > 0) {
		n.index -= graph_width - 1;
		path_length = DIAGLENGTH;
	} else if(neighbour_num == 7 && n_in.index / graph_width > 0 && n_in.index % graph_width > 0) {
		n.index -= graph_width - 1;
		path_length = DIAGLENGTH;
	}

	return n;
}

void AStar::reset_closed_set() {
	delete[] closed_set;
	closed_set = new Node[graph_size];
	Node tmp;

	for(unsigned int i = 0; i < graph_size; ++i)
		closed_set[i] = tmp;
}

void AStar::calc_heuristic(Node& n) {
	n.h_score = PATHLENGTH * sqrt(((end_node.index % graph_width - n.index % graph_width) * (end_node.index % graph_width - n.index % graph_width) + (end_node.index / graph_width - n.index / graph_width) * (end_node.index / graph_width - n.index / graph_width)));
}
