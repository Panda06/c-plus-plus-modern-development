#include "test_runner.h"
#include "profile.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
  T* NotEmpty() {
      auto ptr = deallocate.front();
      deallocate.pop_front();
      objects[ptr] = false;
      allocate.push_back(ptr);
      return ptr;
  }
  T* Allocate() {
      if (deallocate.empty()) {
          T* ptr = new T;
          allocate.push_back(ptr);
          objects[ptr] = false;
          return ptr;
      }
      return NotEmpty();
  }
  T* TryAllocate() {
      if (deallocate.empty()) {
          return nullptr;
      }
      return NotEmpty();
  }
  void ClearAllocate() {
      while (objects[allocate.front()]) {
          objects[allocate.front()] = false;
          allocate.pop_front();
      }
  }
  void Deallocate(T* object) {
      ClearAllocate();
      if (allocate.empty() || objects.count(object) == 0 || objects[object]) {
          throw std::invalid_argument("");
      }
      if (allocate.front() != object) {
          deallocate.push_back(object);
      }
      if (allocate.front() == object) {
          if (!objects[object]) {
              deallocate.push_back(object);
          }
          allocate.pop_front();
      }
      objects[object] = true;
  }

  ~ObjectPool() {
      for (auto& item: objects) {
          delete item.first;
      }
  }

private:
    std::deque<T*> allocate;
    std::deque<T*> deallocate;
    std::map<T*, bool> objects;
};

void TestObjectPool() {
  ObjectPool<string> pool;

  auto p1 = pool.Allocate();
  auto p2 = pool.Allocate();
  auto p3 = pool.Allocate();

  *p1 = "first";
  *p2 = "second";
  *p3 = "third";

  pool.Deallocate(p2);
  ASSERT_EQUAL(*pool.Allocate(), "second");

  pool.Deallocate(p3);
  pool.Deallocate(p1);
  ASSERT_EQUAL(*pool.Allocate(), "third");
  ASSERT_EQUAL(*pool.Allocate(), "first");

  pool.Deallocate(p1);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestObjectPool);
  return 0;
}
