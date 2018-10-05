#include <algorithm>
#include <iostream>
#include <vector>

std::ostream& operator << (std::ostream& stream, std::vector<int>& v) {
    for (const auto& el : v) {
        stream << el << ' ';
    }
    return stream;
}

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = n-1; i >= 0; --i) {
        v[i] = n-i;
    }
    do {
        std::cout << v << '\n';
    }while(std::prev_permutation(begin(v), end(v)));
    return 0;
}
