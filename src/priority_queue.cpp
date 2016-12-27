#include "priority_queue.hpp"

#include <iostream>

PriorityQueue::PriorityQueue() : size(0), capacity(1) {
	priority_array = new Node;
}


PriorityQueue::~PriorityQueue() {
	delete[] priority_array;
}


void PriorityQueue::push(const Node& element) {
	unsigned int insert_loc = 0;

	if(size == capacity)
		resize_queue(2);

	while(insert_loc < size && element > priority_array[insert_loc])
		++insert_loc;

	insert_queue(element, insert_loc);
}


Node PriorityQueue::pop() {
	if(!size)
		throw "Priority Queue is empty, no item to pop";
	else if(size == capacity / 2)
		resize_queue(0.5);

	Node tmp = remove_queue(0);
	return tmp;
}


Node PriorityQueue::first() {
	return priority_array[0];
}


bool PriorityQueue::check_item(const Node& item) {
	for(unsigned int i = 0; i < size; ++i)
		if(priority_array[i] == item)
			return true;
	return false;
}


int PriorityQueue::get_index(const Node& item) {
	for(unsigned int i = 0; i < size; ++i)
		if(priority_array[i] == item)
			return i;
	return -1;
}


void PriorityQueue::remove_item(const Node& item) {
	remove_queue(get_index(item));
}


void PriorityQueue::clear() {
	Node *tmp = new Node;

	delete[] priority_array;

	size = 0;
	capacity = 1;
	priority_array = tmp;
}


const Node& PriorityQueue::at(const unsigned int& i) const {
	return priority_array[i];
}


const Node& PriorityQueue::operator[](const unsigned int& i) const {
	return priority_array[i];
}


void PriorityQueue::resize_queue(double factor) {
	capacity = (double)capacity * factor;
	Node *tmp_array = new Node[capacity];

	for(unsigned int i = 0; i < size; ++i)
		tmp_array[i] = priority_array[i];

	delete[] priority_array;
	priority_array = tmp_array;
}


void PriorityQueue::insert_queue(const Node& element, const unsigned int& loc) {
	Node *tmp_array = new Node[capacity];

	for(unsigned int i = 0; i < size + 1; ++i)
		if(i == loc)
			tmp_array[i] = element;
		else if(i < loc)
			tmp_array[i] = priority_array[i];
		else
			tmp_array[i] = priority_array[i - 1];

	size++;

	delete[] priority_array;
	priority_array = tmp_array;
}


Node PriorityQueue::remove_queue(const unsigned int& loc) {
	Node element;

	Node *tmp_array = new Node[capacity];

	for(unsigned int i = 0; i < size; ++i)
		if(i == loc)
			element = priority_array[i];
		else if(i < loc)
			tmp_array[i] = priority_array[i];
		else
			tmp_array[i - 1] = priority_array[i];

	size--;

	delete[] priority_array;
	priority_array = tmp_array;

	return element;
}
