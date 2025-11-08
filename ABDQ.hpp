// ABDQ.hpp: Array-Based Deque
#pragma once

#include <cstddef>
#include <stdexcept>
#include "Interfaces.hpp"
#include <utility>

template <typename T>
class ABDQ : public DequeInterface<T> {
private:
    T* data_;                 // underlying dynamic array (circular array buffer)
    std::size_t capacity_;    // total allocated capacity
    std::size_t size_;        // number of stored elements
    std::size_t front_;       // index of front element
    std::size_t back_;        // index after the last element (circular)
    static constexpr std::size_t SCALE_FACTOR = 2;

public:
    // Big 5
    // Default Constructor.
    ABDQ() : data_(new T[4]), capacity_(4), size_(0), front_(0), back_(0) {}
    // Parameterized constructor. Same behavior as default, however set capacity_
    // to capacity.
    explicit ABDQ(std::size_t capacity) {
        capacity_ = capacity;
        data_ = new T[capacity_];
        size_ = 0;
        front_ = 0;
        back_ = 0;
    }
    // Copy constructor
    ABDQ(const ABDQ& other) {
        capacity_ = other.capacity_;
        size_ = other.size_;
        front_ = other.front_;
        back_ = other.back_;
        data_ = new T[other.capacity_];
        for (size_t i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
    }
    // Move constructor
    ABDQ(ABDQ&& other) noexcept {
        capacity_ = other.capacity_;
        other.capacity_ = 0;
        size_ = other.size_;
        other.size_ = 0;
        front_ = other.front_;
        other.front_ = 0;
        back_ = other.back_;
        other.back_ = 0;
        data_ = other.data_;
        other.data_ = nullptr;
    }
    // Copy assignment
    ABDQ& operator=(const ABDQ& other) {
        if (this == &other) return *this;
        capacity_ = other.capacity_;
        size_ = other.size_;
        front_ = other.front_;
        back_ = other.back_;
        delete[] data_;
        data_ = new T[capacity_];
        for (size_t i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
        return *this;
    }
    // Move assignment
    ABDQ& operator=(ABDQ&& other) noexcept {
        if (this == &other) return *this;
        capacity_ = other.capacity_;
        other.capacity_ = 0;
        size_ = other.size_;
        other.size_ = 0;
        data_ = other.data_;
        other.data_ = nullptr;
        front_ = other.front_;
        other.front_ = 0;
        back_ = other.back_;
        other.back_ = 0;
        return *this;
    }
    // Destructor
    ~ABDQ() override {
        capacity_ = 0;
        size_ = 0;
        front_ = 0;
        back_ = 0;
        delete[] data_;
        data_ = nullptr;
    }

    // Insertion: Insert element from either end
    void pushFront(const T& item) override {
        // If size exceeds capacity, doubling the size of the array
        if (size_ >= capacity_) {
            std::size_t oldCap = capacity_;
            capacity_ *= SCALE_FACTOR;
            T* temp = new T[capacity_];
            for (size_t i = 0; i < size_; ++i) {
                temp[i] = data_[(front_ + i) % oldCap];
            }
            delete[] data_;
            data_ = temp;
            front_ = 0;
            back_ = size_;
        }
        front_ = (front_ + capacity_ - 1) % capacity_;
        data_[front_] = item;
        size_++;
    }
    void pushBack(const T& item) override {
        // If size exceeds capacity, doubling the size of the array
        if (size_ >= capacity_) {
            std::size_t oldCap = capacity_;
            capacity_ *= SCALE_FACTOR;
            T* temp = new T[capacity_];
            for (size_t i = 0; i < size_; ++i) {
                temp[i] = data_[(front_ + i) % oldCap];
            }
            delete[] data_;
            data_ = temp;
            front_ = 0;
            back_ = size_;
        }
        data_[back_] = item;
        back_ = (back_ + 1) % capacity_;
        size_++;
    }

    // Deletion: Remove element from either end
    T popFront() override {
        if (size_ == 0) throw std::runtime_error("Deque is empty");
        T returnVal = data_[front_];
        // data_[front_] = 0;
        front_ = (front_ + 1) % capacity_;
        size_--;
        return returnVal;
    }
    T popBack() override {
        if (size_ == 0) throw std::runtime_error("Deque is empty");
        back_ = (back_ + capacity_ - 1) % capacity_;
        T returnVal = data_[back_];
        // data_[back_] = 0;
        size_--;
        return returnVal;
    }

    // Access: Access extremities
    const T& front() const override {
        if (size_ == 0) throw std::runtime_error("Deque is empty");
        return data_[front_];
    }
    const T& back() const override {
        if (size_ == 0) throw std::runtime_error("Deque is empty");
        return data_[(back_ + capacity_ -1) % capacity_];
    }

    // Resizes to capacity_ * 2
    void ensureCapacity() {
        capacity_ *= SCALE_FACTOR;
        T* temp = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            temp[i] = data_[(front_ + i) % capacity_];
        }
        delete[] data_;
        data_ = temp;
        delete[] temp;
        front_ = 0;
        back_ = size_;
    }

    // Reduces to half when sparse
    void shrinkIfNeeded() {
        if (size_ * 4 <= capacity_) {
            capacity_ /= 2;
            T* temp = new T[capacity_];
            for (size_t i = 0; i < size_; ++i) {
                temp[i] = data_[(front_ + i) % capacity_];
            }
            delete[] data_;
            data_ = temp;
            delete[] temp;
            front_ = 0;
            back_ = size_;
        }
    }

    // Getters
    [[nodiscard]] std::size_t getSize() const noexcept override {
        return size_;
    }
    [[nodiscard]] std::size_t getCapacity() const noexcept {
        return capacity_;
    }
};
