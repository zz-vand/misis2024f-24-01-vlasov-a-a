#include <iostream>
#include <cstdint> 
#include <stdexcept> 

template <typename T>
class Queue {
private:
    struct N {
        T data;
        N* next;

        N(const T& value) : data(value), next(nullptr) {}
    };

    N* front;
    N* rear;
    size_t size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    Queue(const Queue& src) : front(nullptr), rear(nullptr), size(0) {
        N* current = src.front;
        while (current) {
            Push(current->data);
            current = current->next;
        }
    }

    Queue(Queue&& src) noexcept : front(src.front), rear(src.rear), size(src.size) {
        src.front = nullptr;
        src.rear = nullptr;
        src.size = 0;
    }

    ~Queue() {
        Clear();
    }

    Queue& operator=(const Queue& src) {
        if (this != &src) {
            Clear();
            N* current = src.front;
            while (current) {
                Push(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    Queue& operator=(Queue&& src) noexcept {
        if (this != &src) {
            Clear();

            front = src.front;
            rear = src.rear;
            size = src.size;

            src.front = nullptr;
            src.rear = nullptr;
            src.size = 0;
        }
        return *this;
    }

    void Push(const T val) {
        N* newN = new N(val);
        if (isEmpty()) {
            front = rear = newN;
        }
        else {
            rear->next = newN;
            rear = newN;
        }
        size++;
    }

    void Pop() noexcept {
        if (isEmpty()) {
            throw std::out_of_range("empty");
        }
        N* temp = front;
        front = front->next;
        delete temp;
        size--;
        if (isEmpty()) {
            rear = nullptr;
        }
    }

    T& Top() {
        if (isEmpty()) {
            throw std::out_of_range("empty");
        }
        return front->data;
    }

    const T& Top() const {
        if (isEmpty()) {
            throw std::out_of_range("empty");
        }
        return front->data;
    }

    void Clear() noexcept {
        while (!isEmpty()) {
            Pop();
        }
    }

    bool isEmpty() const {
        return size == 0;
    }

    size_t Size() const {
        return size;
    }
};

int main() {
    Queue<std::uint8_t> queue;

    queue.Push(1);
    queue.Push(2);
    queue.Push(3);
    queue.Push(4);

    std::cout << "front: " << queue.Top() << std::endl;
    std::cout << "size: " << queue.Size() << std::endl;

    while (!queue.isEmpty()) {
        std::cout << static_cast<int>(queue.Top()) << std::endl;
        queue.Pop();
    }

    return 0;
}
