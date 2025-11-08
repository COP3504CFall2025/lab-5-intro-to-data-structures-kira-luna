// ABQ.hpp: Array-Based Queue (First In, First Out)
#pragma once

#include <cstddef>
#include <stdexcept>
#include "Interfaces.hpp"

// Technically bad, but size_t isn't likely to conflict with any client code.
using std::size_t;

template<typename T>
class ABQ : public QueueInterface<T>{

    size_t capacity_; // Total buffer size
    size_t curr_size_; // Number of active elements
    T* array_; // Dynamic storage
    size_t front_;
    size_t back_;
    static constexpr size_t scale_factor_ = 2;

public:
    // Constructors + Big 5
    // Default constructor. Default capacity_ to 1, size_ to 0, and create buffer array data_.
    ABQ() : capacity_(1), curr_size_(0), array_(new T[1]), front_(0), back_(0) {}
    // Parameterized Constructor. Same behavior as default, however set capacity_ to capacity
    explicit ABQ(const size_t capacity) : capacity_(capacity), curr_size_(0), front_(0), back_(0) {
        array_ = new T[capacity_];
    }
    // Copy constructor
    ABQ(const ABQ& other) {
        capacity_ = other.capacity_;
        curr_size_ = other.curr_size_;
        front_ = other.front_;
        back_ = other.back_;
        array_ = new T[other.capacity_];
        for (size_t i = 0; i < curr_size_; i++) {
            array_[i] = other.array_[i];
        }
    }
    // Copy assignment
    ABQ& operator=(const ABQ& rhs) {
        if (this == &rhs) return *this;
        capacity_ = rhs.capacity_;
        curr_size_ = rhs.curr_size_;
        front_ = rhs.front_;
        back_ = rhs.back_;
        delete[] array_;
        array_ = new T[capacity_];
        for (size_t i = 0; i < curr_size_; i++) {
            array_[i] = rhs.array_[i];
        }
        return *this;
    }
    // Move constructor
    ABQ(ABQ&& other) noexcept {
        capacity_ = other.capacity_;
        other.capacity_ = 0;
        curr_size_ = other.curr_size_;
        other.curr_size_ = 0;
        front_ = other.front_;
        other.front_ = 0;
        back_ = other.back_;
        other.back_ = 0;
        array_ = other.array_;
        other.array_ = nullptr;
    }
    // Move assignment
    ABQ& operator=(ABQ&& rhs) noexcept {
        if (this == &rhs) return *this;
        capacity_ = rhs.capacity_;
        rhs.capacity_ = 0;
        curr_size_ = rhs.curr_size_;
        rhs.curr_size_ = 0;
        array_ = rhs.array_;
        rhs.array_ = nullptr;
        front_ = rhs.front_;
        rhs.front_ = 0;
        back_ = rhs.back_;
        rhs.back_ = 0;
        return *this;
    }
    // Destructor
    ~ABQ() noexcept override {
        capacity_ = 0;
        curr_size_ = 0;
        front_ = 0;
        back_ = 0;
        delete[] array_;
        array_ = nullptr;
    }

    // Getters
    [[nodiscard]] size_t getSize() const noexcept override { return curr_size_; }
    [[nodiscard]] size_t getMaxCapacity() const noexcept { return capacity_; }
    [[nodiscard]] T* getData() const noexcept { return array_; }

    // Insertion: Adds element to back
    void enqueue(const T& data) override {
        // If size exceeds capacity, doubling the size of the array
        if (curr_size_ >= capacity_) {
            capacity_ *= scale_factor_;
            T* temp = new T[capacity_];
            for (size_t i = 0; i < curr_size_; ++i) {
                temp[i] = array_[(front_ + i) % capacity_];
            }
            delete[] array_;
            array_ = temp;
            front_ = 0;
            back_ = curr_size_;
        }
        array_[back_] = data;
        back_ = (back_ + 1) % capacity_;
        curr_size_++;
    }

    // Access: Returns front element
    T peek() const override {
        if (curr_size_ == 0) throw std::runtime_error("Stack is empty");
        return array_[front_];
    }

    // Deletion: Removes from front
    T dequeue() override { // Need to fix logic of dequeue function
        if (curr_size_ == 0) throw std::runtime_error("Stack is empty");
        T returnVal = array_[front_];
        front_ = (front_ + 1) % capacity_;
        curr_size_--;
        // If size is 1/4 capacity, halving capacity and moving to smaller array
        if (curr_size_ * 4 <= capacity_ && capacity_ > 1) {
            capacity_ /= 2;
            T* temp = new T[capacity_];
            for (size_t i = 0; i < curr_size_; ++i) {
                temp[i] = array_[(front_ + i) % capacity_];
            }
            delete[] array_;
            array_ = temp;
            front_ = 0;
            back_ = curr_size_;
        }
        // array_[front_] = 0;
        return returnVal;
    }
};
