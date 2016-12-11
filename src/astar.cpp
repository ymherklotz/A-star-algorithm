#include "astar.hpp"

#include <cmath>
#include <iostream>

AStar::AStar() : graph(NULL), graph_width(0), graph_height(0), path_length(1) {
}

AStar::AStar(int *curr_graph, const unsigned int& width, const unsigned int& height) : graph(curr_graph), graph_width(width), graph_height(height), path_length(1) {
	for(unsigned int i = 0; i < graph_width * graph_height; ++i)
		if(graph[i] == 3) {
			start_node.x = i % graph_width;
			start_node.y = i / graph_width;
			start_node.g_score = 0;
			calc_heuristic(start_node);
			calc_f(start_node);
		} else if(graph[i] == 2) {
			end_node.x = i % graph_width;
			end_node.y = i / graph_width;
		}
	open_set.push(start_node);
	start_algorithm();
}

bool AStar::start_algorithm(int *curr_graph, const unsigned int& width, const unsigned int& height) {
	graph_width = width;
	graph_height = height;
	graph = curr_graph;

	closed_set.clear();
	open_set.clear();

	for(unsigned int i = 0; i < graph_width * graph_height; ++i)
		if(graph[i] == 3) {
			start_node.x = i % graph_width;
			start_node.y = i / graph_width;
			start_node.g_score = 0;
			calc_heuristic(start_node);
			start_node.x_prev = -1;
			start_node.y_prev = -1;
			calc_f(start_node);
		} else if(graph[i] == 2) {
			end_node.x = i % graph_width;
			end_node.y = i / graph_width;
		}
	open_set.push(start_node);
	return start_algorithm();
}

bool AStar::start_algorithm() {
	while(open_set.get_first() != end_node) {
		Node current = open_set.pop();
		closed_set.push_back(current);
		for(unsigned int i = 0; i < NEIGHBOUR_NUM; ++i) {
			Node n = get_neighbour(current, i);

			if(graph[n.y * graph_width + n.x] != 1 && n.x != -1 && n.y != -1) {
				graph[n.x + n.y * graph_width] = 9;
				graph[start_node.x + start_node.y * graph_width] = 3;
				graph[end_node.x + end_node.y * graph_width] = 2;
				int cost = current.g_score + path_length;
				if(open_set.check_item(n))
					if(cost < open_set[open_set.get_index(n)].g_score)
						open_set.remove_item(n);
				if(check_item_vec(n))
					if(cost < closed_set[get_index_vec(n)].g_score)
						remove_from_vec(n);
				if(!open_set.check_item(n) && !check_item_vec(n)) {
					n.g_score = cost;
					calc_f(n);
					n.x_prev = current.x;
					n.y_prev = current.y;
					open_set.push(n);
				}
			}
		}
	}
	recreate_path(open_set.get_first());
	return true;
}

void AStar::recreate_path(Node n) {
	while(n.x != -1 && n.y != -1) {
		graph[n.x + n.y * graph_width] = 8;
		n = find_node(n.x_prev, n.y_prev);
	}
}

Node AStar::get_neighbour(Node& n_in, const int& neighbour_num) {
	Node n;

	if(neighbour_num == 0 && n_in.y > 0) {
		n.x = n_in.x;
		n.y = n_in.y - 1;
	} else if(neighbour_num == 1 && n_in.x < graph_width - 1) {
		n.x = n_in.x + 1;
		n.y = n_in.y;
	} else if(neighbour_num == 2 && n_in.y < graph_height - 1) {
		n.x = n_in.x;
		n.y = n_in.y + 1;
	} else if(neighbour_num == 3 && n_in.x > 0) {
		n.x = n_in.x - 1;
		n.y = n_in.y;
	}

	calc_heuristic(n);

	return n;
}

void AStar::calc_heuristic(Node& n) {
	n.h_score = path_length * (abs(n.x - end_node.x) + abs(n.y - end_node.y));
}

void AStar::calc_f(Node& n) {
	n.f_score = n.g_score + n.h_score;
}

bool AStar::check_item_vec(const Node& n) {
	for(unsigned int i = 0; i < closed_set.size(); ++i)
		if(closed_set[i] == n)
			return true;
	return false;
}

int AStar::get_index_vec(const Node& n) {
	for(unsigned int i = 0; i < closed_set.size(); ++i)
		if(closed_set[i] == n)
			return i;
	return -1;
}

void AStar::remove_from_vec(const Node& n) {
	std::vector<Node> tmp_set;
	for(unsigned int i = 0; i < closed_set.size(); ++i)
		if(closed_set[i] != n)
			tmp_set.push_back(closed_set[i]);
	closed_set = tmp_set;
}

Node AStar::find_node(const unsigned int& x, const unsigned int& y) {
	Node n;

	for(unsigned int i = 0; i < closed_set.size(); ++i)
		if(closed_set[i].x == x && closed_set[i].y == y)
			n = closed_set[i];
	return n;
}
