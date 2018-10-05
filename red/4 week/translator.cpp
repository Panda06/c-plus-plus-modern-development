#include "test_runner.h"
#include <map>
#include <deque>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

class Translator {
public:
  void Add(string_view source, string_view target) {
      auto _source = GetNewView(source);
      auto _target = GetNewView(target);
      forward[_source] = _target;
      backward[_target] = _source;
  }
  string_view TranslateForward(string_view source) const {
      auto it = forward.find(source);
      if (it == forward.end()) {
          return {};
      }
      return it->second;
  }
  string_view TranslateBackward(string_view target) const {
      auto it = backward.find(target);
      if (it == backward.end()) {
          return {};
      }
      return it->second;
  }

private:
    map<string_view, string_view> forward;
    map<string_view, string_view> backward;
    deque<string> all_strings;
    
    string_view GetNewView(string_view sv) {
        for (const auto* map_ptr : {&forward, &backward}) {
      const auto it = map_ptr->find(sv);
      if (it != map_ptr->end()) {
        return it->first;
      }
    }
        all_strings.emplace_back(sv);
        return all_strings[all_strings.size() - 1];
    }
};

void TestSimple() {
  Translator translator;
  translator.Add(string("okno"), string("window"));
  translator.Add(string("stol"), string("table"));

  ASSERT_EQUAL(translator.TranslateForward("okno"), "window");
  ASSERT_EQUAL(translator.TranslateBackward("table"), "stol");
  ASSERT_EQUAL(translator.TranslateBackward("stol"), "");
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSimple);
  return 0;
}
