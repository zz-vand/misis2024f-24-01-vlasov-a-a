#pragma once
#ifndef STACKL_STACKL_HPP
#define STACKL_STACKL_HPP

#include <cstddef>
#include <cstdint>

class StackL final {
public:
    using T = std::uint8_t;
public:
    StackL();

    StackL(const StackL& src);

    StackL(StackL&& src) noexcept;

    ~StackL();

    StackL& operator=(const StackL& src);

    StackL& operator=(StackL&& src) noexcept;

    [[nodiscard]] bool IsEmpty() const noexcept;

    void Pop() noexcept;

    void Push(const T val);

    [[nodiscard]] T& Top()&;

    [[nodiscard]] const T& Top() const&;

    void Clear() noexcept;

private:
    struct Node {
        T val = T();
        Node* next = nullptr;
    };

    Node* head_ = nullptr;

};

#endif //STACKL_STACKL_HPP
