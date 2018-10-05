#include <iostream>

int gdc(int a, int b){
    int tmp;
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main(int argc, char const *argv[]) {
    int a, b;
    std::cin >> a >> b;
    std::cout << gdc(a, b) << '\n';
    return 0;
}
