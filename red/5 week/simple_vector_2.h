#include <algorithm>
#include <cstdint>

using namespace std;

// Реализуйте SimpleVector в этом файле
// и отправьте его на проверку

template <typename T>
class SimpleVector {
public:
  SimpleVector() = default;
  explicit SimpleVector(size_t _size) : data(new T[_size]), capacity(_size),
      size(_size) {}
  ~SimpleVector() {
      delete[] data;
  }

  T& operator[](size_t index) {
      return data[index];
  }

  T* begin() { return data; }
  T* end() { return data + size; }

  const T* begin() const { return data; }
  const T* end() const { return data + size; }

  size_t Size() const {
      return size;
  }
  size_t Capacity() const {
      return capacity;
  }

  void PushBack(T value) {
      ReserveNewCapacity();
      data[size++] = move(value);
  }

  // При необходимости перегрузите
  // существующие публичные методы

private:
    T* data = nullptr;
    size_t capacity = 0;
    size_t size = 0;

    void ReserveNewCapacity() {
        if (size == capacity) {
            capacity = capacity ? capacity * 2 : 1;
            T* _data = new T[capacity];
            move(begin(), end(), _data);
            delete[] data;
            data = _data;
        }
    }
};
