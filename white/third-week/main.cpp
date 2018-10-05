#include <algorithm>
#include <iostream>
#include <vector>
int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (auto& el: v) {
        std::cin >> el;
    }
    std::sort(begin(v), end(v), [](int x, int y){return abs(x)<abs(y);});
    for (const auto& el: v) {
        std::cout << el << ' ';
    }
    return 0;
}
