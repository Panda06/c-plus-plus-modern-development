#include "test_runner.h"

#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <numeric>
#include <iterator>

using namespace std;

template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator max_element_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred) {
  auto max = find_if(first, last, pred);
  for (auto it = next(first); it != last; ++it) {
      if (pred(*it) && *max < *it) {
          max = it;
      }
  }
  return max;
}

void TestUniqueMax() {
  auto IsEven = [](int x) {
    return x % 2 == 0;
  };

  const list<int> hill{2, 4, 8, 9, 6, 4, 2};
  auto max_iterator = hill.begin();
  advance(max_iterator, 2);

  vector<int> numbers(10);
  iota(numbers.begin(), numbers.end(), 1);

  /*
    Мы не используем ASSERT_EQUAL, потому что для итераторов
    отсутствует перегрузка оператора вывода в поток ostream.
    Разыменование здесь также недопустимо, так как оно может повлечь
    неопределенное поведение, если функция max_element_if, к примеру,
    вернула итератор, указывающий на конец контейнера.
  */
  ASSERT(max_element_if(numbers.begin(), numbers.end(), IsEven) ==
    --numbers.end());
  ASSERT(max_element_if(hill.begin(), hill.end(), IsEven) ==
    max_iterator);
}

void TestSeveralMax() {
  struct IsCapitalized {
    bool operator()(const string &s) {
      return !s.empty() && isupper(s.front());
    }
  };

  const forward_list<string> text{"One", "two", "Three", "One", "Two",
    "Three", "one", "Two", "three"};
  auto max_iterator = text.begin();
  advance(max_iterator, 4);

  ASSERT(max_element_if(text.begin(), text.end(), IsCapitalized()) ==
    max_iterator);
}

void TestNoMax() {
  const vector<int> empty;
  const string str = "Non-empty string";

  auto AlwaysTrue = [](int) {
    return true;
  };
  ASSERT(max_element_if(empty.begin(), empty.end(), AlwaysTrue) ==
    empty.end());

  auto AlwaysFalse = [](char) {
    return false;
  };
  ASSERT(max_element_if(str.begin(), str.end(), AlwaysFalse) ==
    str.end());
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUniqueMax);
  RUN_TEST(tr, TestSeveralMax);
  RUN_TEST(tr, TestNoMax);
  return 0;
}
