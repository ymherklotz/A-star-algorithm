#include "node.hpp"

Node::Node() : prev_index(-1), f_score(-1), g_score(0), h_score(-1), index(-1) {
}

bool operator<(const Node& n1, const Node& n2) {
	if(n1.f_score == n2.f_score)
		return n1.h_score < n2.h_score;
	return n1.f_score < n2.f_score;
}

bool operator==(const Node& n1, const Node& n2) {
	return n1.index == n2.index;
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
