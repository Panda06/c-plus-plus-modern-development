#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::vector<std::string> FindNameHistory(const std::map<int, std::string>& names,
                                         int year, int birth_year) {
    std::vector<std::string> vec_names;
    if (year < birth_year) {
        return {"No person"};
    }
    for (const auto& item: names) {
        if (item.first <= year &&
            (vec_names.empty() || item.second != vec_names.back())) {
            vec_names.push_back(item.second);
        }
    }
    return vec_names;
    }

std::string JoinName(std::vector<std::string> names) {
    if (names.empty()) {
        return "";
    }
    reverse(names.begin(), names.end());

    std::string joined_name = names[0];
    for (size_t i = 1; i < names.size(); i++) {
        joined_name += ((i == 1) ? " (" : ", ") + names[i];
    }
    if (names.size() > 1) {
        joined_name += ")";
    }
    return joined_name;
}

std::string BuildFullName(std::string& first_name, std::string& last_name) {
    if (first_name.empty() && last_name.empty()) {
        return "Incognito";
    }
    else if (first_name == "No person" || last_name == "No person") {
        return "No person";
    }
    else if (last_name.empty()) {
        return first_name + " with unknown last name";
    }
    else if (first_name.empty()) {
        return last_name + " with unknown first name";
    }
    return first_name + " " + last_name;
}

std::string FindName(const std::map<int, std::string> names, int year, int birth_year) {
    std::string name = "";
    if (year < birth_year) {
        return "No person";
    }
    for (const auto& item: names) {
        if (item.first <= year) {
            name = item.second;
        }
        else {
            return name;
        }
    }
    return name;
}


class Person {
public:
  Person(std::string first_name,std::string last_name, int year) {
      first_names[year] = first_name;
      last_names[year] = last_name;
      birth_year = year;
  }
  void ChangeFirstName(int year, const std::string& first_name) {
      if (year >= birth_year) {
          first_names[year] = first_name;
      }
  }
  void ChangeLastName(int year, const std::string& last_name) {
      if (year >= birth_year) {
          last_names[year] = last_name;
      }
  }
  std::string GetFullName(int year) const {
      std::string first_name = FindName(first_names, year, birth_year);
      std::string last_name = FindName(last_names, year, birth_year);
      return BuildFullName(first_name, last_name);
  }
  std::string GetFullNameWithHistory(int year) const {
      std::string first_name_history = JoinName(FindNameHistory(first_names, year, birth_year));
      std::string last_name_history = JoinName(FindNameHistory(last_names, year, birth_year));
      std::string full_name = BuildFullName(first_name_history, last_name_history);
      return full_name;

  }
private:
  std::map<int, std::string> first_names;
  std::map<int, std::string> last_names;
  int birth_year;
};
