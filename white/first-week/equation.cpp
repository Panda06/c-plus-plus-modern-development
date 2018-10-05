#include <iostream>
#include <cmath>


int main(int argc, char const *argv[]) {
    float a, b, c;
    std::cin >> a >> b >> c;
    if (a == 0 && b != 0) {
        std::cout << -c / b << '\n';
    }
    else if(a != 0 or b != 0)
    {
        auto d = b*b - 4 * a * c;
        if (d > 0){
            std::cout << (-b - sqrt(d))/(2*a) << " " << (-b + sqrt(d))/(2*a) << '\n';
        }
        else if (d == 0){
            std::cout << -b/(2*a) << '\n';
        }
        else
         std::cout << " " << '\n';
    }
    return 0;
}
