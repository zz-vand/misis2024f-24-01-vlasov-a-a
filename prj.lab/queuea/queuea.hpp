
#pragma once
#ifndef QUEUEA_QUEUEA_HPP
#define QUEUEA_QUEUEA_HPP

#include <cstddef>
#include <cstdint>

class QueueA final { 
public:
  using T = std::uint8_t;

  QueueA() = default;

  QueueA(const QueueA& src);

  QueueA(QueueA&& src) noexcept;
  
  ~QueueA();
  
  QueueA& operator=(const QueueA& src);

  QueueA& operator=(QueueA&& src) noexcept;

  [[nodiscard]] bool IsEmpty() const noexcept;

  [[nodiscard]] std::ptrdiff_t Count() const;

  void Pop() noexcept;

  void Push(const T val);
  
  [[nodiscard]] T& Top(); 

  [[nodiscard]] const T& Top() const; 

  void Clear() noexcept;

private:
  std::ptrdiff_t size_ = 0;  
  T* data_ = nullptr;  
  std::ptrdiff_t head_ = -1;  
  std::ptrdiff_t tail_ = -1; 
  std::ptrdiff_t capacity_ = 0; 
private:
  void Swap(QueueA&& src) noexcept;
  void Resize(const std::ptrdiff_t i);
};

#endif
