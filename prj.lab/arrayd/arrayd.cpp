#include <arrayd.hpp>

#include <stdexcept>
#include <algorithm>
#include <cstddef>

ArrayD::ArrayD(const std::ptrdiff_t size) {
    if (size < 0) {
        throw std::invalid_argument("size can't be negative");
    }
    if (size > 0) {
        ssize_ = size;
        capacity_ = size;
        data_ = new double[capacity_]{};
    }
}

ArrayD::~ArrayD() {
    delete[] data_;
}

ArrayD::ArrayD(const ArrayD& arr) {
    if (this != &arr) {
        resize(arr.ssize());
        std::copy(arr.data_, arr.data_ + arr.ssize(), data_);
    }
}

ArrayD& ArrayD::operator=(const ArrayD& arr) {
    if (this != &arr) {
        resize(arr.ssize());
        std::copy(arr.data_, arr.data_ + arr.ssize(), data_);
    }
    return *this;
}

double& ArrayD::operator[](std::ptrdiff_t i) {
    if (i < 0 || i >= ssize_ || data_ == nullptr) {
        throw std::out_of_range("array index out of range");
    }
    return data_[i];
}

const double& ArrayD::operator[](std::ptrdiff_t i) const {
    if (i < 0 || i >= ssize_) {
        throw std::out_of_range("array index out of range");
    }
    return data_[i];
}

std::ptrdiff_t ArrayD::ssize() const noexcept {
    return ssize_;
}

std::ptrdiff_t ArrayD::capacity() const noexcept {
    return capacity_;
}

void ArrayD::resize(const std::ptrdiff_t new_size) {
    if (new_size <= 0) {
        throw std::invalid_argument("size should be positive");
    }
    if (new_size == ssize_) {
        return;
    }
    if (new_size > capacity_) {
        capacity_ = new_size * 2;
        auto* new_data = new double[capacity_] {};
        std::copy(data_, data_ + ssize_, new_data);
        delete[] data_;
        data_ = new_data;
    }
    else if (ssize_ < new_size) {
        std::fill(data_ + ssize_, data_ + new_size, double(0));
    }
    ssize_ = new_size;
}

void ArrayD::insert(const std::ptrdiff_t i, const double value) {
    if (i < 0 || i > ssize_) {
        throw std::out_of_range("index should be in range [0, size]");
    }
    resize(ssize_ + 1);
    std::copy_backward(data_ + i, data_ + ssize_ - 1, data_ + ssize_);
    data_[i] = value;
}

void ArrayD::remove(const std::ptrdiff_t i) {
    if (i < 0 || i >= ssize_) {
        throw std::out_of_range("array index out of range");
    }
    std::copy(data_ + i + 1, data_ + ssize_, data_ + i);
    resize(ssize_ - 1);
}
