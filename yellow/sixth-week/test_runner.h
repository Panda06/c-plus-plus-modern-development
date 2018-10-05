#pragma once

#include <iostream>
#include <exception>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

template <class K, class V>
std::ostream& operator << (std::ostream& os, const std::pair<K, V>& m) {
    os << m.first << " " << m.second;
    return os;
}

template <class T>
std::ostream& operator << (std::ostream& os, const std::set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
std::ostream& operator << (std::ostream& os, const std::map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv;
  }
  return os << "}";
}

template <class E>
std::ostream& operator << (std::ostream& os, const std::vector<E>& v) {
    os << "{";
    bool not_first = false;
    for (const auto el : v) {
        if(not_first) {
            os << ", ";
        }
        not_first = true;
        os << el;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u,
    const std::string& hint)
{
  if (t != u) {
    std::ostringstream os;
    os << "Assertion failed: " << t << " != " << u
       << " hint: " << hint;
    throw std::runtime_error(os.str());
  }
}

void Assert(bool b, const std::string& hint);

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const std::string& test_name) {
    try {
      func();
      std::cerr << test_name << " OK" << std::endl;
  } catch (std::runtime_error& e) {
      ++fail_count;
      std::cerr << test_name << " fail: " << e.what() << std::endl;
    }
  }

  ~TestRunner();

private:
  int fail_count = 0;
};
