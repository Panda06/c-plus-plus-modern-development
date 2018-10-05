#include <iostream>

int Factorial(int n) {
    if (n < 2) {
        return 1;
    }
    return n*Factorial(n-1);
}

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    std::cout << Factorial(n) << '\n';
    return 0;
}
