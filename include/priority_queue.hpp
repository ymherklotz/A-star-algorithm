#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include <iostream>

template<typename T>
class PriorityQueue {
public:
	PriorityQueue();
	~PriorityQueue();

	// pushes element to the queue which is sorted by smallest element first
	void push(const T& element);

	// pops the first element from the queue and removes it while returning
	// it
	T pop();
private:
	// size of the current queue
	unsigned int size;
	// capacity of the queue, this will just increase in multiples of 2
	unsigned int capacity;
	// array that will represent the priority queue
	T *priority_array;

	void resize_queue(double factor);

	void insert_queue(const T& element, const unsigned int& loc);

	T remove_queue(const unsigned int& loc);

	void delete_queue();
};

template<typename T>
PriorityQueue<T>::PriorityQueue() : size(0), capacity(1) {
	T *tmp_head = new T;

	std::cout << "constructor" << std::endl;

	priority_array = tmp_head;
}

template<typename T>
PriorityQueue<T>::~PriorityQueue() {
	std::cout << "destructor" << std::endl;
	delete[] priority_array;
}

template<typename T>
void PriorityQueue<T>::push(const T& element) {
	unsigned int insert_loc = 0;

	if(size == capacity)
		resize_queue(2);

	while(insert_loc < size && element > priority_array[insert_loc])
		++insert_loc;

	size++;

	insert_queue(element, insert_loc);
}

template<typename T>
T PriorityQueue<T>::pop() {
	if(!size)
		throw "Priority Queue is empty, no item to pop";
	else if(size - 1 == capacity / 2)
		resize_queue(0.5);

	size--;

	return remove_queue(0);
}

template<typename T>
void PriorityQueue<T>::resize_queue(double factor) {
	capacity = (double)capacity * factor;
	T *tmp_array = new T[capacity];

	for(unsigned int i = 0; i < size; ++i)
		tmp_array[i] = priority_array[i];

	delete[] priority_array;
	priority_array = tmp_array;
}

template<typename T>
void PriorityQueue<T>::insert_queue(const T& element, const unsigned int& loc) {
	T *tmp_array = new T[capacity];

	for(unsigned int i = 0; i < size; ++i)
		if(i == loc)
			tmp_array[i] = element;
		else if(i < loc)
			tmp_array[i] = priority_array[i];
		else
			tmp_array[i] = priority_array[i - 1];

	delete[] priority_array;
	priority_array = tmp_array;
}

template<typename T>
T PriorityQueue<T>::remove_queue(const unsigned int& loc) {
	T element;

	T *tmp_array = new T[capacity];

	for(unsigned int i = 0; i < size; ++i)
		if(i == loc)
			element = priority_array[i];
		else if(i < loc)
			tmp_array[i] = priority_array[i];
		else
			tmp_array[i - 1] = priority_array[i];

	delete[] priority_array;
	priority_array = tmp_array;

	return element;
}

#endif
