#pragma once

#include <iostream>
#include <deque>
#include <string>
#include <utility>
#include <vector>

class Date {
public:
    Date() : year(0), month(0), day(0) {}
    Date(const int y, const int m, const int d);
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
private:
    int year;
    int month;
    int day;
};

Date ParseDate(std::istream& is);
std::ostream& operator << (std::ostream& stream, const Date& date);
bool operator < (const Date& lhs, const Date& rhs);
bool operator < (const Date& lhs, const std::pair<Date, std::deque<std::string>> rhs);
bool operator < (const std::pair<Date, std::deque<std::string>> lhs, const Date& rhs);
bool operator <= (const Date& lhs, const Date& rhs);
bool operator <= (const Date& lhs, const std::pair<Date, std::deque<std::string>> rhs);
bool operator <= (const std::pair<Date, std::deque<std::string>> lhs, const Date& rhs);
bool operator >(const Date& lhs, const Date& rhs);
bool operator >=(const Date& lhs, const Date& rhs);
bool operator ==(const Date& lhs, const Date& rhs);
bool operator !=(const Date& lhs, const Date& rhs);
