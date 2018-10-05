#include <algorithm>
using namespace std;

template <class T>
void RemoveDuplicates(vector<T>& elements) {
  sort(begin(elements), end(elements));
  elements.erase(unique(begin(elements), end(elements)),
                 end(elements));
}
