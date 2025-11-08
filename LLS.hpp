// LLS.hpp: Linked-List Stack. Last-in, First-out.
#pragma once

#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdexcept>

template <typename T>
class LLS : public StackInterface<T> {
private:
    LinkedList<T> list; // Internal container; Maintains stack order
public:
    // Constructor
    LLS() : list() {}
    // Copy constructor
    LLS(const LLS<T>& other) {
        list = other.list;
    }
    // Move constructor
    LLS(LLS<T>&& other) noexcept {
        list = std::move(other.list);
    }
    // Move assignment
    LLS<T>& operator=(LLS<T>&& other) noexcept {
        if (this == &other) return *this;
        list.clear();
        list = std::move(other.list);
        return *this;
    }
    // Copy assignment
    LLS<T>& operator=(const LLS<T>& rhs) {
        if (this == &rhs) return *this;
        list.clear();
        list = rhs.list;
        return *this;
    }
    // Destructor
    ~LLS() override {
        list.clear();
    }

    // Insertion: Adds node at head
    void push(const T& item) override {
        list.addHead(item);
    }

    // Deletion: Removes and returns head
    T pop() override {
        if (list.getCount() == 2) throw std::runtime_error("Stack is empty");
        T returnData = list.getHead()->next->data;
        list.removeHead();
        return returnData;
    }

    // Access: Returns head’s data
    T peek() const override {
        if (list.getCount() == 2) throw std::runtime_error("Stack is empty");
        return list.getHead()->prev->data;
    }

    // Getter: Returns node count
    [[nodiscard]] std::size_t getSize() const noexcept override {
        return list.getCount();
    }
};
