#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

template<typename T>
struct queue_node {
	queue_node *next_node;
	T			item;

	queue_node(T& i) {
		item = i;
	}
};

template<typename T>
class PriorityQueue {
public:
	// creates a new object of type T
	PriorityQueue();
	// deletes the array priority_array so that there are no memory leaks
	~PriorityQueue();

	// pushes element to the queue which is sorted by smallest element first
	void push(T& element);

	// pops the first element from the queue and removes it while returning
	// it
	T& pop();
private:
	queue_node<T> *head_list;

	void delete_queue_node(queue_node<T> *node);
};

template<typename T>
PriorityQueue<T>::PriorityQueue() : head_list(nullptr) {
}

template<typename T>
PriorityQueue<T>::~PriorityQueue() {
	delete_queue_node(head_list);
}

template<typename T>
void PriorityQueue<T>::push(T& element) {
	queue_node<T> *el_node = new queue_node<T>(element);
	queue_node<T> *tmp_head = head_list;
	queue_node<T> *prev_head = head_list;

	while(tmp_head != nullptr && element > tmp_head->item) {
		prev_head = tmp_head;
		tmp_head = tmp_head->next_node;
	}

	// el_node->next_node = tmp_head;
	// prev_head->next_node = el_node;

	head_list = el_node;
}

template<typename T>
T& PriorityQueue<T>::pop() {
	T *element = &head_list->item;

	if(head_list->next_node != nullptr) {
		queue_node<T> *tmp_node = head_list;
		head_list = head_list->next_node;
		delete tmp_node;
	} else {
		delete head_list;
		head_list = nullptr;
	}

	return *element;
}

template<typename T>
void PriorityQueue<T>::delete_queue_node(queue_node<T> *node) {
	if(node != nullptr) {
		delete_queue_node(node->next_node);
		delete node;
	}
}

#endif // PRIORITY_QUEUE_HPP
