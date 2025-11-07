// Array-Based Stack: ABS.hpp. Last-in, First-out.
#pragma once

#include <cstddef>
#include <stdexcept>
#include "Interfaces.hpp"
#include "LinkedList.hpp"

// Technically bad, but size_t isn't likely to conflict with any client code.
using std::size_t;

template<typename T>
class ABS : public StackInterface<T> {
private:
    size_t capacity_; // Total allocated slots
    size_t curr_size_; // Current stack depth
    // T* array_; // Pointer to dynamic array storing elements
    LinkedList<T>* array_;
    static constexpr size_t scale_factor_ = 2;

public:
    // Big 5 + Parameterized Constructor
    // Default Constructor. Default capacity_ to 1, size_ to 0, and create buffer array data_.
    ABS() : capacity_(1), curr_size_(0), array_(new LinkedList<T>) {}
    // Parameterized Constructor. Same behavior as default, however set capacity_ to capacity
    explicit ABS(const size_t capacity) : capacity_(capacity), curr_size_(0), array_(new LinkedList<T>) {}
    // Copy constructor
    ABS(const ABS& other) : capacity_(other.capacity_), curr_size_(other.curr_size_), array_(other.array_) {}
    // Copy assignment
    ABS& operator=(const ABS& rhs) {
        capacity_ = rhs.capacity_;
        curr_size_ = rhs.curr_size_;
        LinkedList<T>* temp = rhs.array_;
        array_ = temp;
        temp = nullptr;
        return *this;
    }
    // Move constructor
    ABS(ABS&& other) noexcept {
        capacity_ = other.capacity_;
        other.capacity_ = 0;
        curr_size_ = other.curr_size_;
        other.curr_size_ = 0;
        array_ = std::move(other.array_);
    }
    // Move assignment
    ABS& operator=(ABS&& rhs) noexcept {
        capacity_ = rhs.capacity_;
        rhs.capacity_ = 0;
        curr_size_ = rhs.curr_size_;
        rhs.curr_size_ = 0;
        delete array_; // Need to clear first?
        array_ = std::move(rhs.array_);
        return *this;
    }
    // Destructor
    ~ABS() noexcept override {
        capacity_ = 0;
        curr_size_ = 0;
        array_->clear();
        delete array_; // Double delete error?
        array_ = nullptr;
    }

    // Get the number of items in the ABS; Returns element count
    [[nodiscard]] size_t getSize() const noexcept override { return curr_size_; }

    // Get the max size of the ABS
    [[nodiscard]] size_t getMaxCapacity() const noexcept { return capacity_; }

    // Return underlying data for the stack
    [[nodiscard]] T* getData() const noexcept { return array_; } // Need to return T* instead?

    // Push item onto the stack: Push at top; doubles capacity if full
    void push(const T& data) override {
        curr_size_++;
        if (curr_size_ > capacity_) capacity_ *= scale_factor_;
        array_->addHead(data);
    }

    // Returns top element
    T peek() const override {
        return array_->head->next.data;
    }

    // Removes the last inserted element
    T pop() override {
        if (curr_size_ == 0) return 0;
        curr_size_--;
        if (curr_size_ <= (capacity_/4)) curr_size_ /= 2; // is this necessary?
        return array_->getHead().data;
    }
};
