// Abstract Base Classes for Data Structures Interfaces
#pragma once
#include <cstddef>
#include <stdexcept>

template <typename T>
class StackInterface { // Defines standard LIFO (Last-In-First-Out) operations:
    virtual ~StackInterface() = default;
    virtual void push(const T& item) = 0;
    virtual T pop() = 0;
    virtual T peek() const = 0;
    virtual std::size_t getSize() const noexcept = 0;
};


template <typename T>
class QueueInterface { // Defines standard FIFO (First-In-First-Out) operations:
    virtual ~QueueInterface() = default;
    virtual void enqueue(const T& item) = 0;
    virtual T dequeue() = 0;
    virtual T peek() const = 0;
    virtual std::size_t getSize() const noexcept = 0;
};


template <typename T>
class DequeInterface { // Defines double-ended sequential access operations:
    virtual ~DequeInterface() = default;
    virtual void pushFront(const T& item) = 0;
    virtual void pushBack(const T& item) = 0;
    virtual T popFront() = 0;
    virtual T popBack() = 0;
    virtual const T& front() const = 0;
    virtual const T& back() const = 0;
    virtual std::size_t getSize() const noexcept = 0;
};

