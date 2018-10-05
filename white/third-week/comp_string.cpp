#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

std::string Lower(std::string str) {
    for (auto& c: str) {
        c = tolower(c);
    }
    return str;
}
int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::vector<std::string> v(n);
    for (auto& el: v) {
        std::cin >> el;
    }
    std::sort(begin(v), end(v), [](std::string x, std::string y){return Lower(x)<Lower(y);});
    for (const auto& el: v) {
        std::cout << el << ' ';
    }
    return 0;
}
