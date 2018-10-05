#include "date.h"

#include <iomanip>
#include <exception>

Date::Date(const int y, const int m, const int d) {
    year = y;
    month = m;
    day = d;

}
int Date::GetYear() const {
    return year;
}
int Date::GetMonth() const {
    return month;
}
int Date::GetDay() const {
    return day;
}

bool operator < (const Date& lhs, const Date& rhs) {
    return std::vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
        std::vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator < (const Date& lhs, const std::pair<Date, std::deque<std::string>> rhs) {
    return lhs < rhs.first;
}

bool operator < (const std::pair<Date, std::deque<std::string>> lhs, const Date& rhs) {
    return lhs.first < rhs;
}
bool operator <= (const Date& lhs, const Date& rhs) {
    return std::vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <=
        std::vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator <= (const Date& lhs, const std::pair<Date, std::deque<std::string>> rhs) {
    return lhs <= rhs.first;
}

bool operator <= (const std::pair<Date, std::deque<std::string>> lhs, const Date& rhs) {
    return lhs.first <= rhs;
}

bool operator > (const Date& lhs, const Date& rhs) {
    return std::vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >
        std::vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}
bool operator >= (const Date& lhs, const Date& rhs) {
    return std::vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >=
        std::vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}
bool operator == (const Date& lhs, const Date& rhs) {
    return std::vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} ==
        std::vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}
bool operator !=(const Date& lhs, const Date& rhs) {
    return !(lhs == rhs);
}

std::ostream& operator << (std::ostream& stream, const Date& date) {
  stream << std::setw(4) << std::setfill('0') << date.GetYear() << "-"
         << std::setw(2) << std::setfill('0') << date.GetMonth() << "-"
         << std::setw(2) << std::setfill('0') << date.GetDay();
  return stream;
}

Date ParseDate(std::istream& input) {
    if (input.eof()) {
        return Date();
    }
    int day, month, year;
    std::string date;
    input >> date;
    std::stringstream is(date);
    is >> year;
    is.ignore(1);
    is >> month;
    is.ignore(1);
    is >> day;
    return Date(year, month, day);
}
