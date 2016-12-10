#include "astar.hpp"

AStar::AStar(int *curr_graph, const unsigned int& width, const unsigned int& height) : graph(curr_graph), graph_width(width), graph_height(height) {
	set_start_end();
	open_set.push(start_node);
}

void AStar::set_start_end() {
	for(unsigned int i = 0; i < graph_width * graph_height; ++i)
		if(graph[i] == 3) {
			start_node.x = i % graph_width;
			start_node.y = i / graph_width;
			start_node.g_score = 0;
		} else if(graph[i] == 2) {
			end_node.x = i % graph_width;
			end_node.y = i / graph_width;
			end_node.h_score = 0;
		}
}

Node AStar::get_neighbour(const Node& n_in, const int& neighbour_num) {
	if(neighbour_num == 0) {
	}
}

void AStar::calc_heuristic(Node& n) {
}
