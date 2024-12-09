#pragma once
#ifndef ARRAYD_ARRAYD_HPP
#define ARRAYD_ARRAYD_HPP

#include <cstddef>

class ArrayD {
public:
    explicit ArrayD(const std::ptrdiff_t size = 0);
    ~ArrayD();

    ArrayD(const ArrayD&);
    ArrayD& operator=(const ArrayD&);

    [[nodiscard]] double& operator[](std::ptrdiff_t i);
    [[nodiscard]] const double& operator[](std::ptrdiff_t i) const;

    [[nodiscard]] std::ptrdiff_t ssize() const noexcept;
    [[nodiscard]] std::ptrdiff_t capacity() const noexcept;

    void resize(const std::ptrdiff_t new_size);

    void insert(const std::ptrdiff_t i, const double value);

    void remove(const std::ptrdiff_t i);

private:
    std::ptrdiff_t ssize_ = 0;
    std::ptrdiff_t capacity_ = 0;
    double* data_ = nullptr;
};

#endif
