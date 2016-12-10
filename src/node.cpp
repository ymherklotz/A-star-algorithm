#include "node.hpp"

Node::Node() : previous_node(NULL), f_score(-1), g_score(0), h_score(-1), x(0), y(0) {
}

bool operator<(const Node& n1, const Node& n2) {
	if(n1.f_score == n2.f_score)
		return n1.h_score < n2.h_score;
	return n1.f_score < n2.f_score;
}

bool operator==(const Node& n1, const Node& n2) {
	return n1.x == n2.x && n1.y == n2.y;
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
