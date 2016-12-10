#include "node.hpp"

Node::Node() : previous_node(NULL), f_score(-1), g_score(0), h_score(-1), x(0), y(0) {
}

void Node::set_x(int x_in) {
	x = x_in;
}

void Node::set_y(int y_in) {
	y = y_in;
}

void Node::set_h_score(int h) {
	h_score = h;
}

void Node::set_g_score(int g) {
	g_score = g;
}

void Node::compute_f() {
	f_score = g_score + h_score;
}

bool operator<(const Node& n1, const Node& n2) {
	if(n1.f_score == n2.f_score)
		return n1.h_score < n2.h_score;
	return n1.f_score < n2.f_score;
}

bool operator==(const Node& n1, const Node& n2) {
	return n1.f_score == n2.f_score;
}

bool operator>(const Node& n1, const Node& n2) {
	if(n1.f_score == n2.f_score)
		return n1.h_score > n2.h_score;
	return n1.f_score > n2.f_score;
}

bool operator<=(const Node& n1, const Node& n2) {
	return n1.f_score <= n2.f_score;
}

bool operator>=(const Node& n1, const Node& n2) {
	return n1.f_score >= n2.f_score;
}

bool operator!=(const Node& n1, const Node& n2) {
	return !(n1 == n2);
}

std::ostream& operator<<(std::ostream& out, const Node& n) {
	out << n.f_score;
	return out;
}
