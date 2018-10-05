#include "database.h"

void Database::Add(const Date& date, const std::string& event) {
    if (table.count(date) == 0 || table[date].count(event) == 0) {
        table[date].insert(event);
        deque_table[date].push_back(event);
    }
}

void Database::Print(std::ostream& out) const {
    for (const auto& item : deque_table) {
        for (const auto event : item.second) {
            out << item.first << " " << event << std::endl;
        }
    }
}

int Database::RemoveIf(std::function<bool (const Date &, const std::string&)> predicate) {
    int count = 0;
    for (auto it = begin(table); it != end(table);) {
        for (auto it2 = begin(it->second); it2 != end(it->second);) {
            if(predicate(it->first, *it2)) {
                it2 = it->second.erase(it2);
                ++count;
            } else {
                ++it2;
            }
        }
        if (it->second.empty()) {
            it = table.erase(it);
        } else {
            ++it;
        }
    }
    for (auto it = begin(deque_table); it != end(deque_table);) {
        for (auto it2 = begin(it->second); it2 != end(it->second);) {
            if(predicate(it->first, *it2)) {
                it2 = it->second.erase(it2);
            } else {
                ++it2;
            }
        }
        if (it->second.empty()) {
            it = deque_table.erase(it);
        } else {
            ++it;
        }
    }
    return count;
}

std::vector<std::pair<Date, std::string>> Database::FindIf(
    std::function<bool (const Date, const std::string&)> predicate) const {
    std::vector<std::pair<Date, std::string>> s;
    for (auto it = begin(deque_table); it != end(deque_table); ++it) {
        for (auto it2 = begin(it->second); it2 != end(it->second); ++it2) {
            if(predicate(it->first, *it2)) {
                s.push_back(std::make_pair(it->first, *it2));
            }
        }
    }
    return s;
}
std::string Database::Last(const Date& date) const {
    auto it = deque_table.upper_bound(date);
    if (date == Date() || it == begin(deque_table)) {
        throw std::invalid_argument("");
    }
    --it;
    std::ostringstream last;
    last << it->first << " " << it->second.back();
    return last.str();

}
