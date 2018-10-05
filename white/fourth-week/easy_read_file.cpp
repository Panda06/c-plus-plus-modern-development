#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[]) {
    std::ifstream input("input.txt");
    if (input.is_open()) {
        std::string s;
        while (getline(input, s)) {
            std::cout << s << '\n';
        }
    }
    return 0;
}
