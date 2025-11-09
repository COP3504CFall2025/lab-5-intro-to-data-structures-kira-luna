// Array-Based Stack: ABS.hpp. Last-in, First-out.
#pragma once

#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "Interfaces.hpp"
#include "LinkedList.hpp"

// Technically bad, but size_t isn't likely to conflict with any client code.
using std::size_t;

template<typename T>
class ABS : public StackInterface<T> {
private:
    size_t capacity_; // Total allocated slots
    size_t curr_size_; // Current stack depth
    T* array_; // Pointer to dynamic array storing elements
    static constexpr size_t scale_factor_ = 2;

public:
    // Big 5 + Parameterized Constructor
    // Default Constructor. Default capacity_ to 1, size_ to 0, and create buffer array data_.
    ABS() : capacity_(1), curr_size_(0), array_(new T[1]) {}
    // Parameterized Constructor. Same behavior as default, however set capacity_ to capacity
    explicit ABS(const size_t capacity) : capacity_(capacity), curr_size_(0), array_(new T[capacity]) {}
    // Copy constructor
    ABS(const ABS& other) {
        capacity_ = other.capacity_;
        curr_size_ = other.curr_size_;
        array_ = new T[other.capacity_];
        for (size_t i = 0; i < curr_size_; i++) {
            array_[i] = other.array_[i];
        }
    }
    // Copy assignment
    ABS& operator=(const ABS& rhs) {
        if (this == &rhs) return *this;
        capacity_ = rhs.capacity_;
        curr_size_ = rhs.curr_size_;
        delete[] array_;
        array_ = new T[capacity_];
        for (size_t i = 0; i < curr_size_; i++) {
            array_[i] = rhs.array_[i];
        }
        return *this;
    }
    // Move constructor
    ABS(ABS&& other) noexcept {
        capacity_ = other.capacity_;
        other.capacity_ = 0;
        curr_size_ = other.curr_size_;
        other.curr_size_ = 0;
        array_ = other.array_;
        other.array_ = nullptr;
    }
    // Move assignment
    ABS& operator=(ABS&& rhs) noexcept {
        if (this == &rhs) return *this;
        capacity_ = rhs.capacity_;
        rhs.capacity_ = 0;
        curr_size_ = rhs.curr_size_;
        rhs.curr_size_ = 0;
        array_ = rhs.array_;
        rhs.array_ = nullptr;
        return *this;
    }
    // Destructor
    ~ABS() noexcept override {
        capacity_ = 0;
        curr_size_ = 0;
        delete[] array_;
        array_ = nullptr;
    }

    // Getters
    [[nodiscard]] size_t getSize() const noexcept override { return curr_size_; }
    [[nodiscard]] size_t getMaxCapacity() const noexcept { return capacity_; }
    [[nodiscard]] T* getData() const noexcept { return array_; }

    // Push item onto the top of the stack (end of the array)
    void push(const T& data) override {
        // If size exceeds capacity, doubling the size of the array
        if (curr_size_ >= capacity_) {
            capacity_ *= scale_factor_;
            T* temp = new T[capacity_];
            for (size_t i = 0; i < curr_size_; ++i) {
                temp[i] = array_[i];
            }
            delete[] array_;
            array_ = temp;
            temp = nullptr;
        }
        array_[curr_size_] = data;
        curr_size_++;
    }

    // Returns top element
    T peek() const override {
        if (curr_size_ == 0) throw std::runtime_error("Stack is empty");
        return array_[curr_size_-1];
    }

    // Removes and returns the last inserted element
    T pop() override {
        if (curr_size_ == 0) throw std::runtime_error("Stack is empty");
        T returnVal = array_[curr_size_-1];
        curr_size_--;
        // If size is 1/4 capacity, halving capacity and moving to smaller array
        if (curr_size_ * 4 <= capacity_) {
            capacity_ /= 2;
            T* temp = new T[capacity_];
            for (size_t i = 0; i < curr_size_; ++i) {
                temp[i] = array_[i];
            }
            delete[] array_;
            array_ = temp;
            temp = nullptr;
        }
        // array_[curr_size_] = 0;
        return returnVal;
    }
};
