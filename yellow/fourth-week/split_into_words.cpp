#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> SplitIntoWords(const string& s) {
    vector<string> words;
    auto it = begin(s);
    do {
        auto it_space = find(it, end(s), ' ');
        words.push_back({it, it_space});
        ++it_space;
        it = it_space;
    }while (it < end(s));
    return words;
}
int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;

  return 0;
}
