#include "test_runner.h"
#include <algorithm>
#include <memory>
#include <iterator>
#include <vector>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    auto dist = distance(range_begin, range_end);
      if (dist < 2 ) {
          return;
      }
      vector<typename RandomIt::value_type> elements(make_move_iterator(range_begin),
                                                     make_move_iterator(range_end));
      auto it = begin(elements) + dist / 3;
      auto it2 = begin(elements) + dist * 2 / 3;

      MergeSort(begin(elements), it);
      MergeSort(it, it2);
      MergeSort(it2, end(elements));

      vector<typename RandomIt::value_type> tmp;

      merge(make_move_iterator(begin(elements)), make_move_iterator(it),
            make_move_iterator(it), make_move_iterator(it2),
            back_inserter(tmp));
      merge(make_move_iterator(begin(tmp)), make_move_iterator(end(tmp)),
            make_move_iterator(it2), make_move_iterator(end(elements)),
            range_begin);
}

void TestIntVector() {
  vector<int> numbers = {6, 1, 3, 9, 1, 9, 8, 12, 1};
  MergeSort(begin(numbers), end(numbers));
  ASSERT(is_sorted(begin(numbers), end(numbers)));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestIntVector);
  return 0;
}
