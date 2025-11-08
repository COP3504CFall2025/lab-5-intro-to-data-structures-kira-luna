// LLQ.hpp: Linked-List Queue (First in, first out)
#pragma once

#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdexcept>

template <typename T>
class LLQ : public QueueInterface<T> {
private:
    LinkedList<T> list; // Internal member: Implements FIFO
public:
    // Constructor
    LLQ() : list() {}
    // Copy constructor
    LLQ(const LLQ<T>& other) {
        list = other.list;
    }
    // Move constructor
    LLQ(LLQ<T>&& other) noexcept {
        list = std::move(other.list);
    }
    // Move assignment
    LLQ<T>& operator=(LLQ<T>&& other) noexcept {
        if (this == &other) return *this;
        list.clear();
        list = std::move(other.list);
        return *this;
    }
    // Copy assignment
    LLQ<T>& operator=(const LLQ<T>& rhs) {
        if (this == &rhs) return *this;
        list.clear();
        list = rhs.list;
        return *this;
    }
    // Destructor
    ~LLQ() override {
        list.clear();
    }

    // Insertion: Adds new tail node
    void enqueue(const T& item) override {
        list.addTail(item);
    }

    // Deletion: Removes head node
    T dequeue() override {
        if (list.getCount() == 2) throw std::runtime_error("Queue is empty");
        T returnData = list.getHead()->next->data;
        list.removeHead();
        return returnData;
    }

    // Access: Returns head data
    T peek() const override {
        if (list.getCount() == 2) throw std::runtime_error("Queue is empty");
        return list.getHead()->next->data;
    }

    // Getter: Returns list count
    [[nodiscard]] std::size_t getSize() const noexcept override {
        return list.getCount();
    }
};