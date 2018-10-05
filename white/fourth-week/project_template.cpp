// Реализуйте функции и методы классов и при необходимости добавьте свои
#include <iomanip>
#include <iostream>
#include <exception>
#include <map>
#include <set>
#include <sstream>
#include <string>

#define ADD "Add"
#define DEL "Del"
#define FIND "Find"
#define PRINT "Print"

class Date {
public:
  Date(int y, int m, int d) {
      if (m < 1 || m > 12) {
          throw std::invalid_argument("Month value is invalid: " + std::to_string(m));
      }
      if (d < 1 || d > 31) {
          throw std::invalid_argument("Day value is invalid: " + std::to_string(d));
      }
      year = y;
      month = m;
      day = d;

  }
  int GetYear() const {
      return year;
  }
  int GetMonth() const {
      return month;
  }
  int GetDay() const {
      return day;
  }
private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetDay()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() < rhs.GetDay();
        }
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetYear() < rhs.GetYear();
}

std::ostream& operator << (std::ostream& stream, const Date& date) {
    stream << std::setw(4) << std::setfill('0') << date.GetYear() << "-"
           << std::setw(2) << std::setfill('0') << date.GetMonth() << "-"
           << std::setw(2) << std::setfill('0') << date.GetDay();
    return stream;
}

class Database {
public:
  void AddEvent(const Date& date, const std::string& event) {
      if (!event.empty()) {
          table[date].insert(event);
      }
  }
  bool DeleteEvent(const Date& date, const std::string& event) {
      if (table.count(date) > 0 && table.at(date).count(event) > 0) {
          table.at(date).erase(event);
          if (table.at(date).size() == 0) {
              table.erase(date);
          }
          return true;
      }
      return false;
  }
  int  DeleteDate(const Date& date) {
      if (table.count(date) > 0) {
          int n = table.at(date).size();
          table.erase(date);
          return n;
      }
      return 0;
  }

  std::set<std::string> Find(const Date& date) const {
      if (table.count(date) > 0) {
          return table.at(date);
      }
      return {};
  }

  void Print() const {
      for (const auto& tuple : table) {
          for (const auto& el : tuple.second) {
              std::cout << tuple.first << " " << el << std::endl;
          }
      }
  }
private:
    std::map<Date, std::set<std::string>> table;
};

Date ParseDate(const std::string& date) {
    int day, month, year;
    std::stringstream stream(date);
    stream >> year;
    if (stream.peek() != '-') {
        throw std::logic_error("Wrong date format: " + date);
    }
    stream.ignore(1);
    stream >> month;
    if (stream.peek() != '-') {
        throw std::logic_error("Wrong date format: " + date);
    }
    stream.ignore(1);
    stream.peek();
    if (stream.eof()) {
        throw std::logic_error("Wrong date format: " + date);
    }
    stream >> day;
    if (!stream.eof()) {
        throw std::logic_error("Wrong date format: " + date);
    }
    return Date(year, month, day);
}

int main() {
  Database db;
  try {
      std::string command;
      while (getline(std::cin, command)) {
          std::stringstream stream(command);
          std::string operation;
          stream >> operation;
          if (operation == ADD) {
              std::string event, date_str;
              stream >> date_str >> event;
              auto date = ParseDate(date_str);
              db.AddEvent(date, event);
          }
          else if (operation == PRINT) {
              db.Print();
          }
          else if (operation == FIND) {
              std::string date_str;
              stream >> date_str;
              auto date = ParseDate(date_str);
              for (const auto& el : db.Find(date)) {
                  std::cout << el << std::endl;
              }
          }
          else if (operation == DEL) {
              std::string date_str;
              stream >> date_str;
              auto date = ParseDate(date_str);
              if (stream.eof()) {
                  std::cout << "Deleted " << db.DeleteDate(date) << " events\n";
              }
              else {
                  std::string event;
                  stream >> event;
                  if (db.DeleteEvent(date, event)) {
                      std::cout << "Deleted successfully\n";
                  }
                  else {
                      std::cout << "Event not found\n";
                  }
              }
          }
          else if (operation.empty()) {
              continue;
          }
          else {
              throw std::logic_error("Unknown command: " + command);
          }
      }
  }catch(std::exception& e) {
      std::cout << e.what() << '\n';
  }

  return 0;
}
