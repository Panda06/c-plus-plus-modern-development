#include <iostream>

int main(int argc, char const *argv[]) {
    double N, A, B, X, Y;
    std::cin >> N >> A >> B >> X >> Y;
    if (N > B)
    {
        N *= (100-Y) / 100;
    }
    else if (N > A) {
        N *= (100-X) / 100;
    }
    std::cout << N << '\n';
    return 0;
}
