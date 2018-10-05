#include <cstdint>
#include <iostream>

int main(int argc, char const *argv[]) {
    int n, R;
    uint64_t W, D, H, sum = 0;
    std::cin >> n >> R;
    for (size_t i = 0; i < n; i++) {
        std::cin >> W >> H >> D;
        sum += W * H * D;
    }
    std::cout << sum * R << '\n';
    return 0;
}
