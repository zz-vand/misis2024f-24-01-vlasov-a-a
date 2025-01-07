#pragma once
#ifndef ARRAYT_ARRAYT_HPP
#define ARRAYT_ARRAYT_HPP

#include <stdexcept>
#include <algorithm>
#include <cstddef>

template <typename T>
class ArrayT {
public:
    ArrayT(const std::ptrdiff_t size = 0);
    ~ArrayT();

    ArrayT(const ArrayT&);
    ArrayT& operator=(const ArrayT&);

    [[nodiscard]] T& operator[](std::ptrdiff_t i);
    [[nodiscard]] const T& operator[](std::ptrdiff_t i) const;

    [[nodiscard]] std::ptrdiff_t ssize() const noexcept;
    [[nodiscard]] std::ptrdiff_t capacity() const noexcept;

    void resize(const std::ptrdiff_t new_size);

    void insert(const std::ptrdiff_t i, const T value);

    void remove(const std::ptrdiff_t i);

private:
    std::ptrdiff_t ssize_ = 0;
    std::ptrdiff_t capacity_ = 0;
    T* data_ = nullptr;
};

template <typename T>
ArrayT<T>::ArrayT(const std::ptrdiff_t size) {
    if (size < 0) {
        throw std::invalid_argument("size cant be negative");
    }
    if (size > 0) {
        ssize_ = size;
        capacity_ = size;
        data_ = new T[capacity_]{};
    }
}

template <typename T>
ArrayT<T>::~ArrayT() {
    delete[] data_;
}

template <typename T>
ArrayT<T>::ArrayT(const ArrayT& arr) {
    if (this != &arr) {
        resize(arr.ssize());
        std::copy(arr.data_, arr.data_ + arr.ssize(), data_);
    }
}

template <typename T>
ArrayT<T>& ArrayT<T>::operator=(const ArrayT& arr) {
    if (this != &arr) {
        resize(arr.ssize());
        std::copy(arr.data_, arr.data_ + arr.ssize(), data_);
    }
    return *this;
}

template <typename T>
T& ArrayT<T>::operator[](std::ptrdiff_t i) {
    if (i < 0 || i >= ssize_ || data_ == nullptr) {
        throw std::out_of_range("wrong");
    }
    return data_[i];
}

template <typename T>
const T& ArrayT<T>::operator[](std::ptrdiff_t i) const {
    if (i < 0 || i >= ssize_) {
        throw std::out_of_range("bad index");
    }
    return data_[i];
}

template <typename T>
std::ptrdiff_t ArrayT<T>::ssize() const noexcept {
    return ssize_;
}

template <typename T>
std::ptrdiff_t ArrayT<T>::capacity() const noexcept {
    return capacity_;
}

template <typename T>
void ArrayT<T>::resize(const std::ptrdiff_t new_size) {
    if (new_size <= 0) {
        throw std::invalid_argument("new size cant be negative");
    }
    if (new_size == ssize_) {
        return;
    }
    if (new_size > capacity_) {
        capacity_ = new_size * 2;
        auto* new_data = new T[capacity_]{};
        std::copy(data_, data_ + ssize_, new_data);
        delete[] data_;
        data_ = new_data;
    }
    else if (ssize_ < new_size) {
        std::fill(data_ + ssize_, data_ + new_size, T());
    }
    ssize_ = new_size;
}

template <typename T>
void ArrayT<T>::insert(const std::ptrdiff_t i, const T value) {
    if (i < 0 || i > ssize_) {
        throw std::out_of_range("wrong index");
    }
    resize(ssize_ + 1);
    std::copy_backward(data_ + i, data_ + ssize_ - 1, data_ + ssize_);
    data_[i] = value;
}

template <typename T>
void ArrayT<T>::remove(const std::ptrdiff_t i) {
    if (i < 0 || i >= ssize_) {
        throw std::out_of_range("wrong index");
    }
    std::copy(data_ + i + 1, data_ + ssize_, data_ + i);
    resize(ssize_ - 1);
}

#endif
