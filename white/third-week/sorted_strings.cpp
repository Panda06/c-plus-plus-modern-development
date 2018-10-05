#include <iostream>
#include <string>
#include <vector>

class SortedStrings {
public:
  void AddString(const string& s) {
      str.push_back(s);
  }
  std::vector<std::string> GetSortedStrings() {
      sort(str.begin(), str.end());
      return str;
  }
private:
  std::vector<std::string> str;
};
