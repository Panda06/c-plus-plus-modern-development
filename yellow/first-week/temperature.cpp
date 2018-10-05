#include <iostream>
#include <numeric>
#include <vector>

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    int64_t avg = 0;
    std::vector<int64_t> v(n);
    for (int64_t& el : v) {
        std::cin >> el;
        avg += el;
    }
    avg /= n;
    std::vector<int> s;
    for (size_t i = 0; i < n; i++) {
        if (v[i] > avg) {
            s.push_back(i);
        }
    }
    std::cout << s.size() << '\n';
    for (size_t i = 0; i < s.size(); i++) {
        std::cout << s[i] << ' ';
    }
    return 0;
}
