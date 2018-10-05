#include <iostream>
#include <string>
#include <map>

#define NO "NO"
#define YES "YES"

std::map<char, int> BuildCharCounters(const std::string& word) {
    std::map<char, int> result;
    for(const auto& ch : word) {
        ++result[ch];
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;
    for (size_t i = 0; i < n; i++) {
        std::string first_word, second_word;
        std::cin >> first_word >> second_word;
        auto first_map = BuildCharCounters(first_word);
        auto second_map = BuildCharCounters(second_word);
        if (first_map == second_map) {
            std::cout << YES << '\n';
        }
        else {
            std::cout << NO << '\n';
        }

    }
    return 0;
}
