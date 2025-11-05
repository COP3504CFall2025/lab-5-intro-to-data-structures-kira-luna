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
	// Construction/Destruction
	LinkedList() {
		head = new Node();
		tail = new Node();
		head.next = tail;
		head.prev = nullptr;
		tail.next = nullptr;
		tail.prev = head;
	}
	LinkedList(const LinkedList<T>& list);
	LinkedList(LinkedList<T>&& other) noexcept;
	~LinkedList();

	// Behaviors
	void printForward() const;
	void printReverse() const;

	// Accessors
	[[nodiscard]] unsigned int getCount() const;
	Node* getHead();
	const Node* getHead() const;
	Node* getTail();
	const Node* getTail() const;

	// Insertion
	void addHead(const T& data);
	void addTail(const T& data);

	// Removal
	bool removeHead();
	bool removeTail();
	void clear();

	// Operators
	LinkedList<T>& operator=(LinkedList<T>&& other) noexcept;
	LinkedList<T>& operator=(const LinkedList<T>& rhs);

};

