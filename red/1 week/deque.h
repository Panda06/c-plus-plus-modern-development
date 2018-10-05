#include <stdexcept>
#include <vector>


template <class T>
class Deque {
private:
    std::vector<T> front;
    std::vector<T> back;
    void CheckIndex(size_t index) const {
    if (index >= Size())
      throw std::out_of_range("Index is out of range");
  }
public:
    Deque() {
        front = std::vector<T>();
        back = std::vector<T>();
    }
    bool Empty() const { return front.empty() && back.empty(); }
    size_t Size() const { return front.size() + back.size(); }
    T& operator[](size_t index) {
        if (index < front.size()) {
            return front[front.size()-index-1];
        }
        return back[index-front.size()];
    }
    const T& operator[](size_t index) const {
        if (index < front.size()) {
            return front[front.size()-index-1];
        }
        return back[index-front.size()];
    }
    T& At(size_t index) {
        CheckIndex(index);
        return (*this)[index];
    }
    const T& At(size_t index) const {
        CheckIndex(index);
        return (*this)[index];
    }
    void PushBack(T el) {
        back.push_back(el);
    }
    void PushFront(T el) {
        front.push_back(el);
    }
    T& Back() {
        if (back.empty() && !front.empty()) {
            return front.front();
        }
        return back.back();
    }
    const T& Back() const {
        if (back.empty() && !front.empty()) {
            return front.front();
        }
        return back.back();
    }
    T& Front() {
        if (front.empty() && !back.empty()) {
            return back.front();
        }
        return front.back();
    }
    const T& Front() const {
        if (front.empty() && !back.empty()) {
            return back.front();
        }
        return front.back();
    }
};
