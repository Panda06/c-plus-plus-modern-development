#pragma once
#include <array>
#include <stdexcept>
using namespace std;

template <typename T, size_t N>
class StackVector {
public:
  explicit StackVector(size_t a_size = 0) : size(a_size) {
      if (size > N) {
          throw invalid_argument("");
      }
  }

  T& operator[](size_t index) {
      return stack[index];
  }
  const T& operator[](size_t index) const {
      return stack[index];
  }

  auto begin() {
      return stack.begin();
  }
  auto end() {
      return stack.begin() + size;
  }
  auto begin() const {
      return stack.begin();
  }
  auto end() const {
      return stack.begin() + size;
  }

  size_t Size() const {
      return size;
  }
  size_t Capacity() const {
      return N;
  }

  void PushBack(const T& value) {
      if (size == N) {
          throw overflow_error("");
      }
      stack[size] = value;
      ++size;
  }
  T PopBack() {
      if (size == 0) {
          throw underflow_error("");
      }
      --size;
      return stack[size];
  }

private:
    array<T, N> stack;
    size_t size = 0;
};
