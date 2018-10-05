#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
    std::string s;
    int count = 0, ind = -2;
    std::cin >> s;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == 'f') {
            ++count;
        }
        if (count == 2) {
            ind = i;
            break;
        }
    }
    if (count == 1) {
        std::cout << -1 << '\n';
    }
    else if (ind > 0 or ind == -2) {
        std::cout << ind << '\n';
    }
    return 0;
}
