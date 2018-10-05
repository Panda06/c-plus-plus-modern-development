#include <iostream>
#include <vector>
#include <string>

bool IsPalindrom(std::string s) {
    for (int i = 0; i < s.length() / 2; ++i) {
        if(s[i] != s[s.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

std::vector<std::string> PalindromFilter(std::vector<std::string> v, int minLength) {
    std::vector<std::string> filter;
    for (auto s: v) {
        if(IsPalindrom(s) && s.size() >= minLength) {
            filter.push_back(s);
        }
    }
    return filter;
}
