#include "astar.hpp"

Node::Node() : previous_node(NULL), f_score(-1), g_score(0), h_score(-1), visited(false) {
	for(unsigned int i = 0; i < NEIGHBOUR_NUM; ++i)
		next_nodes[i] = NULL;
	update_f_score();
}

Node::Node(Node *prev_node) : previous_node(prev_node), f_score(-1), g_score(0), h_score(-1), visited(false) {
	for(unsigned int i = 0; i < NEIGHBOUR_NUM; ++i)
		next_nodes[i] = NULL;
	update_f_score();
}

Node::Node(Node *prev_node, int g) : previous_node(prev_node), f_score(-1), g_score(g), h_score(-1), visited(false) {
	for(unsigned int i = 0; i < NEIGHBOUR_NUM; ++i)
		next_nodes[i] = NULL;
	update_f_score();
}

Node::~Node() {
}

bool operator<(const Node& n1, const Node& n2) {
	return n1.f_score < n2.f_score;
}

bool operator==(const Node& n1, const Node& n2) {
	return n1.f_score == n2.f_score;
}

bool operator>(const Node& n1, const Node& n2) {
	return !(n1 < n2) && !(n1 == n2);
}

bool operator<=(const Node& n1, const Node& n2) {
	return (n1 < n2) || (n1 == n2);
}

bool operator>=(const Node& n1, const Node& n2) {
	return !(n1 < n2);
}

bool operator!=(const Node& n1, const Node& n2) {
	return !(n1 == n2);
}

std::ostream& operator<<(std::ostream& out, const Node& n) {
	out << n.f_score;
	return out;
}

void Node::update_f_score() {
	f_score = g_score + h_score;
}