#pragma once
#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
// Internal struct for each Node
	struct Node {
		T data;
		Node* prev;
		Node* next;
	};

private:
	// Stores pointers to first and last nodes and count
	Node* head;
	Node* tail;
	// Total number of nodes
	unsigned int count;

public:
	LinkedList() { // Constructor
		head = new Node();
		tail = new Node();
		head->next = tail;
		head->prev = nullptr;
		tail->next = nullptr;
		tail->prev = head;
		count = 2;
	}
	LinkedList(const LinkedList<T>& list) { // Copy constructor
		head = new Node();
		tail = new Node();
		head->prev = nullptr;
		head->next = tail;
		tail->next = nullptr;
		tail->prev = head;
		count = list->count;

		Node* temp = list->head;
		for (size_t i = 1; i < list.count-1; i++) {
			addTail(temp->next.data);
			temp = temp->next;
		}
		temp = nullptr;
	}
	LinkedList(LinkedList<T>&& other) noexcept { // Move constructor
		head = other->head;
		other->head = nullptr;
		tail = other->tail;
		other->tail = nullptr;
		count = other->count;
		other->count = 0;
		// Should I move over every data point from the 'other' list?
	}
	LinkedList<T>& operator=(LinkedList<T>&& other) noexcept { // Move assignment
		if (this == &other) return *this;
		head = other->head;
		tail = other->tail;
		other->head = nullptr;
		other->tail = nullptr;
		return *this;
	}
	LinkedList<T>& operator=(const LinkedList<T>& rhs) { // Copy assignment
		if (this == &rhs) return *this;
		clear();
		count = rhs->count;
		head = new Node();
		tail = new Node();
		head->prev = nullptr;
		head->next = tail;
		tail->next = nullptr;
		tail->prev = head;

		Node* temp = rhs->head;
		for (size_t i = 1; i < count-1; i++) {
			addTail(temp->next.data);
			temp = temp->next;
		}
		temp = nullptr;
		return *this;
	}

	~LinkedList() { // Destructor
		clear();
	}

	// Behaviors
	void printForward() const { // Prints elements from head to tail.
		if (head) {
			Node* temp = head;
			while (temp->next->next) {
				std::cout << temp->next->data << std::endl;
				temp = temp->next;
			}
			temp = nullptr;
		}
	}
	void printReverse() const { // Prints elements from tail to head.
		if (tail) {
			Node* temp = tail;
			while (temp->prev->prev) {
				std::cout << temp->prev.data << std::endl;
				temp = temp->prev;
			}
			temp = nullptr;
		}
	}

	// Accessors
	[[nodiscard]] unsigned int getCount() const { return count; }
	Node* getHead() { return head; }
	const Node* getHead() const { return head; } // Does const getHead need a different implementation?
	Node* getTail() { return tail; }
	const Node* getTail() const { return tail; } // Does const getTail need a different implementation?

	// Insertion
	void addHead(const T& data) {
		Node* newHead = new Node;
		head->data = data;
		head->prev = newHead;
		newHead->prev = nullptr;
		newHead->next = head;
		head = newHead;
		count++;
	}
	void addTail(const T& data) {
		Node* newTail = new Node;
		tail->data = data;
		tail->next = newTail;
		newTail->next = nullptr;
		newTail->prev = tail;
		tail = newTail;
		count++;
	}

	// Removal
	bool removeHead() {
		if (!head) return false; // If there is no head (and therefore no nodes)
		if (!(head->next)) { // If head is the only node in the list
			delete head;
			head = nullptr;
			count--;
			return true;
		}
		Node* newHead = head->next;
		newHead->prev = nullptr;
		head->next = nullptr;
		// Remove/delete data?
		delete head;
		this->head = newHead;
		count--;
		return true;
	}
	bool removeTail() {
		if (!tail) return false; // If there is no tail (and therefore no nodes)
		if (!(tail->prev)) { // If tail is the only node in the list
			delete tail;
			tail = nullptr;
			count--;
			return true;
		}
		Node* newTail = tail->prev;
		newTail->next = nullptr;
		tail->prev = nullptr;
		// Remove/delete data?
		delete tail;
		tail = newTail;
		count--;
		return true;
	}
	void clear() {
		while (removeHead()) {}
		count = 0;
	}
};

