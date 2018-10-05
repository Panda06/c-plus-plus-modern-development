#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    auto dist = distance(range_begin, range_end);
    if (dist < 2 ) {
        return;
    }
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    auto it = begin(elements) + dist / 2;
    MergeSort(begin(elements), it);
    MergeSort(it, end(elements));
    
    merge(begin(elements), it, it, end(elements), range_begin);

}

int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
