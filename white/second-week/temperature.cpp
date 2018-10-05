#include <iostream>
#include <vector>
#include <numeric>

int main(int argc, char const *argv[]) {
    int n, sum = 0;
    std::cin >> n;
    std::vector<int> v(n);
    for(auto &e: v) {
        std::cin >> e;
        sum += 0;
    }
    int mean = sum / n;
    std::vector<int> new_v;
    for (int i = 0; i < n; ++i) {
        if(v[i] > mean) {
            new_v.push_back(i);
        }
    }
    std::cout << new_v.size() << '\n';
    for (auto &e: new_v) {
        std::cout << e << ' ';
    }
    return 0;
}
