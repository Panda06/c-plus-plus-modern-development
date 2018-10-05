#include <iostream>
#include <vector>
int main(int argc, char const *argv[]) {
    int a;
    std::vector<bool> v;
    std::cin >> a;
    while (a > 0) {
        v.push_back(a % 2)
        a /= 2;
    }
    for (int i = v.size()-1; i >= 0; --i) {
        std::cout << v[i];
    }
    return 0;
}
