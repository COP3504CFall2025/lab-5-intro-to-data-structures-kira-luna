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
    static constexpr size_t scale_factor_ = 2;

public:
    // Constructors + Big 5
    // Default constructor. Default capacity_ to 1, size_ to 0, and create buffer array data_.
    ABQ();
    // Parameterized Constructor. Same behavior as default, however set capacity_ to capacity
    explicit ABQ(const size_t capacity);

    ABQ(const ABQ& other);
    ABQ& operator=(const ABQ& rhs);
    ABQ(ABQ&& other) noexcept;
    ABQ& operator=(ABQ&& rhs) noexcept;
    ~ABQ() noexcept override;

    // Getters
    // Returns size
    [[nodiscard]] size_t getSize() const noexcept override;
    // Returns capacity
    [[nodiscard]] size_t getMaxCapacity() const noexcept;
    // Returns pointer to data
    [[nodiscard]] T* getData() const noexcept;

    // Insertion: Adds element to back
    void enqueue(const T& data) override;

    // Access: Returns front element
    T peek() const override;

    // Deletion: Removes from front
    T dequeue() override;

};
