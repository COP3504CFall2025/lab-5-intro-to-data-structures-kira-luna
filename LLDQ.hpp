// LLDQ.hpp: Linked-List Deque
#pragma once

#include <cstddef>
#include <stdexcept>
#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <utility>

template <typename T>
class LLDQ : public DequeInterface<T> {
private:
    LinkedList<T> list; // Composition: Double-ended linked container

public:
    // Constructor
    LLDQ() : list() {}
    // Copy constructor
    LLDQ(const LLDQ<T>& other) {
        list = other.list;
    }
    // Move constructor
    LLDQ(LLDQ<T>&& other) noexcept {
        list = std::move(other.list);
    }
    // Move assignment
    LLDQ<T>& operator=(LLDQ<T>&& other) noexcept {
        if (this == &other) return *this;
        list.clear();
        list = std::move(other.list);
        return *this;
    }
    // Copy assignment
    LLDQ<T>& operator=(const LLDQ<T>& rhs) {
        if (this == &rhs) return *this;
        list.clear();
        list = rhs.list;
        return *this;
    }
    // Destructor
    ~LLDQ() override {
        list.clear();
    }

    // Core Insertion Operations
    // Insert head
    void pushFront(const T& item) override {
        list.addHead(item);
    }
    // Insert tail
    void pushBack(const T& item) override {
        list.addTail(item);
    }

    // Core Removal Operations: Remove from front/back
    T popFront() override {
        if (list.getCount() == 2) throw std::runtime_error("Deque is empty");
        T returnVal = list.getHead()->next->data;
        list.removeHead();
        return returnVal;
    }
    T popBack() override {
        if (list.getCount() == 2) throw std::runtime_error("Deque is empty");
        T returnVal = list.getTail()->prev->data;
        list.removeTail();
        return returnVal;
    }

    // Element Accessors: Retrieve end data
    const T& front() const override {
        if (list.getCount() == 2) throw std::runtime_error("Deque is empty");
        return list.getHead()->next->data;
    }
    const T& back() const override {
        if (list.getCount() == 2) throw std::runtime_error("Deque is empty");
        return list.getTail()->prev->data;
    }

    // Getter: Total nodes
    [[nodiscard]] std::size_t getSize() const noexcept override {
        return list.getCount();
    }
};

