#include "stackl/stackl.hpp"

#include <cstddef>
#include <cstdint>
#include <stdexcept>

StackL::StackL() : head_(nullptr) {}

StackL::StackL(const StackL& src) : head_(nullptr) {
    if (!src.IsEmpty()) {
        Node* current = src.head_;
        while (current != nullptr) {
            Push(current->val);
            current = current->next;
        }
    }
}

StackL::StackL(StackL&& src) noexcept : head_(src.head_) {
    src.head_ = nullptr; }

StackL::~StackL() noexcept {
    Clear();
}

StackL& StackL::operator=(const StackL& src) {
    if (this != &src) {
        Clear(); 
        if (!src.IsEmpty()) {
            StackL temp; 
            Node* current = src.head_;
            while (current != nullptr) {
                temp.Push(current->val);
                current = current->next;
            }
            while (!temp.IsEmpty()) {
                Push(temp.Top());
                temp.Pop();
            }
        }
    }
    return *this;
}

StackL& StackL::operator=(StackL&& src) noexcept {
    if (this != &src) {
        Clear();         
        head_ = src.head_;
        src.head_ = nullptr;     
    }
    return *this;
}

bool StackL::IsEmpty() const noexcept {
    return head_ == nullptr;
}

void StackL::Pop() noexcept {
    if (!IsEmpty()) {
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
    }
}

void StackL::Push(const T val) {
    Node* newNode = new Node{ val, head_ };
    head_ = newNode;
}

StackL::T& StackL::Top()& {
    if (IsEmpty()) {
        throw std::logic_error("empty");
    }
    return head_->val;
}

const StackL::T& StackL::Top() const& {
    if (IsEmpty()) {
        throw std::logic_error("empty");
    }
    return head_->val;
}

void StackL::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}
