#pragma once

#include <cstdlib>
#include <algorithm>
// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
  SimpleVector() = default;
  explicit SimpleVector(size_t size) : data(new T[size]), capacity(2*size),
      _size(size) {}
  ~SimpleVector() {
      delete[] data;
  }

  T& operator[](size_t index) {
      return data[index];
  }

  T* begin() { return data; }
  T* end() { return data + _size; }

  const T* begin() const { return data; }
  const T* end() const { return data + _size; }

  size_t Size() const {
      return _size;
  }
  size_t Capacity() const {
      return capacity;
  }
  void PushBack(const T& value) {
      if (_size == capacity) {
          capacity = capacity ? capacity * 2 : 1;
          T* _data = new T[capacity];
          std::copy(begin(), end(), _data);
          delete[] data;
          data = _data;
      }
      data[_size++] = value;
  }

private:
    T* data = nullptr;
    size_t capacity = 0;
    size_t _size = 0;
};
