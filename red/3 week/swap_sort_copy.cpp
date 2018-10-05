#include "test_runner.h"

#include <algorithm>
#include <numeric>
using namespace std;

template <typename T>
void Swap(T* first, T* second) {
    T* tmp = new T;
    *tmp = *first;
    *first = *second;
    *second = *tmp;
}

template <typename T>
void SortPointers(vector<T*>& pointers) {
    for (int i = 0; i < pointers.size(); ++i) {
        for (int j = i + 1; j < pointers.size(); ++j) {
            if (*pointers[i] > *pointers[j]) {
                Swap(pointers[i], pointers[j]);
            }
        }
    }
}

template <typename T>
void ReversedCopy(T* source, size_t count, T* destination) {
    if (source <= destination && destination < source + count) {
        int i = 0;
        int j = count - 1;
        while (source + i != destination) {
            destination[j] = source[i];
            --j;
            ++i;
        }
        while (i < j) {
            Swap(source + i, destination + j);
            --j;
            ++i;
        }
    } else {
        auto end = source + count;
        while (source != end) {
            *(destination++) = *(--end);
        }
    }
}

void TestSwap() {
  int a = 1;
  int b = 2;
  Swap(&a, &b);
  ASSERT_EQUAL(a, 2);
  ASSERT_EQUAL(b, 1);

  string h = "world";
  string w = "hello";
  Swap(&h, &w);
  ASSERT_EQUAL(h, "hello");
  ASSERT_EQUAL(w, "world");
}

void TestSortPointers() {
  int one = 1;
  int two = 2;
  int three = 3;

  vector<int*> pointers;
  pointers.push_back(&two);
  pointers.push_back(&three);
  pointers.push_back(&one);

  SortPointers(pointers);

  ASSERT_EQUAL(pointers.size(), 3u);
  ASSERT_EQUAL(*pointers[0], 1);
  ASSERT_EQUAL(*pointers[1], 2);
  ASSERT_EQUAL(*pointers[2], 3);
}

void TestReverseCopy() {
  const size_t count = 7;

  int* source = new int[count];
  int* dest = new int[count];

  for (size_t i = 0; i < count; ++i) {
    source[i] = i + 1;
  }
  ReversedCopy(source, count, dest);
  const vector<int> expected1 = {7, 6, 5, 4, 3, 2, 1};
  ASSERT_EQUAL(vector<int>(dest, dest + count), expected1);

  for (size_t i = 0; i < count; ++i) {
    source[i] = i + 1;
  }

  ReversedCopy(source, 1, source + count - 1);
  const vector<int> expected2 = {1, 2, 3, 4, 5, 6, 1};
  ASSERT_EQUAL(vector<int>(source, source + count), expected2);

  for (size_t i = 0; i < count; ++i) {
    source[i] = i + 1;
  }
  // Области памяти могут перекрываться
  ReversedCopy(source, count - 1, source + 1);
  const vector<int> expected3 = {1, 6, 5, 4, 3, 2, 1};
  ASSERT_EQUAL(vector<int>(source, source + count), expected3);

  ReversedCopy(source, count - 2, source + 2);
  const vector<int> expected4 = {1, 6, 5, 4, 3, 6, 1};
  ASSERT_EQUAL(vector<int>(source, source + count), expected4);

  delete[] dest;
  delete[] source;
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSwap);
  RUN_TEST(tr, TestSortPointers);
  RUN_TEST(tr, TestReverseCopy);
  return 0;
}
