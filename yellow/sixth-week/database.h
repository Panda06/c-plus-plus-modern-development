#pragma once

#include "date.h"

#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class Database {
public:
    void Add(const Date& date, const std::string& event);
    void Print(std::ostream& out) const;

    int RemoveIf(std::function<bool (const Date &, const std::string&)> predicate);

    std::vector<std::pair<Date, std::string>> FindIf(
            std::function<bool (const Date, const std::string&)> predicate) const;

    std::string Last(const Date& date) const;
    std::map<Date, std::set<std::string>> getInternalStorage() {
        return table;
    }
private:
    std::map<Date, std::set<std::string>> table;
    std::map<Date, std::deque<std::string>> deque_table;

};
