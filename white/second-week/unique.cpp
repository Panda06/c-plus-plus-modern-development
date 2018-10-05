#include <iostream>
#include <set>
#include <string>

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::set<std::string> unique;
    for (size_t i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        unique.insert(s);
    }
    std::cout << unique.size() << '\n';
    return 0;
}
