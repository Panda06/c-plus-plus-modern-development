#pragma once

#include "http_request.h"

#include <string_view>
#include <map>
using namespace std;

class Stats {
public:
  Stats();
  void AddMethod(string_view method);
  void AddUri(string_view uri);
  const map<string_view, int>& GetMethodStats() const {
      return method_stats;
  }
  const map<string_view, int>& GetUriStats() const {
      return uri_stats;
  }
private:
    map<string_view, int> uri_stats;
    map<string_view, int> method_stats;
};

HttpRequest ParseRequest(string_view line);
