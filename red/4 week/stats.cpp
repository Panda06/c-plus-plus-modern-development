#include "stats.h"
#include <iostream>
HttpRequest ParseRequest(string_view line) {
    string_view method, uri, protocol;
    size_t pos = 0;

    line.remove_prefix(min(line.find_first_not_of(' '), line.size()));
    pos = line.find(' ');
    method = line.substr(0, pos++);

    line.remove_prefix(min(pos, line.size()));
    pos = line.find(' ');
    uri = line.substr(0, pos++);

    line.remove_prefix(min(pos, line.size()));
    pos = line.find(' ');
    protocol = line.substr(0, pos);

    return { method, uri, protocol};
}

void Stats::AddMethod(string_view method) {
    if (method_stats.count(method)) {
        ++method_stats[method];
    } else {
        ++method_stats["UNKNOWN"];
    }
}

void Stats::AddUri(string_view uri) {
    if (uri_stats.count(uri)) {
        ++uri_stats[uri];
    } else {
        ++uri_stats["unknown"];
    }
}

Stats::Stats() {
    method_stats = { {"GET", 0},
                     {"PUT", 0},
                     {"POST", 0},
                     {"DELETE", 0},
                     {"UNKNOWN", 0} };
    uri_stats = { {"/", 0},
                  {"/order", 0},
                  {"/product", 0},
                  {"/basket", 0},
                  {"/help", 0},
                  {"unknown", 0} };
}
