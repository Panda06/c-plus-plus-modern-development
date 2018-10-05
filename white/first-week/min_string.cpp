#include <iostream>
#include <string>
int main() {

    std::string a, b, c;
    std::cin >> a >> b >> c;

    if(a <= b && a <= c){
        std::cout << a << '\n';
    }
    else if (b <= a && b <= c) {
        std::cout << b << '\n';
    }
    else {
        std::cout << c << '\n';
    }
    return 0;
}
