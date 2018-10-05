#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define WORRY "WORRY"
#define QUIET "QUIET"
#define COME "COME"
#define WORRY_COUNT "WORRY_COUNT"

int main() {
    int n, k;
    std::cin >> n;

    std::vector<bool> v;
    for (int i = 0; i < n; i++) {
        std::string op;
        std::cin >> op;
        if (op != WORRY_COUNT) {
            std::cin >> k;
                if (op == COME){
                       v.resize(v.size()+k, 0);
                    }
                if (op == WORRY || op == QUIET)
                     v[k] = (op == WORRY);
            }
        else{
            std::cout << std::count(v.begin(), v.end(), 1) << '\n';
            }

    }
    return 0;
}
