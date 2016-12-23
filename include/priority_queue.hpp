#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include "node.hpp"

class PriorityQueue {
public:
	// creates a new object of type Node
	PriorityQueue();
	// deletes the array priority_array so that there are no memory leaks
	~PriorityQueue();

	// pushes element to the queue which is sorted by smallest element first
	void push(const Node& element);

	// pops the first element from the queue and removes it while returning
	// it
	Node pop();

	// returns the lowest priority item
	Node first();

	// check if item is in queue
	bool check_item(const Node& item);

	// gets index of item
	int get_index(const Node& item);

	// removes item from queue
	void remove_item(const Node& item);

	void clear();

	// return element at position;
	const Node& at(const unsigned int& i) const;

	const Node& operator[](const unsigned int& i) const;
private:
	// size of the current queue
	unsigned int size;
	// capacity of the queue, this will just increase in multiples of 2
	unsigned int capacity;
	// array that will represent the priority queue
	Node *priority_array;

	// resize the queue's array accordingly by some factor
	void resize_queue(double factor);

	// insert and element into the queue
	// this assumes that the capacity is larger than the size
	void insert_queue(const Node& element, const unsigned int& loc);

	// removes an element from the queue
	Node remove_queue(const unsigned int& loc);
};

#endif // PRIORITY_QUEUE_HPP
