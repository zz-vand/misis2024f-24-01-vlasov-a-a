#include "queuea/queuea.hpp"
#include <stdexcept>
#include <algorithm>
#include <cstring>

QueueA::QueueA(const QueueA& src)
    : size_(src.size_), head_(src.head_), tail_(src.tail_), capacity_(src.capacity_) {
    if (capacity_ > 0) {
        data_ = new T[capacity_];
        std::copy(src.data_, src.data_ + capacity_, data_);
    }
    else {
        data_ = nullptr;
    }
}

QueueA::QueueA(QueueA&& src) noexcept
    : size_(src.size_), head_(src.head_), tail_(src.tail_), capacity_(src.capacity_), data_(src.data_) {
    src.data_ = nullptr;      
    src.size_ = 0;
    src.head_ = -1;
    src.tail_ = -1;
    src.capacity_ = 0;
}

QueueA::~QueueA() {
    Clear();
}

QueueA& QueueA::operator=(const QueueA& src) {
    if (this != &src) {
        delete[] data_;  
        size_ = src.size_;
        head_ = src.head_;
        tail_ = src.tail_;
        capacity_ = src.capacity_;

        if (capacity_ > 0) {
            data_ = new T[capacity_];
            std::copy(src.data_, src.data_ + capacity_, data_);
        }
        else {
            data_ = nullptr;
        }
    }
    return *this;
}

QueueA& QueueA::operator=(QueueA&& src) noexcept {
    if (this != &src) {
        delete[] data_;  
        data_ = src.data_;
        size_ = src.size_;
        head_ = src.head_;
        tail_ = src.tail_;
        capacity_ = src.capacity_;

        src.data_ = nullptr;          
        src.size_ = 0;
        src.head_ = -1;
        src.tail_ = -1;
        src.capacity_ = 0;
    }
    return *this;
}

bool QueueA::IsEmpty() const noexcept {
    return size_ == 0;
}

std::ptrdiff_t QueueA::Count() const {
    return size_;
}

void QueueA::Pop() noexcept {
    if (IsEmpty()) return;

    head_ = (head_ + 1) % capacity_;
    --size_;

    if (IsEmpty()) {          
        head_ = -1;
        tail_ = -1;
    }
}

void QueueA::Push(const T val) {
    if (size_ == capacity_) {          
        Resize(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    if (IsEmpty()) {          
        head_ = 0;
        tail_ = 0;
    }
    else {
        tail_ = (tail_ + 1) % capacity_;      
    }
    data_[tail_] = val;      
    ++size_;  
}

QueueA::T& QueueA::Top() {
    if (IsEmpty()) {
        throw std::logic_error("empty queue.");
    }
    return data_[head_];
}

const QueueA::T& QueueA::Top() const {
    if (IsEmpty()) {
        throw std::logic_error("empty queue.");
    }
    return data_[head_];
}
void QueueA::Clear() noexcept {
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
    head_ = -1;
    tail_ = -1;
    capacity_ = 0;
}

void QueueA::Resize(const std::ptrdiff_t new_capacity) {
    T* new_data = new T[new_capacity];

    if (!IsEmpty()) {
        if (head_ <= tail_) {              
            std::copy(data_ + head_, data_ + tail_ + 1, new_data);
        }
        else {              
            std::copy(data_ + head_, data_ + capacity_, new_data);
            std::copy(data_, data_ + tail_ + 1, new_data + capacity_ - head_);
        }
    }

    delete[] data_;      
    data_ = new_data;      
    capacity_ = new_capacity;  
}
